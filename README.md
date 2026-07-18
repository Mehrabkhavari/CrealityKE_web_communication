# CrealityKE\_web\_communication

A lightweight Arduino library for controlling and monitoring Creality K1/KE series 3D printers over the local network using the native Creality WebSocket protocol.



Designed for ESP32, ESP8266 and other Arduino-compatible boards.



\---



\## Features



\### Monitor printer status



\- Nozzle temperature

\- Bed temperature

\- Target temperatures

\- Print progress

\- Current layer

\- Total layers

\- Elapsed print time

\- Remaining print time

\- Printer state

\- Fan status

\- Model fan speed

\- Case fan speed

\- Auxiliary fan speed

\- Filament sensor

\- Filament presence

\- Printer hostname

\- Printer model

\- Firmware version

\- Connection state

\- Maximum nozzle temperature

\- Maximum bed temperature



\### Control printer



\- Set nozzle temperature

\- Set bed temperature

\- Pause print

\- Resume print

\- Stop print

\- Home X

\- Home Y

\- Home Z

\- Home XY

\- Home XZ

\- Home YZ

\- Home XYZ



\### Low level API



\- Send raw WebSocket JSON

\- Send GET requests

\- Send SET requests



\---



\## Supported Boards



\- ESP32

\- ESP8266

\- Arduino boards with WebSocket support



\---



\## Supported Printers



Tested on



\- Creality Ender-3 V3 KE



Expected to work with other Creality printers using the same WebSocket protocol.



\---



\## Installation



\### Arduino IDE



Download the latest release from GitHub.



Or install manually into



```

Documents/Arduino/libraries/

```



\---



\## Quick Start



```cpp

\#include <CrealityKE.h>



CrealityKE printer;



void setup()

{

&#x20;   Serial.begin(115200);



&#x20;   printer.begin("192.168.1.100");

}



void loop()

{

&#x20;   printer.loop();



&#x20;   Serial.println(printer.nozzleTemp());

}

```



\---



\## Example



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



\---



\## Documentation



Documentation is available in the `/docs` directory.



Examples are available in the `/examples` directory.



\---



\## Version



Current stable release



```

v1.0.0

```



\---



\## Roadmap



Planned features



\- Print file management

\- Motion control

\- Fan control

\- LED control

\- Camera support

\- Timelapse control

\- Full printer information

\- Automatic printer discovery



\---



\## License



MIT License



\---



\## Author



Mehrab Khavari



GitHub



https://github.com/MehrabKhavari



YouTube



https://www.youtube.com/@mehrabtronic

