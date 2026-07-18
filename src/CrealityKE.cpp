#include "CrealityKE.h"

// Initialize library
CrealityKE::CrealityKE()
{
    parser.begin(&status);
    commands.begin(&connection);
}

// Connect to printer
void CrealityKE::begin(const char* ip, uint16_t port)
{
    connection.begin(ip, &parser, port);
}

// Process WebSocket events
void CrealityKE::loop()
{
    connection.loop();
}

// Raw communication
bool CrealityKE::sendRaw(const String& json)
{
    return commands.sendRaw(json);
}

bool CrealityKE::sendGet(const String& parameter)
{
    return commands.sendGet(parameter);
}

bool CrealityKE::sendSet(const String& parameter, const String& value)
{
    return commands.sendSet(parameter, value);
}

// Temperature control
bool CrealityKE::setNozzleTemp(int temperature)
{
    return commands.setNozzleTemp(temperature);
}

bool CrealityKE::setBedTemp(int temperature)
{
    return commands.setBedTemp(temperature);
}

// Homing
bool CrealityKE::homeX()
{
    return commands.homeX();
}

bool CrealityKE::homeY()
{
    return commands.homeY();
}

bool CrealityKE::homeZ()
{
    return commands.homeZ();
}

bool CrealityKE::homeXY()
{
    return commands.homeXY();
}

bool CrealityKE::homeXZ()
{
    return commands.homeXZ();
}

bool CrealityKE::homeYZ()
{
    return commands.homeYZ();
}

bool CrealityKE::homeXYZ()
{
    return commands.homeXYZ();
}

// Print control
bool CrealityKE::pause()
{
    return commands.pause();
}

bool CrealityKE::resume()
{
    return commands.resume();
}

bool CrealityKE::stop()
{
    return commands.stop();
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