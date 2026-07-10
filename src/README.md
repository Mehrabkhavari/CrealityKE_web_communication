\# CrealityKE



An ESP32 library for communicating with Creality Ender series printers over WebSocket.



> \*\*Project Status:\*\* Under Development 🚧



\---



\## Overview



CrealityKE is an open-source ESP32 library designed to communicate directly with Creality printers through their built-in WebSocket interface.



The goal of this project is to provide a simple and clean API for monitoring and controlling Creality printers without relying on external software such as OctoPrint or Moonraker.



Ultimately, this library aims to become the core of custom projects such as:



\- External printer status displays

\- Print farm dashboards

\- IoT monitoring systems

\- Remote printer control panels

\- Home Assistant integrations

\- ESP32-based accessories



\---



\## Current Progress



\### Version 0.0.1



Current implementation includes:



\- Project architecture

\- Modular library structure

\- WebSocket connection

\- Automatic reconnect

\- Receiving raw printer messages

\- Separation of responsibilities between modules



The JSON parser and printer status management are currently under development.



\---



\## Project Structure



```

CrealityKE

│

├── Connection

│   Handles WebSocket communication

│

├── Parser

│   Parses incoming JSON messages

│

├── Status

│   Stores printer state

│

├── Commands

│   Sends commands to the printer

│

└── CrealityKE

&#x20;   Main user interface

```



Each module has a single responsibility, making the library easy to maintain and extend.



\---



\## Planned Features



\- Read nozzle temperature

\- Read bed temperature

\- Print progress

\- Current layer

\- Total layers

\- Remaining print time

\- Current print speed

\- Fan status

\- File name

\- Printer state

\- Pause / Resume

\- Stop print

\- Temperature control

\- Multi-printer support



\---



\## Example



```cpp

\#include <WiFi.h>

\#include <CrealityKE.h>



CrealityKE printer;



void setup()

{

&#x20;   WiFi.begin(ssid, password);



&#x20;   while (WiFi.status() != WL\_CONNECTED);



&#x20;   printer.begin("192.168.0.156");

}



void loop()

{

&#x20;   printer.loop();

}

```



\---



\## Hardware



Current development target:



\- ESP32

\- Creality Ender 3 V3 KE



Additional Creality printers will be supported in future releases.



\---



\## License



MIT License



\---



\## Author



\*\*Mehrab Khavari\*\*



GitHub:

https://github.com/MehrabKhavari

