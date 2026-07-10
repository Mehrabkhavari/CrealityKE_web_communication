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