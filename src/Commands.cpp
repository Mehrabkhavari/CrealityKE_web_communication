#include "Commands.h"
#include "Connection.h"

// Constructor
Commands::Commands()
{
}

// Attach connection object
void Commands::begin(Connection* connection)
{
    _connection = connection;
}

// Send raw JSON command
bool Commands::sendRaw(const String& json)
{
    if (_connection == nullptr)
        return false;

    return _connection->sendRaw(json);
}

// Send GET request
bool Commands::sendGet(const String& parameter)
{
    if (_connection == nullptr)
        return false;

    return _connection->sendGet(parameter);
}

// Send SET request
bool Commands::sendSet(const String& parameter, const String& value)
{
    if (_connection == nullptr)
        return false;

    return _connection->sendSet(parameter, value);
}

// Set nozzle temperature
bool Commands::setNozzleTemp(int temperature)
{
    return sendSet("nozzleTemp", String(temperature));
}

// Set bed temperature
bool Commands::setBedTemp(int temperature)
{
    return sendSet("bedTemp0", String(temperature));
}

// Home X
bool Commands::homeX()
{
    return sendRaw("{\"method\":\"set\",\"params\":{\"home\":\"X\"}}");
}

// Home Y
bool Commands::homeY()
{
    return sendRaw("{\"method\":\"set\",\"params\":{\"home\":\"Y\"}}");
}

// Home Z
bool Commands::homeZ()
{
    return sendRaw("{\"method\":\"set\",\"params\":{\"home\":\"Z\"}}");
}

// Home XY
bool Commands::homeXY()
{
    return sendRaw("{\"method\":\"set\",\"params\":{\"home\":\"XY\"}}");
}

// Home XZ
bool Commands::homeXZ()
{
    return sendRaw("{\"method\":\"set\",\"params\":{\"home\":\"XZ\"}}");
}

// Home YZ
bool Commands::homeYZ()
{
    return sendRaw("{\"method\":\"set\",\"params\":{\"home\":\"YZ\"}}");
}

// Home XYZ
bool Commands::homeXYZ()
{
    return sendRaw("{\"method\":\"set\",\"params\":{\"home\":\"XYZ\"}}");
}

// Pause print
bool Commands::pause()
{
    return sendSet("pause", "1");
}

// Resume print
bool Commands::resume()
{
    return sendSet("pause", "0");
}

// Stop print
bool Commands::stop()
{
    return sendSet("stop", "1");
}