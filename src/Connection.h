#ifndef CONNECTION_H
#define CONNECTION_H

#include <Arduino.h>
#include <WebSocketsClient.h>

class Parser;

class Connection
{
public:

    Connection();

    void begin(
        const char* ip,
        Parser* parser,
        uint16_t port = 9999);

    void loop();

private:

    WebSocketsClient ws;

    Parser* _parser;

    static Connection* instance;

    static void webSocketEvent(
        WStype_t type,
        uint8_t* payload,
        size_t length);

    void onMessage(
        WStype_t type,
        uint8_t* payload,
        size_t length);

};

#endif