#ifndef CREALITYKE_H
#define CREALITYKE_H

#include <Arduino.h>

#include "Commands.h"
#include "Connection.h"
#include "Parser.h"
#include "Status.h"

// Main library class
class CrealityKE
{
public:

    CrealityKE();

    // Connect to printer
    void begin(const char* ip, uint16_t port = 9999);

    // Process WebSocket events
    void loop();

    // Send raw JSON command
    bool send(const String& json);

    // Current nozzle temperature
    float nozzleTemp() const;

    // Current bed temperature
    float bedTemp() const;

    // Target nozzle temperature
    int targetNozzleTemp() const;

    // Target bed temperature
    int targetBedTemp() const;

    // Print progress
    int progress() const;

    // Current printing layer
    int currentLayer() const;

    // Total printing layers
    int totalLayers() const;

    // Elapsed print time
    int printTime() const;

    // Remaining print time
    int remainingTime() const;

    // Printer state
    int state() const;

    // Main fan state
    bool fan() const;

    // Model fan speed
    int modelFan() const;

    // Case fan speed
    int caseFan() const;

    // Auxiliary fan speed
    int auxiliaryFan() const;

    // Filament sensor enabled
    bool materialDetected() const;

    // Filament detected
    bool materialStatus() const;

    // Printer hostname
    const String& hostname() const;

    // Printer model
    const String& model() const;

    // Firmware information
    const String& version() const;

    // Printer connection state
    bool connected() const;

    // Maximum nozzle temperature
    int maxNozzleTemp() const;

    // Maximum bed temperature
    int maxBedTemp() const;

private:

    // WebSocket connection
    Connection connection;

    // JSON parser
    Parser parser;

    // Printer status
    PrinterStatus status;

    // Command manager
    Commands commands;
};

#endif