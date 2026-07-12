# CrealityKE

An open-source ESP32 library for communicating with Creality printers over WebSocket.

> **Current Version:** v0.7.0

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
- Raw command transmission
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

    printer.send(R"({"method":"get","params":{"nozzleTemp":1}})");

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

## Raw Command

```cpp
printer.send(json);
```

Sends a raw JSON command to the printer through the active WebSocket connection.

Returns `true` if the command was accepted for transmission.

---

## Temperature

- nozzleTemp()
- bedTemp()
- targetNozzleTemp()
- targetBedTemp()

---

## Print

- progress()
- currentLayer()
- totalLayers()
- printTime()
- remainingTime()
- state()

---

## Cooling

- fan()
- modelFan()
- caseFan()
- auxiliaryFan()

---

## Material

- materialDetected()
- materialStatus()

---

## Device Information

- hostname()
- model()
- version()
- connected()
- maxNozzleTemp()
- maxBedTemp()

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
User
   │
   ▼
CrealityKE
   │
   ▼
Commands
   │
   ▼
Connection
   │
   ▼
WebSocket
   │
   ▼
Printer
```

All outgoing commands pass through a single communication layer.

---

## Roadmap

Planned features:

- Command builder
- Light control
- Print control
- Motion control
- Temperature control
- G-code commands
- Multi-printer support

---

## License

MIT License

---

## Author

Mehrab Khavari