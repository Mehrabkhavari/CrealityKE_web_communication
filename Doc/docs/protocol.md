# WebSocket Protocol

This document describes the communication protocol used by Creality KE printers.

---

# Transport

Protocol

```
WebSocket
```

Data Format

```
JSON
```

Encoding

```
UTF-8
```

Communication

```
Full Duplex
```

The printer and client can send messages independently at any time.

---

# Client Messages

Commands sent to the printer always follow this structure:

```json
{
    "method":"set",
    "params":{
        ...
    }
}
```

Example

```json
{
    "method":"set",
    "params":{
        "pause":1
    }
}
```

---

# Query Messages

Some information can be requested manually using the `get` method.

Example

```json
{
    "method":"get",
    "params":{
        "ReqPrinterPara":1
    }
}
```

Typical response

```json
{
    "curPosition":"X:0.00 Y:0.00 Z:0.00",
    "autohome":"X:1 Y:1 Z:1",
    "curZOffset":"3.216"
}
```

---

# Printer Messages

The printer continuously sends JSON objects whenever one or more values change.

Example

```json
{
    "nozzleTemp":"220.10"
}
```

or

```json
{
    "bedTemp0":"50.00",
    "printJobTime":514,
    "curPosition":"X:101.91 Y:110.89 Z:0.87"
}
```

A message may contain:

- One field
- Several fields
- Dozens of fields

Only changed values are transmitted.

---

# Heartbeat

The printer periodically sends heartbeat packets.

Example

```json
{
    "ModeCode":"heart_beat",
    "msg":"2026-07-12T17:24:30.001Z"
}
```

The client should reply with:

```
ok
```

Example

```
ok
```

Heartbeat packets are used to keep the WebSocket connection alive.

---

# Update Strategy

The printer does **not** send a complete status packet.

Instead it sends only parameters whose values have changed.

For example:

```
220.01°C

↓

220.02°C

↓

220.03°C
```

Only the changed temperature field is transmitted.

If no parameter changes, no status packet is sent (except heartbeat messages).

---

# Typical Communication Flow

```
Client connects

↓

Heartbeat

↓

Client replies "ok"

↓

Status packets arrive continuously

↓

Client sends command

↓

Printer acknowledges by changing status values

↓

Printing continues
```

---

# Message Ordering

Messages are asynchronous.

For example, after sending:

```json
{
    "method":"set",
    "params":{
        "pause":1
    }
}
```

The printer may send:

```json
{
    "state":0
}
```

followed by

```json
{
    "curPosition":"..."
}
```

followed by

```json
{
    "nozzleTemp":"..."
}
```

There is no guarantee that related values arrive in the same packet.

Applications should merge incoming JSON objects into a single printer state.

---

# Recommended Client Design

Maintain an internal printer state object.

Whenever a new JSON message arrives:

1. Parse the JSON.
2. Update only the fields present.
3. Leave all other fields unchanged.
4. Notify the user interface of the updated values.

This approach accurately reflects how the printer communicates over the WebSocket connection.