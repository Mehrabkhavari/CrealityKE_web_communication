# CrealityKE

An open-source ESP32 library for communicating with Creality printers over WebSocket.

---

## Current Version

**v0.2.0**

---

## Project Goals

The purpose of this project is to provide a lightweight and modular SDK for ESP32 that can communicate directly with Creality printers without requiring OctoPrint, Moonraker or other middleware.

The library is designed with scalability in mind and will eventually support:

- Printer monitoring
- Remote control
- Multi-printer management
- ESP32 dashboards
- Home Assistant integration
- IoT applications

---

## Current Features

✔ Modular project architecture

✔ WebSocket communication

✔ Automatic reconnect

✔ Dedicated communication layer

✔ Dedicated parser layer

✔ Shared printer status model

✔ Object-oriented design

---

## Architecture

```
                User
                  │
                  ▼
             CrealityKE
          ┌──────────────┐
          ▼              ▼
    Connection       Parser
                          │
                          ▼
                    PrinterStatus
```

Each module has a single responsibility.

This design makes the library easier to maintain, extend and debug.

---

## Project Structure

```
src/

Connection
Handles WebSocket communication.

Parser
Processes incoming printer messages.

Status
Stores the current printer status.

Commands
Will contain all printer commands.

CrealityKE
Main public interface.
```

---

## Development Status

### v0.1.0

- Initial library structure
- WebSocket connection
- Automatic reconnect

---

### v0.2.0

- Added PrinterStatus model
- Connected Parser to shared status object
- Connection now forwards messages to Parser
- Improved internal architecture

---

## Planned Features

- JSON parser
- Nozzle temperature
- Bed temperature
- Target temperatures
- Print progress
- Current layer
- Total layers
- Remaining print time
- Printer state
- Fan status
- Pause / Resume
- Stop print
- Temperature control
- Multi-printer support

---

## Hardware

Currently tested with:

- ESP32
- Creality Ender-3 V3 KE

---

## License

MIT License

---

## Author

Mehrab Khavari