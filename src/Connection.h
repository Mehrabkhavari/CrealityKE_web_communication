#ifndef CONNECTION_H
#define CONNECTION_H

#include <Arduino.h>
#include <ArduinoWebsockets.h>

class Parser;

// Handles WebSocket communication
class Connection
{
    friend class Commands;

public:

    Connection();

    void begin(const char* ip, Parser* parser, uint16_t port = 9999);

    void loop();

    bool connected() const;

    // Send raw JSON
    bool sendRaw(const String& json);

    // Send {"method":"set","params":{...}}
    bool sendSet(const String& parameter, const String& value);

    // Send {"method":"get","params":{...}}
    bool sendGet(const String& parameter);

private:

    websockets::WebsocketsClient _client;

    Parser* _parser = nullptr;

    String _host;

    uint16_t _port = 9999;

    unsigned long _lastHeartbeat = 0;

    bool _connected = false;
};

#endif