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

// Return current layer
int PrinterStatus::currentLayer() const
{
    return _currentLayer;
}

// Return total layers
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