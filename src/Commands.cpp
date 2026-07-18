#include "Commands.h"
#include "Connection.h"

#include <ArduinoJson.h>

// Constructor
Commands::Commands()
{
}

// Attach connection object
void Commands::begin(Connection* connection)
{
    _connection = connection;
}

// Set nozzle temperature
bool Commands::setNozzleTemp(uint16_t temperature)
{
    // Check connection
    if (_connection == nullptr)
        return false;

    StaticJsonDocument<64> params;

    params["nozzleTempControl"] = temperature;

    return _connection->sendSet(params);
}

// Set bed temperature
bool Commands::setBedTemp(uint16_t temperature)
{
    // Check connection
    if (_connection == nullptr)
        return false;

    StaticJsonDocument<96> params;

    JsonObject bed = params.createNestedObject("bedTempControl");

    bed["num"] = 0;
    bed["val"] = temperature;

    return _connection->sendSet(params);
}