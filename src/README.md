# CrealityKE

An open-source ESP32 library for communicating with Creality printers over WebSocket.

> **Current Version:** v0.3.0

---

## Features

- WebSocket communication
- Automatic reconnection
- JSON message parsing
- Nozzle temperature monitoring
- Bed temperature monitoring
- Target nozzle temperature
- Target bed temperature
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

Clone this repository into your Arduino libraries folder or install it manually.

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

    Serial.println(printer.nozzleTemp());
    Serial.println(printer.bedTemp());

    delay(1000);
}
```

---

## Available API

### Connection

```cpp
printer.begin(ipAddress);
```

```cpp
printer.loop();
```

---

### Temperature

```cpp
printer.nozzleTemp();
```

Returns the current nozzle temperature.

```cpp
printer.bedTemp();
```

Returns the current bed temperature.

```cpp
printer.targetNozzleTemp();
```

Returns the target nozzle temperature.

```cpp
printer.targetBedTemp();
```

Returns the target bed temperature.

---

## Project Structure

```
CrealityKE
│
├── src
│   ├── Connection
│   ├── Parser
│   ├── Status
│   ├── Commands
│   └── CrealityKE
│
├── examples
│
└── library.properties
```

---

## Architecture

```
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

- Print progress
- Current layer
- Total layers
- Remaining print time
- Printer state
- Fan status
- Motion information
- Printer information
- Remote printer control
- Multi-printer support

---

## License

MIT License

---

## Author

Mehrab Khavari