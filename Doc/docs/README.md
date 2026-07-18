# Creality KE WebSocket API

An unofficial documentation project for the Creality KE WebSocket interface.

This repository documents the printer protocol by observing real communication between Creality Print / Creality Cloud and the printer.

The goal is to provide an open reference for developers building custom software, dashboards, mobile applications, and embedded devices.

---

## Features

- WebSocket protocol documentation
- Printer command reference
- Status parameter reference
- Device state documentation
- Print history structure
- Object metadata
- Real packet examples
- Reverse engineered behavior

---

## Tested Printer

- Creality Ender 3 V3 KE

The protocol is expected to work on other Creality printers using the same firmware, although this has not yet been verified.

---

## Repository Structure

```
docs/
│
├── README.md
├── protocol.md
├── commands.md
├── printer_status.md
├── device_states.md
├── history.md
├── print_objects.md
```

---

## Communication

Transport

```
WebSocket
```

Encoding

```
UTF-8
```

Data

```
JSON
```

The printer continuously pushes status updates.

Commands are sent from the client using JSON packets.

---

## Example Command

```json
{
    "method":"set",
    "params":{
        "pause":1
    }
}
```

---

## Example Status Packet

```json
{
    "nozzleTemp":"220.15",
    "bedTemp0":"50.02",
    "printProgress":36,
    "curPosition":"X:101.32 Y:112.43 Z:0.84"
}
```

---

## Current Documentation

### Protocol

- WebSocket communication
- Heartbeat packets
- Update strategy
- Client design

### Commands

- Nozzle temperature
- Bed temperature
- Auto Home
- Pause
- Resume
- Stop

### Status

- Temperatures
- Position
- Feedrate
- Flow
- Fans
- Progress
- Print statistics

### Device States

Known `deviceState` values

Known `state` values

### Print History

- Lifetime statistics
- History database
- Print result codes

### Objects

- Object metadata
- Bed polygons
- Object centers

---

## Project Status

Current status

```
Reverse Engineering
```

Most commonly used commands have already been identified.

Additional commands will be added as they are discovered.

---

## Disclaimer

This project is **not affiliated with Creality**.

All information has been obtained through protocol observation and testing.

Some undocumented values may change with future firmware versions.

---

## Contributing

Pull requests, issue reports, and additional protocol discoveries are welcome.

If you discover a new command or parameter, please include:

- Firmware version
- Printer model
- JSON packet
- Expected behavior
- Observed behavior

This helps keep the documentation accurate and up to date.