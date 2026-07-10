# CrealityKE

An open-source ESP32 library for communicating with Creality printers over WebSocket.

> **Current Version:** v0.5.0

---

## Features

- WebSocket communication
- Automatic reconnection
- JSON message parsing
- Nozzle temperature
- Bed temperature
- Target temperatures
- Print progress
- Layer information
- Print time
- Printer state
- Cooling system monitoring
- Filament sensor monitoring
- Lightweight architecture
- Optimized for ESP32

---

## Supported Printers

Currently tested with:

- Creality Ender-3 V3 KE

Support for additional Creality printers will be added in future releases.

---

## Dependencies

- ArduinoJson
- ArduinoWebsockets
- WiFi (ESP32)

---

## Installation

Copy the library into your Arduino libraries folder.

```
Documents/
└── Arduino/
    └── libraries/
        └── CrealityKE/
```

---

## Quick Start

```cpp
#include <WiFi.h>
#include <CrealityKE.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

CrealityKE printer;

void setup()
{
    Serial.begin(115200);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }

    printer.begin("192.168.0.156");
}

void loop()
{
    printer.loop();

    Serial.print("Nozzle: ");
    Serial.println(printer.nozzleTemp());

    Serial.print("Bed: ");
    Serial.println(printer.bedTemp());

    Serial.print("Progress: ");
    Serial.print(printer.progress());
    Serial.println("%");

    delay(1000);
}
```

---

# Available API

## Connection

```cpp
printer.begin(ip);
```

```cpp
printer.loop();
```

---

## Temperature

```cpp
printer.nozzleTemp();
```

Current nozzle temperature.

```cpp
printer.bedTemp();
```

Current bed temperature.

```cpp
printer.targetNozzleTemp();
```

Target nozzle temperature.

```cpp
printer.targetBedTemp();
```

Target bed temperature.

---

## Print

```cpp
printer.progress();
```

Print progress.

```cpp
printer.currentLayer();
```

Current layer.

```cpp
printer.totalLayers();
```

Total layers.

```cpp
printer.printTime();
```

Elapsed print time (seconds).

```cpp
printer.remainingTime();
```

Remaining print time (seconds).

```cpp
printer.state();
```

Printer state.

---

## Cooling

```cpp
printer.fan();
```

Main fan status.

```cpp
printer.modelFan();
```

Model fan speed (%).

```cpp
printer.caseFan();
```

Case fan speed (%).

```cpp
printer.auxiliaryFan();
```

Auxiliary fan speed (%).

---

## Material Sensor

```cpp
printer.materialDetected();
```

Returns whether the filament sensor is enabled.

```cpp
printer.materialStatus();
```

Returns whether filament is detected.

---

## Supported Messages

The parser currently supports:

- nozzleTemp
- bedTemp0
- targetNozzleTemp
- targetBedTemp0
- printProgress
- layer
- TotalLayer
- printJobTime
- printLeftTime
- state
- fan
- modelFanPct
- caseFanPct
- auxiliaryFanPct
- materialDetect
- materialStatus

---

## Project Structure

```
CrealityKE
│
├── src
│   ├── Commands
│   ├── Connection
│   ├── Parser
│   ├── Status
│   └── CrealityKE
│
├── examples
│
└── library.properties
```

---

## Architecture

```
Printer
    │
    ▼
WebSocket
    │
    ▼
Connection
    │
    ▼
Parser
    │
    ▼
PrinterStatus
    │
    ▼
Public API
```

Each module has a single responsibility, making the library easy to maintain and extend.

---

## Roadmap

Planned features:

- Printer information
- Motion information
- AI detection status
- Camera status
- Remote printer control
- G-code commands
- Multi-printer support

---

## License

MIT License

---

## Author

Mehrab Khavari