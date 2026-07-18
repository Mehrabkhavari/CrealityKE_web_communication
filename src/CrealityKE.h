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

    // Raw communication
    bool sendRaw(const String& json);
    bool sendGet(const String& parameter);
    bool sendSet(const String& parameter, const String& value);

    // Temperature control
    bool setNozzleTemp(int temperature);
    bool setBedTemp(int temperature);

    // Homing
    bool homeX();
    bool homeY();
    bool homeZ();

    bool homeXY();
    bool homeXZ();
    bool homeYZ();

    bool homeXYZ();

    // Print control
    bool pause();
    bool resume();
    bool stop();

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

    Connection connection;
    Parser parser;
    PrinterStatus status;
    Commands commands;
};

#endif