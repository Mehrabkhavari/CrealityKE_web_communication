#ifndef CREALITYKE_H
#define CREALITYKE_H

#include <Arduino.h>
#include <WebSocketsClient.h>

class CrealityKE
{
public:

    CrealityKE();

    bool begin(const char* ip, uint16_t port = 9999);

    void loop();

    bool connected();

private:

    WebSocketsClient _ws;

    bool _connected = false;

    static void webSocketEvent(
        WStype_t type,
        uint8_t * payload,
        size_t length);
};

#endif