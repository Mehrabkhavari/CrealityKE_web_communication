#include "Connection.h"
#include "Parser.h"

using namespace websockets;

// Constructor
Connection::Connection()
{
}

// Send raw JSON to printer
bool Connection::send(const String& json)
{
    // Check connection state
    if (!_connected)
        return false;

    // Send WebSocket message
    return _client.send(json);
}

// Return connection state
bool Connection::connected() const
{
    return _connected;
}