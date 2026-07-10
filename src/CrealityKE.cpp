#include "CrealityKE.h"

CrealityKE::CrealityKE()
{

}

void CrealityKE::begin(
    const char* ip,
    uint16_t port)
{
    connection.begin(ip, &parser, port);
}

void CrealityKE::loop()
{
    connection.loop();
}