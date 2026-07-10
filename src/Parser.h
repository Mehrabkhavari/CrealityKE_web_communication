#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>
#include <ArduinoJson.h>

#include "Status.h"

// Parses incoming printer messages
class Parser
{
public:

    Parser() = default;

    // Attach printer status object
    void begin(PrinterStatus* status);

    // Parse incoming JSON
    void parse(const String& json);

private:

    // Shared printer status
    PrinterStatus* _status = nullptr;

    // Parse temperature data
    void parseTemperatures(JsonDocument& doc);

    // Parse print information
    void parsePrint(JsonDocument& doc);

    // Parse fan information
    void parseFans(JsonDocument& doc);

    // Parse printer state
    void parseState(JsonDocument& doc);

    // Parse motion data
    void parseMotion(JsonDocument& doc);

    // Parse system data
    void parseSystem(JsonDocument& doc);
};

#endif