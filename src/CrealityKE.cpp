#include "CrealityKE.h"

// Initialize library
CrealityKE::CrealityKE()
{
    // Attach parser to shared status
    parser.begin(&status);
}

// Connect to printer
void CrealityKE::begin(const char* ip, uint16_t port)
{
    // Start WebSocket connection
    connection.begin(ip, &parser, port);
}

// Process WebSocket events
void CrealityKE::loop()
{
    // Keep connection alive
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

// Return print progress
int CrealityKE::progress() const
{
    return status.progress();
}

// Return current layer
int CrealityKE::currentLayer() const
{
    return status.currentLayer();
}

// Return total layers
int CrealityKE::totalLayers() const
{
    return status.totalLayers();
}

// Return elapsed print time
int CrealityKE::printTime() const
{
    return status.printTime();
}

// Return remaining print time
int CrealityKE::remainingTime() const
{
    return status.remainingTime();
}

// Return printer state
int CrealityKE::state() const
{
    return status.state();
}