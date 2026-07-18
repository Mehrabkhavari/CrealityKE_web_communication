\# Examples



This document contains real communication examples captured from a Creality KE printer.



\---



\# Example 1 - Get Printer Parameters



Client



```json

{

&#x20;   "method":"get",

&#x20;   "params":{

&#x20;       "ReqPrinterPara":1

&#x20;   }

}

```



Printer



```json

{

&#x20;   "curPosition":"X:0.00 Y:0.00 Z:0.00",

&#x20;   "autohome":"X:1 Y:1 Z:1",

&#x20;   "curZOffset":"3.216"

}

```



\---



\# Example 2 - Set Nozzle Temperature



Client



```json

{

&#x20;   "method":"set",

&#x20;   "params":{

&#x20;       "nozzleTempControl":220

&#x20;   }

}

```



Printer



```json

{

&#x20;   "targetNozzleTemp":220

}

```



Followed by



```json

{

&#x20;   "nozzleTemp":"30.22"

}

```



```json

{

&#x20;   "nozzleTemp":"80.15"

}

```



```json

{

&#x20;   "nozzleTemp":"220.00"

}

```



\---



\# Example 3 - Set Bed Temperature



Client



```json

{

&#x20;   "method":"set",

&#x20;   "params":{

&#x20;       "bedTempControl":{

&#x20;           "num":0,

&#x20;           "val":50

&#x20;       }

&#x20;   }

}

```



Printer



```json

{

&#x20;   "targetBedTemp0":50

}

```



Then



```json

{

&#x20;   "bedTemp0":"29.70"

}

```



↓



```json

{

&#x20;   "bedTemp0":"49.99"

}

```



\---



\# Example 4 - Auto Home



Client



```json

{

&#x20;   "method":"set",

&#x20;   "params":{

&#x20;       "autohome":"X Y"

&#x20;   }

}

```



Printer



```json

{

&#x20;   "deviceState":7

}

```



```json

{

&#x20;   "autohome":"X:1 Y:0 Z:0"

}

```



```json

{

&#x20;   "curPosition":"X:337.44 Y:0.00 Z:0.00"

}

```



```json

{

&#x20;   "autohome":"X:1 Y:1 Z:0"

}

```



```json

{

&#x20;   "deviceState":0

}

```



\---



\# Example 5 - Start of Print



Observed packets immediately after a print begins.



```json

{

&#x20;   "deviceState":1

}

```



```json

{

&#x20;   "state":1

}

```



```json

{

&#x20;   "state":5

}

```



```json

{

&#x20;   "TotalLayer":10

}

```



```json

{

&#x20;   "printLeftTime":1031,

&#x20;   "realTimeSpeed":"33.33"

}

```



\---



\# Example 6 - Printing



Typical packets during printing.



```json

{

&#x20;   "printJobTime":193,

&#x20;   "printLeftTime":837,

&#x20;   "realTimeFlow":"0.39",

&#x20;   "realTimeSpeed":"300",

&#x20;   "usedMaterialLength":53

}

```



```json

{

&#x20;   "curPosition":"X:74.97 Y:90.89 Z:0.43"

}

```



```json

{

&#x20;   "nozzleTemp":"219.73"

}

```



\---



\# Example 7 - Pause Print



Client



```json

{

&#x20;   "method":"set",

&#x20;   "params":{

&#x20;       "pause":1

&#x20;   }

}

```



Printer



```json

{

&#x20;   "state":0

}

```



Observed behavior



\- Print motion stops.

\- Toolhead moves to the parking position.

\- Nozzle target temperature is removed.

\- Nozzle begins cooling.



\---



\# Example 8 - Resume Print



Client



```json

{

&#x20;   "method":"set",

&#x20;   "params":{

&#x20;       "pause":0

&#x20;   }

}

```



Printer



```json

{

&#x20;   "targetNozzleTemp":220

}

```



Observed behavior



\- Heater restarts.

\- Nozzle reheats.

\- Printing automatically continues after reaching target temperature.



\---



\# Example 9 - Heartbeat



Printer



```json

{

&#x20;   "ModeCode":"heart\_beat",

&#x20;   "msg":"2026-07-12T17:24:30.001Z"

}

```



Client



```

ok

```



Heartbeat packets are sent approximately every few seconds to verify that the connection is still alive.



\---



\# Example 10 - Print History



The printer can return lifetime statistics together with previous print jobs.



Example fields



```json

{

&#x20;   "totalJob":50,

&#x20;   "totalUsageTime":306907,

&#x20;   "totalUsageMaterial":625645,

&#x20;   "historyList":\[ ... ]

}

```



Each history entry contains information such as:



\- filename

\- print duration

\- material usage

\- print result

\- thumbnail

\- MD5 hash

\- start method

\- creation time



See `history.md` for the complete structure.



\---



\# Incremental Updates



The printer sends only values that have changed.



Example



Packet 1



```json

{

&#x20;   "nozzleTemp":"220.05"

}

```



Packet 2



```json

{

&#x20;   "bedTemp0":"50.02"

}

```



Packet 3



```json

{

&#x20;   "printProgress":36

}

```



A client should merge these packets into a single internal printer state instead of replacing the previous one.

