# 🖨️ CrealityKE

<p align="center">

<img src="https://img.shields.io/badge/Arduino-Library-00979D?style=for-the-badge&logo=arduino">
<img src="https://img.shields.io/badge/ESP32-Supported-E7352C?style=for-the-badge&logo=espressif">
<img src="https://img.shields.io/badge/Version-1.0.0-blue?style=for-the-badge">
<img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge">

</p>


## 🚀 Bring your Creality 3D Printer into the IoT world

**CrealityKE** is an open-source Arduino library that allows microcontrollers such as **ESP32** and **ESP8266** to communicate with Creality 3D printers through the native local network WebSocket protocol.

With this library, your printer is no longer a standalone machine.  
You can monitor its status, control printing operations, and build your own smart devices around your 3D printer. 🤖✨


<p align="center">

🖨️ Printer  
⬇️  
📡 WebSocket Communication  
⬇️  
🔌 ESP32 / Arduino  
⬇️  
🌐 Your Smart Project

</p>


## 💡 What can you build?

With CrealityKE you can create:

🔹 Smart printer status displays  
🔹 Temperature monitoring systems  
🔹 Custom control panels  
🔹 IoT printer dashboards  
🔹 Workshop automation tools  
🔹 Notification systems  
🔹 Custom hardware controllers


## ⚡ Features

### 📊 Real-time Monitoring

Monitor your printer directly from your microcontroller:

🌡️ Nozzle temperature  
🔥 Bed temperature  
📈 Print progress  
🧱 Current layer information  
⏱️ Print time tracking  
🌀 Fan status  
🧵 Filament detection  
🖥️ Printer information  


### 🎮 Printer Control

Control your printer using simple Arduino functions:

```cpp
printer.setNozzleTemp(220);

printer.setBedTemp(60);

printer.pause();

printer.resume();

printer.homeXYZ();
```


No complicated JSON commands are required for common operations.  
The library handles communication with the printer automatically. ⚙️


## 🧠 Designed for Makers

CrealityKE was created for developers, makers, and engineers who want to connect the physical world with software.

From a small OLED temperature display to a complete smart factory system, the possibilities are open. 🚀


## 🔧 Supported Hardware

✅ ESP32  
✅ ESP8266  
✅ Arduino-compatible boards


## 🖨️ Tested Printer

Currently tested with:

⭐ Creality Ender-3 V3 KE

Other Creality printers using the same communication protocol may also work.


## 📦 Installation

Download the latest release and add it to your Arduino libraries folder:

```
Documents/Arduino/libraries/
```

Then include:

```cpp
#include <CrealityKE.h>
```


## 🌟 Project Status

Current version:

```
v1.0.0
```

Stable release 🎉

This version provides the foundation for building custom hardware and IoT solutions around Creality printers.


## 🛣️ Future Roadmap

Future versions may include:

🚧 Advanced motion control  
🚧 File management  
🚧 Camera integration  
🚧 Printer discovery  
🚧 More printer models support  


## 👨‍💻 Created by

**Mehrab Khavari**

Building tools that connect creativity, electronics and manufacturing. ⚡


## Features

### Monitor printer status

- Nozzle temperature
- Bed temperature
- Target temperatures
- Print progress
- Current layer
- Total layers
- Elapsed print time
- Remaining print time
- Printer state
- Fan status
- Model fan speed
- Case fan speed
- Auxiliary fan speed
- Filament sensor
- Filament presence
- Printer hostname
- Printer model
- Firmware version
- Connection state
- Maximum nozzle temperature
- Maximum bed temperature

### Control printer

- Set nozzle temperature
- Set bed temperature
- Pause print
- Resume print
- Stop print
- Home X
- Home Y
- Home Z
- Home XY
- Home XZ
- Home YZ
- Home XYZ

### Low level API

- Send raw WebSocket JSON
- Send GET requests
- Send SET requests

---

## Supported Boards

- ESP32
- ESP8266
- Arduino boards with WebSocket support

---

## Supported Printers

Tested on

- Creality Ender-3 V3 KE

Expected to work with other Creality printers using the same WebSocket protocol.

---

## Installation

### Arduino IDE

Download the latest release from GitHub.

Or install manually into

```
Documents/Arduino/libraries/
```

---

## Quick Start

```cpp
#include <CrealityKE.h>

CrealityKE printer;

void setup()
{
    Serial.begin(115200);

    printer.begin("192.168.1.100");
}

void loop()
{
    printer.loop();

    Serial.println(printer.nozzleTemp());
}
```

---

## Example

Set nozzle temperature

```cpp
printer.setNozzleTemp(220);
```

Pause printing

```cpp
printer.pause();
```

Resume printing

```cpp
printer.resume();
```

Home all axes

```cpp
printer.homeXYZ();
```

---

## Documentation

Documentation is available in the `/docs` directory.

Examples are available in the `/examples` directory.

---

## Version

Current stable release

```
v1.0.0
```

---

## Roadmap

Planned features

- Print file management
- Motion control
- Fan control
- LED control
- Camera support
- Timelapse control
- Full printer information
- Automatic printer discovery

---

## License

MIT License

---

## Author

Mehrab Khavari

GitHub

https://github.com/MehrabKhavari

YouTube

https://www.youtube.com/@mehrabtronic
