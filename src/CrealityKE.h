#ifndef CREALITYKE_H
#define CREALITYKE_H

#include "Connection.h"
#include "Parser.h"
#include "Status.h"
#include "Commands.h"

class CrealityKE
{
public:

    CrealityKE();

    void begin(
        const char* ip,
        uint16_t port = 9999);

    void loop();

private:

    Connection connection;

    Parser parser;

    PrinterStatus status;

    Commands commands;

};

#endif