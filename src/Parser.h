#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>
#include <ArduinoJson.h>

#include "Status.h"

// Parses printer messages
class Parser
{
public:

    Parser() = default;

    // Attach printer status object
    void begin(PrinterStatus* status);

    // Parse incoming JSON message
    void parse(const String& json);

private:

    // Shared printer status
    PrinterStatus* _status = nullptr;

    // Parse temperature values
    void parseTemperatures(JsonDocument& doc);

    // Parse print information
    void parsePrint(JsonDocument& doc);

    // Parse fan information
    void parseFans(JsonDocument& doc);

    // Parse printer state
    void parseState(JsonDocument& doc);

    // Parse motion data
    void parseMotion(JsonDocument& doc);

    // Parse system information
    void parseSystem(JsonDocument& doc);
};

#endif