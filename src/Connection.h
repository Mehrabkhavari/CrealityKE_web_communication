#ifndef CONNECTION_H
#define CONNECTION_H

#include <Arduino.h>
#include <WebSocketsClient.h>

class Connection
{
public:

    Connection();

    void begin(const char* ip,uint16_t port=9999);

    void loop();

private:

    WebSocketsClient ws;

    static void webSocketEvent(
        WStype_t type,
        uint8_t* payload,
        size_t length);

};

#endif