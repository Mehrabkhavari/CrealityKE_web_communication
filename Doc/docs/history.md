# Print History

This document describes the print history information returned by the printer.

---

# Overview

The printer maintains an internal database of previous print jobs.

It can be retrieved through the WebSocket interface.

Example response:

```json
{
    "totalJob":50,
    "totalUsageTime":306907,
    "totalUsageMaterial":625645,
    "historyList":[ ... ]
}
```

---

# totalJob

Total number of print jobs stored by the printer.

Example

```json
{
    "totalJob":50
}
```

Type

```
integer
```

---

# totalUsageTime

Total accumulated printing time.

Example

```json
{
    "totalUsageTime":306907
}
```

Type

```
seconds
```

---

# totalUsageMaterial

Total consumed filament.

Example

```json
{
    "totalUsageMaterial":625645
}
```

Type

```
millimeters
```

---

# historyList

Array containing print history records.

Example

```json
{
    "historyList":[ ... ]
}
```

Each element represents one print job.

---

# History Record

Example

```json
{
    "id":1783875989,
    "filename":"/usr/data/printer_data/gcodes/test.gcode",
    "size":2148481,
    "ctime":1783875983,
    "starttime":1783875989,
    "startway":11,
    "usagetime":731,
    "usagematerial":675.59,
    "printfinish":0,
    "thumbnail":"/usr/data/creality/userdata/history/thumbnail/1783875989.png",
    "filemd5":"ede7acc589befc43f7a6227db466fda7"
}
```

---

# Fields

## id

Unique print job identifier.

Type

```
integer
```

---

## filename

Absolute path of the G-code file stored on the printer.

Example

```
/usr/data/printer_data/gcodes/test.gcode
```

---

## size

File size.

Type

```
bytes
```

---

## ctime

Creation time of the G-code file.

Type

```
Unix Timestamp
```

---

## starttime

Time when printing started.

Type

```
Unix Timestamp
```

---

## startway

Indicates how the print was started.

Observed values

| Value | Meaning | Status |
|------:|---------|--------|
| 1 | Started locally from printer | Observed |
| 9 | Started remotely | Observed |
| 11 | Started from Creality Cloud / App | Observed |

> The exact meaning of these values has not yet been officially confirmed.

---

## usagetime

Actual print duration.

Type

```
seconds
```

---

## usagematerial

Consumed filament.

Type

```
millimeters
```

---

## printfinish

Print result.

Observed values

| Value | Meaning |
|------:|----------|
| 0 | Cancelled / Failed |
| 1 | Successfully completed |

Verified by comparing completed prints with manually cancelled prints.

---

## thumbnail

Path to the generated preview image.

Example

```
/usr/data/creality/userdata/history/thumbnail/1783875989.png
```

---

## filemd5

MD5 checksum of the G-code file.

Useful for verifying whether two history entries refer to the same file.

---

# Notes

- The printer stores multiple history records for the same G-code file.
- Each print receives a unique `id`.
- History includes both successful and cancelled prints.
- The history database survives printer reboots.
- The printer reports lifetime statistics (`totalJob`, `totalUsageTime`, `totalUsageMaterial`) together with the history list.