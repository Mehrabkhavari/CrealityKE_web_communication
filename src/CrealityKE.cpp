#include "CrealityKE.h"

// Initialize library
CrealityKE::CrealityKE()
{
    // Attach parser to shared status
    parser.begin(&status);

    // Attach connection to command manager
    commands.begin(&connection);
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
    // Keep WebSocket alive
    connection.loop();
}

// Send raw JSON command
bool CrealityKE::send(const String& json)
{
    return commands.send(json);
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

// Return current printing layer
int CrealityKE::currentLayer() const
{
    return status.currentLayer();
}

// Return total printing layers
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

// Return main fan state
bool CrealityKE::fan() const
{
    return status.fan();
}

// Return model fan speed
int CrealityKE::modelFan() const
{
    return status.modelFan();
}

// Return case fan speed
int CrealityKE::caseFan() const
{
    return status.caseFan();
}

// Return auxiliary fan speed
int CrealityKE::auxiliaryFan() const
{
    return status.auxiliaryFan();
}

// Return filament sensor enabled state
bool CrealityKE::materialDetected() const
{
    return status.materialDetected();
}

// Return filament presence
bool CrealityKE::materialStatus() const
{
    return status.materialStatus();
}

// Return printer hostname
const String& CrealityKE::hostname() const
{
    return status.hostname();
}

// Return printer model
const String& CrealityKE::model() const
{
    return status.model();
}

// Return firmware information
const String& CrealityKE::version() const
{
    return status.version();
}

// Return printer connection state
bool CrealityKE::connected() const
{
    return status.connected();
}

// Return maximum nozzle temperature
int CrealityKE::maxNozzleTemp() const
{
    return status.maxNozzleTemp();
}

// Return maximum bed temperature
int CrealityKE::maxBedTemp() const
{
    return status.maxBedTemp();
}