#include "Status.h"

// Return current nozzle temperature
float PrinterStatus::nozzleTemp() const
{
    return _nozzleTemp;
}

// Return current bed temperature
float PrinterStatus::bedTemp() const
{
    return _bedTemp;
}

// Return target nozzle temperature
int PrinterStatus::targetNozzleTemp() const
{
    return _targetNozzleTemp;
}

// Return target bed temperature
int PrinterStatus::targetBedTemp() const
{
    return _targetBedTemp;
}

// Return print progress
int PrinterStatus::progress() const
{
    return _progress;
}

// Return current printing layer
int PrinterStatus::currentLayer() const
{
    return _currentLayer;
}

// Return total printing layers
int PrinterStatus::totalLayers() const
{
    return _totalLayers;
}

// Return elapsed print time
int PrinterStatus::printTime() const
{
    return _printTime;
}

// Return remaining print time
int PrinterStatus::remainingTime() const
{
    return _remainingTime;
}

// Return printer state
int PrinterStatus::state() const
{
    return _state;
}

// Return main fan state
bool PrinterStatus::fan() const
{
    return _fan;
}

// Return model fan speed
int PrinterStatus::modelFan() const
{
    return _modelFan;
}

// Return case fan speed
int PrinterStatus::caseFan() const
{
    return _caseFan;
}

// Return auxiliary fan speed
int PrinterStatus::auxiliaryFan() const
{
    return _auxiliaryFan;
}

// Return filament sensor enabled state
bool PrinterStatus::materialDetected() const
{
    return _materialDetected;
}

// Return filament presence
bool PrinterStatus::materialStatus() const
{
    return _materialStatus;
}

// Return printer hostname
const String& PrinterStatus::hostname() const
{
    return _hostname;
}

// Return printer model
const String& PrinterStatus::model() const
{
    return _model;
}

// Return firmware version
const String& PrinterStatus::version() const
{
    return _version;
}

// Return printer connection state
bool PrinterStatus::connected() const
{
    return _connected;
}

// Return maximum nozzle temperature
int PrinterStatus::maxNozzleTemp() const
{
    return _maxNozzleTemp;
}

// Return maximum bed temperature
int PrinterStatus::maxBedTemp() const
{
    return _maxBedTemp;
}