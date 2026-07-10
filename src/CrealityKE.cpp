#include "CrealityKE.h"

// Constructor
CrealityKE::CrealityKE()
{
    // Connect parser to shared status object
    parser.begin(&status);
}

// Connect to printer
void CrealityKE::begin(const char* ip, uint16_t port)
{
    connection.begin(ip, &parser, port);
}

// Handle WebSocket events
void CrealityKE::loop()
{
    connection.loop();
}

// Return current nozzle temperature
float CrealityKE::nozzleTemp() const
{
    return status.nozzleTemp();
}

// Return current bed temperature
float CrealityKE::bedTemp() const
{
    return status.bedTemp();
}

// Return target nozzle temperature
int CrealityKE::targetNozzleTemp() const
{
    return status.targetNozzleTemp();
}

// Return target bed temperature
int CrealityKE::targetBedTemp() const
{
    return status.targetBedTemp();
}