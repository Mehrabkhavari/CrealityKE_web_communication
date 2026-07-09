#include "CrealityKE.h"

CrealityKE::CrealityKE()
{

}

bool CrealityKE::begin(const char* ip, uint16_t port)
{
    _ws.begin(ip, port, "/");

    _ws.onEvent(webSocketEvent);

    _ws.setReconnectInterval(5000);

    return true;
}

void CrealityKE::loop()
{
    _ws.loop();
}

bool CrealityKE::connected()
{
    return _connected;
}

void CrealityKE::webSocketEvent(
    WStype_t type,
    uint8_t * payload,
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