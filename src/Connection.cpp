#include "Connection.h"
#include "Parser.h"

using namespace websockets;

// Constructor
Connection::Connection()
{
}

// Send raw JSON to printer
bool Connection::sendRaw(const String& json)
{
    // Check connection state
    if (!_connected)
        return false;

    // Send WebSocket message
    return _client.send(json);
}

// Send SET request
bool Connection::sendSet(const String& parameter, const String& value)
{
    if (!_connected)
        return false;

    String json = "{\"method\":\"set\",\"params\":{\"";
    json += parameter;
    json += "\":";
    json += value;
    json += "}}";

    return _client.send(json);
}

// Send GET request
bool Connection::sendGet(const String& parameter)
{
    if (!_connected)
        return false;

    String json = "{\"method\":\"get\",\"params\":{\"";
    json += parameter;
    json += "\":0}}";

    return _client.send(json);
}

// Return connection state
bool Connection::connected() const
{
    return _connected;
}