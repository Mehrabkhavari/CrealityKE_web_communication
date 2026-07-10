#include "Connection.h"
#include "Parser.h"

Connection* Connection::instance = nullptr;

Connection::Connection()
{
    instance = this;
}

void Connection::begin(
    const char* ip,
    Parser* parser,
    uint16_t port)
{
    _parser = parser;

    ws.begin(ip, port, "/");

    ws.onEvent(webSocketEvent);

    ws.setReconnectInterval(5000);
}

void Connection::loop()
{
    ws.loop();
}

void Connection::webSocketEvent(
    WStype_t type,
    uint8_t* payload,
    size_t length)
{
    if(instance)
    {
        instance->onMessage(type, payload, length);
    }
}

void Connection::onMessage(
    WStype_t type,
    uint8_t* payload,
    size_t length)
{
    switch(type)
    {

        case WStype_CONNECTED:

            Serial.println("Printer Connected");

            break;

        case WStype_DISCONNECTED:

            Serial.println("Printer Disconnected");

            break;

        case WStype_TEXT:

            if(_parser)
            {
                _parser->parse(String((char*)payload));
            }

            break;

        default:

            break;

    }
}