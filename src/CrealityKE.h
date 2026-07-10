#ifndef CREALITYKE_H
#define CREALITYKE_H

#include <Arduino.h>

#include "Connection.h"
#include "Parser.h"
#include "Status.h"
#include "Commands.h"

// Main library class
class CrealityKE
{
public:

    CrealityKE();

    // Connect to printer
    void begin(const char* ip, uint16_t port = 9999);

    // Process WebSocket events
    void loop();

    // Current nozzle temperature
    float nozzleTemp() const;

    // Current bed temperature
    float bedTemp() const;

    // Target nozzle temperature
    int targetNozzleTemp() const;

    // Target bed temperature
    int targetBedTemp() const;

    // Print progress (0-100)
    int progress() const;

    // Current printing layer
    int currentLayer() const;

    // Total printing layers
    int totalLayers() const;

    // Elapsed print time (seconds)
    int printTime() const;

    // Remaining print time (seconds)
    int remainingTime() const;

    // Printer state
    int state() const;

private:

    // Printer connection
    Connection connection;

    // JSON parser
    Parser parser;

    // Shared printer status
    PrinterStatus status;

    // Printer commands
    Commands commands;
};

#endif