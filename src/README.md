# CrealityKE

An open-source ESP32 library for communicating with Creality printers over WebSocket.

> **Current Version:** v0.6.0

---

## Features

- WebSocket communication
- Automatic reconnection
- JSON message parsing
- Temperature monitoring
- Print status monitoring
- Cooling system monitoring
- Filament sensor monitoring
- Device information
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

# Quick Start

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

    Serial.println(printer.hostname());
    Serial.println(printer.model());

    Serial.print("Nozzle : ");
    Serial.println(printer.nozzleTemp());

    Serial.print("Bed : ");
    Serial.println(printer.bedTemp());

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

Current printing layer.

```cpp
printer.totalLayers();
```

Total printing layers.

```cpp
printer.printTime();
```

Elapsed print time.

```cpp
printer.remainingTime();
```

Remaining print time.

```cpp
printer.state();
```

Printer state.

---

## Cooling

```cpp
printer.fan();
```

Main fan state.

```cpp
printer.modelFan();
```

Model fan speed.

```cpp
printer.caseFan();
```

Case fan speed.

```cpp
printer.auxiliaryFan();
```

Auxiliary fan speed.

---

## Material

```cpp
printer.materialDetected();
```

Returns whether the filament sensor is enabled.

```cpp
printer.materialStatus();
```

Returns whether filament is present.

---

## Device Information

```cpp
printer.hostname();
```

Printer hostname.

```cpp
printer.model();
```

Printer model.

```cpp
printer.version();
```

Firmware information.

```cpp
printer.connected();
```

Printer connection state.

```cpp
printer.maxNozzleTemp();
```

Maximum supported nozzle temperature.

```cpp
printer.maxBedTemp();
```

Maximum supported bed temperature.

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
- hostname
- model
- modelVersion
- connect
- maxNozzleTemp
- maxBedTemp

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

Each module has a single responsibility, making the library easy to extend and maintain.

---

## Roadmap

Planned features:

- Printer control
- G-code commands
- Motion status
- AI detection
- Camera status
- Timelapse
- Multi-printer support

---

## License

MIT License

---

## Author

Mehrab Khavari