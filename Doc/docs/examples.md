# Version 0.9.0

Version 0.9.0 introduces the first high-level printer control API.

## New Features

### Temperature Control

```cpp
printer.setNozzleTemp(220);
printer.setBedTemp(60);
```

### Homing

```cpp
printer.homeX();
printer.homeY();
printer.homeZ();

printer.homeXY();
printer.homeXZ();
printer.homeYZ();

printer.homeXYZ();
```

### Print Control

```cpp
printer.pause();
printer.resume();
printer.stop();
```

## Improvements

- Added high-level command API.
- Raw JSON communication remains available through `sendRaw()`.
- All printer control commands now use dedicated functions instead of manually creating JSON.
- API structure is now ready for future movement and file management features.

## Compatible Firmware

Creality OS (WebSocket API)

## Breaking Changes

- `send()` renamed to `sendRaw()`
- Added `sendGet()` and `sendSet()`