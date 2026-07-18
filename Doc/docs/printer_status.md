# Printer Status Parameters

This document describes all status parameters observed from the printer over the WebSocket connection.

The printer sends these values asynchronously whenever they change.

---

# Temperatures

## nozzleTemp

Current nozzle temperature.

### Example

```json
{
    "nozzleTemp": "219.85"
}
```

Type

```
float (°C)
```

---

## targetNozzleTemp

Requested nozzle temperature.

Example

```json
{
    "targetNozzleTemp": 220
}
```

Type

```
integer (°C)
```

---

## bedTemp0

Current bed temperature.

Example

```json
{
    "bedTemp0": "49.98"
}
```

Type

```
float (°C)
```

---

## targetBedTemp0

Requested bed temperature.

Example

```json
{
    "targetBedTemp0": 50
}
```

Type

```
integer (°C)
```

---

# Print Progress

## printProgress

Current print progress.

Example

```json
{
    "printProgress": 36
}
```

Type

```
integer (%)
```

---

## printJobTime

Elapsed printing time.

Example

```json
{
    "printJobTime": 514
}
```

Type

```
seconds
```

---

## printLeftTime

Estimated remaining print time.

Example

```json
{
    "printLeftTime": 838
}
```

Type

```
seconds
```

---

## TotalLayer

Total number of layers in the loaded G-code.

Example

```json
{
    "TotalLayer": 10
}
```

Type

```
integer
```

---

## usedMaterialLength

Consumed filament length.

Example

```json
{
    "usedMaterialLength": 457
}
```

Type

```
millimeters
```

---

# Motion

## curPosition

Current toolhead position.

Example

```json
{
    "curPosition": "X:143.08 Y:124.14 Z:0.01"
}
```

Type

```
string
```

---

## curFeedratePct

Feedrate override.

Example

```json
{
    "curFeedratePct": 100
}
```

Type

```
percent
```

---

## realTimeSpeed

Current printing speed.

Example

```json
{
    "realTimeSpeed": "300.000000"
}
```

Type

```
mm/s
```

---

## realTimeFlow

Current extrusion flow.

Example

```json
{
    "realTimeFlow": "2.320000"
}
```

Type

```
float
```

---

# Fans

## fan

Part cooling fan state.

Example

```json
{
    "fan": 1
}
```

Values

| Value | Meaning |
|------|-----------|
|0|Off|
|1|On|

---

## modelFanPct

Model cooling fan percentage.

Example

```json
{
    "modelFanPct": 80
}
```

Type

```
percent
```

---

# Printer State

## deviceState

Overall printer state.

Example

```json
{
    "deviceState": 1
}
```

See:

```
device_states.md
```

---

## state

Current print state.

Example

```json
{
    "state": 5
}
```

See:

```
device_states.md
```

---

# Calibration

## curZOffset

Current Z Offset.

Example

```json
{
    "curZOffset":"3.216"
}
```

Type

```
millimeters
```

---

## autohome

Current homing status.

Example

```json
{
    "autohome":"X:1 Y:1 Z:0"
}
```

Values

```
0 = Not Homed

1 = Homed
```

---

# Print Objects

## current_object

Current object being printed.

Example

```json
{
    "current_object":""
}
```

---

## objects

Objects detected inside the loaded G-code.

Example

```json
{
    "objects":[...]
}
```

Each object includes

- Name
- Center
- Polygon

---

## excluded_objects

Objects excluded from printing.

Example

```json
{
    "excluded_objects":[]
}
```

---

# Motion Configuration

## accelerationLimits

Current acceleration limit.

Example

```json
{
    "accelerationLimits":5000
}
```

---

## accelToDecelLimits

Acceleration to deceleration limit.

Example

```json
{
    "accelToDecelLimits":5000
}
```

---

## pressureAdvance

Pressure Advance value.

Example

```json
{
    "pressureAdvance":"0.044000"
}
```

---

# Notes

The printer does **not** send all parameters in every message.

Instead, only parameters that have changed since the previous update are transmitted.