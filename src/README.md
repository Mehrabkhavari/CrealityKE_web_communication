# CrealityKE

An open-source ESP32 library for communicating with Creality printers over WebSocket.

> **Current Version:** v0.4.0

---

## Features

- WebSocket communication
- Automatic reconnection
- JSON message parsing
- Nozzle temperature monitoring
- Bed temperature monitoring
- Target nozzle temperature
- Target bed temperature
- Print progress
- Current layer
- Total layers
- Elapsed print time
- Remaining print time
- Printer state
- Lightweight architecture
- Optimized for ESP32

---

## Supported Printers

Currently tested with:

- Creality Ender-3 V3 KE

Support for more Creality printers will be added in future releases.

---

## Dependencies

- ArduinoJson
- ArduinoWebsockets
- WiFi (ESP32)

---

## Installation

Clone this repository into your Arduino libraries folder.

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
    Serial.println(printer.progress());

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

Print progress percentage.

```cpp
printer.currentLayer();
```

Current printing layer.

```cpp
printer.totalLayers();
```

Total number of layers.

```cpp
printer.printTime();
```

Elapsed print time in seconds.

```cpp
printer.remainingTime();
```

Estimated remaining print time in seconds.

```cpp
printer.state();
```

Current printer state.

---

## Supported Messages

The parser currently supports the following printer messages:

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

- Fan status
- Printer information
- Motion information
- Material sensor
- Remote printer control
- G-code commands
- Multi-printer support

---

## License

MIT License

---

## Author

Mehrab Khavari