# Print Objects

This document describes the object metadata transmitted by the printer during a print.

These parameters allow software to identify individual objects contained in a G-code file.

---

# Overview

When a print starts, the printer may transmit information about every printable object found in the G-code.

Example

```json
{
    "current_object":"",
    "excluded_objects":"[ ]",
    "objects":"[
        {
            \"name\":\"CHATGPT_IMAGE_JUL_3_2026_08_11_39_PM.STL_ID_0_COPY_0\",
            \"center\":[110,110],
            \"polygon\":[
                [35,66.3412],
                [185,66.3412],
                [185,153.659],
                [35,153.659],
                [35,66.3412]
            ]
        }
    ]"
}
```

Unlike most status values, these fields are JSON strings containing serialized arrays.

Applications should parse these strings into JSON objects.

---

# current_object

The object currently being printed.

Example

```json
{
    "current_object":""
}
```

Type

```
string
```

Observed values

- Empty string
- Object name (expected)

During testing the value remained empty.

---

# excluded_objects

List of skipped objects.

Example

```json
{
    "excluded_objects":"[ ]"
}
```

Type

```
JSON Array (encoded as string)
```

Normally empty unless object cancellation is supported.

---

# objects

Contains every printable object detected in the G-code.

Example

```json
{
    "objects":"[...]"
}
```

Type

```
JSON Array (encoded as string)
```

---

# Object Structure

Each object contains:

```json
{
    "name":"ObjectName",
    "center":[110,110],
    "polygon":[
        [35,66],
        [185,66],
        [185,153],
        [35,153]
    ]
}
```

---

## name

Unique object name.

Example

```
CHATGPT_IMAGE_JUL_3_2026_08_11_39_PM.STL_ID_0_COPY_0
```

Usually generated from the original STL filename.

---

## center

Center point of the object on the print bed.

Example

```json
[110,110]
```

Type

```
[X,Y]
```

Units

```
millimeters
```

---

## polygon

Polygon describing the occupied area on the build plate.

Example

```json
[
    [35,66],
    [185,66],
    [185,153],
    [35,153]
]
```

Type

```
Array of XY coordinates
```

The polygon forms a closed boundary around the object.

---

# Possible Applications

Object metadata enables advanced printer interfaces such as:

- Object selection
- Per-object cancellation
- Object highlighting
- Bed visualization
- Collision checking
- Print progress by object

---

# Parsing

The printer transmits `objects` and `excluded_objects` as strings.

Example

```json
{
    "objects":"[ ... ]"
}
```

Applications must parse the string a second time.

Example (pseudo-code)

```cpp
JsonDocument doc;

deserializeJson(doc, websocketMessage);

String objectsString = doc["objects"];

JsonDocument objectsDoc;

deserializeJson(objectsDoc, objectsString);
```

---

# Notes

- Object metadata is typically sent once near the beginning of a print.
- It is not included in every status update.
- Current firmware sends an empty `current_object` during normal printing, although future firmware versions may populate this field.
- The polygon coordinates correspond to the object's footprint on the print bed.