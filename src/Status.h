#ifndef STATUS_H
#define STATUS_H

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

    // Print progress (0-100)
    int progress() const;

    // Current printing layer
    int currentLayer() const;

    // Total print layers
    int totalLayers() const;

    // Elapsed print time (seconds)
    int printTime() const;

    // Remaining print time (seconds)
    int remainingTime() const;

    // Printer state
    int state() const;

    // Main fan status
    bool fan() const;

    // Model fan speed (0-100)
    int modelFan() const;

    // Case fan speed (0-100)
    int caseFan() const;

    // Auxiliary fan speed (0-100)
    int auxiliaryFan() const;

    // Filament sensor enabled
    bool materialDetected() const;

    // Filament available
    bool materialStatus() const;

private:

    // Allow parser to update values
    friend class Parser;

    // Temperature data
    float _nozzleTemp = 0.0f;
    float _bedTemp = 0.0f;

    // Target temperatures
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

    // Cooling system
    bool _fan = false;
    int _modelFan = 0;
    int _caseFan = 0;
    int _auxiliaryFan = 0;

    // Material sensor
    bool _materialDetected = false;
    bool _materialStatus = false;
};

#endif