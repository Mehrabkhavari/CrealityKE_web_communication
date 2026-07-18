# Commands

This document describes all commands that can be sent to Creality KE printers through the WebSocket interface.

---

## Message Format

All commands use the following JSON structure:

```json
{
  "method": "set",
  "params": {
    ...
  }
}
```

---

## Set Nozzle Temperature

Sets the target nozzle temperature.

### Command

```json
{
  "method": "set",
  "params": {
    "nozzleTempControl": 220
  }
}
```

---

## Set Bed Temperature

Sets the target heated bed temperature.

### Command

```json
{
  "method": "set",
  "params": {
    "bedTempControl": {
      "num": 0,
      "val": 60
    }
  }
}
```

---

## Auto Home

Homes one or more printer axes.

### Home X

```json
{
  "method": "set",
  "params": {
    "autohome": "X"
  }
}
```

### Home Y

```json
{
  "method": "set",
  "params": {
    "autohome": "Y"
  }
}
```

### Home Z

```json
{
  "method": "set",
  "params": {
    "autohome": "Z"
  }
}
```

### Home X Y

```json
{
  "method": "set",
  "params": {
    "autohome": "X Y"
  }
}
```

### Home X Y Z

```json
{
  "method": "set",
  "params": {
    "autohome": "X Y Z"
  }
}
```

---

## Pause Print

```json
{
  "method": "set",
  "params": {
    "pause": 1
  }
}
```

---

## Resume Print

```json
{
  "method": "set",
  "params": {
    "pause": 0
  }
}
```

---

## Cancel Print

```json
{
  "method": "set",
  "params": {
    "stop": 1
  }
}
```
