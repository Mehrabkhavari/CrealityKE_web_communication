#ifndef CONNECTION_H
#define CONNECTION_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ArduinoWebsockets.h>

class Parser;

// Handles WebSocket communication
class Connection
{
public:

    Connection();

    void begin(const char* ip, Parser* parser, uint16_t port = 9999);

    void loop();

    bool connected() const;

    // Send raw JSON document
    bool sendRaw(JsonDocument& doc);

    // Send {"method":"set","params":{...}}
    bool sendSet(JsonDocument& params);

    // Send {"method":"get","params":{...}}
    bool sendGet(JsonDocument& params);

private:

    websockets::WebsocketsClient _client;

    Parser* _parser = nullptr;

    String _host;

    uint16_t _port = 9999;

    unsigned long _lastHeartbeat = 0;

    bool _connected = false;
};

#endif