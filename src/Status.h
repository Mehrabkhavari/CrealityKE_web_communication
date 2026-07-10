#ifndef STATUS_H
#define STATUS_H

class Parser;

// Stores current printer data
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

private:

    // Allow parser to update values
    friend class Parser;

    float _nozzleTemp = 0.0f;
    float _bedTemp = 0.0f;

    int _targetNozzleTemp = 0;
    int _targetBedTemp = 0;
};

#endif