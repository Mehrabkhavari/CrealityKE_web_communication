# Device States

This document describes the observed values of `deviceState` and `state`.

> **Note**
>
> These values are based on real-world testing of a Creality KE printer.
> Some values are inferred from printer behavior and may be updated as additional states are discovered.

---

# deviceState

Represents the printer's overall operating state.

| Value | Meaning | Status |
|------:|---------|--------|
| 0 | Idle / Ready | ✅ Verified |
| 1 | Printing | ✅ Verified |
| 7 | Homing | ✅ Verified |

---

## deviceState = 0

The printer is idle and ready for commands.

Observed when:

- Printer finishes homing
- Printer is waiting
- Print has been cancelled
- Print has finished

Example

```json
{
    "deviceState": 0
}
```

---

## deviceState = 1

Printer is actively printing.

Example

```json
{
    "deviceState": 1
}
```

---

## deviceState = 7

Printer is performing Auto Home.

Observed immediately after sending:

```json
{
    "method":"set",
    "params":{
        "autohome":"X Y"
    }
}
```

Example response

```json
{
    "deviceState":7
}
```

When homing completes:

```json
{
    "deviceState":0
}
```

---

# state

Represents the current print workflow state.

Unlike `deviceState`, this value changes frequently during printing.

---

## state = 0

Observed during:

- Pause sequence
- Resume sequence

Example

```json
{
    "state":0
}
```

Status

✅ Verified

---

## state = 1

Observed immediately after a print is started.

Example

```json
{
    "state":1
}
```

Status

✅ Verified

---

## state = 5

Observed a fraction of a second after `state = 1`.

This appears to indicate that the printer has entered the active printing phase.

Example

```json
{
    "state":5
}
```

Status

✅ Verified

---

# State Transition Example

Starting a print

```
deviceState = 0

↓

state = 1

↓

state = 5

↓

deviceState = 1
```

---

Pausing a print

```
deviceState = 1

↓

state = 0

↓

Printer parks

↓

Nozzle cools

↓

Waiting
```

---

Resuming a print

```
Pause = 0

↓

Target nozzle temperature restored

↓

Printer reheats

↓

Printing resumes
```

---

Stopping a print

```
Printing

↓

Stop command

↓

deviceState = 0

↓

History updated
```

---

# Unknown Values

The following values have **not** yet been observed.

```
deviceState = 2
deviceState = 3
deviceState = 4
deviceState = 5
deviceState = 6

state = 2
state = 3
state = 4
```

These will be documented as they are discovered.