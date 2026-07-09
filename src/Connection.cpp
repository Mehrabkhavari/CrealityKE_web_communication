#include "Connection.h"

Connection::Connection()
{

}

void Connection::begin(const char* ip,uint16_t port)
{
    ws.begin(ip,port,"/");

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
    switch(type)
    {

        case WStype_CONNECTED:

            Serial.println("Printer Connected");

            break;

        case WStype_DISCONNECTED:

            Serial.println("Printer Disconnected");

            break;

        case WStype_TEXT:

            Serial.println((char*)payload);

            break;

        default:

            break;

    }
}