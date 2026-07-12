#ifndef CONNECTION_H
#define CONNECTION_H

#include <Arduino.h>
#include <ArduinoWebsockets.h>

class Parser;
class Commands;

// Handles WebSocket communication
class Connection
{
    friend class Commands;

public:

    Connection();

    void begin(const char* ip, Parser* parser, uint16_t port = 9999);

    void loop();

    bool connected() const;

private:

    // Send raw JSON over WebSocket
    bool send(const String& json);

    websockets::WebsocketsClient _client;

    Parser* _parser = nullptr;

    String _host;

    uint16_t _port = 9999;

    unsigned long _lastHeartbeat = 0;

    bool _connected = false;
};

#endif