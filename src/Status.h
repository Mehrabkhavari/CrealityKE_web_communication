#ifndef STATUS_H
#define STATUS_H

#include <Arduino.h>

class Parser;

// Stores the latest printer status
class PrinterStatus
{
public:

    PrinterStatus() = default;

    // Current nozzle temperature
    float nozzleTemp() const;

    // Current bed temperature
    float bedTemp() const;

    // Target nozzle temperature
    int targetNozzleTemp() const;

    // Target bed temperature
    int targetBedTemp() const;

    // Print progress
    int progress() const;

    // Current layer
    int currentLayer() const;

    // Total layers
    int totalLayers() const;

    // Elapsed print time
    int printTime() const;

    // Remaining print time
    int remainingTime() const;

    // Printer state
    int state() const;

    // Main fan state
    bool fan() const;

    // Model fan speed
    int modelFan() const;

    // Case fan speed
    int caseFan() const;

    // Auxiliary fan speed
    int auxiliaryFan() const;

    // Filament sensor enabled
    bool materialDetected() const;

    // Filament detected
    bool materialStatus() const;

    // Printer hostname
    const String& hostname() const;

    // Printer model
    const String& model() const;

    // Firmware version
    const String& version() const;

    // Printer connection state
    bool connected() const;

    // Maximum nozzle temperature
    int maxNozzleTemp() const;

    // Maximum bed temperature
    int maxBedTemp() const;

private:

    friend class Parser;

    // Temperature
    float _nozzleTemp = 0.0f;
    float _bedTemp = 0.0f;

    // Target temperature
    int _targetNozzleTemp = 0;
    int _targetBedTemp = 0;

    // Print information
    int _progress = 0;
    int _currentLayer = 0;
    int _totalLayers = 0;

    // Print timing
    int _printTime = 0;
    int _remainingTime = 0;

    // Printer state
    int _state = 0;

    // Cooling
    bool _fan = false;
    int _modelFan = 0;
    int _caseFan = 0;
    int _auxiliaryFan = 0;

    // Material sensor
    bool _materialDetected = false;
    bool _materialStatus = false;

    // Device information
    String _hostname;
    String _model;
    String _version;

    bool _connected = false;

    int _maxNozzleTemp = 0;
    int _maxBedTemp = 0;
};

#endif