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
bool Commands::send(const String& json)
{
    // Check connection
    if (_connection == nullptr)
        return false;

    // Send command over WebSocket
    return _connection->send(json);
}