#include "Parser.h"
#include <stdlib.h>

// Attach shared printer status
void Parser::begin(PrinterStatus* status)
{
    _status = status;
}

// Parse incoming JSON
void Parser::parse(const String& json)
{
    // Nothing to update
    if (_status == nullptr)
        return;

    JsonDocument doc;

    // Ignore invalid JSON
    DeserializationError error = deserializeJson(doc, json);

    if (error)
        return;

    // Parse each message category
    parseTemperatures(doc);
    parsePrint(doc);
    parseFans(doc);
    parseState(doc);
    parseMotion(doc);
    parseSystem(doc);
}

// Parse temperature values
void Parser::parseTemperatures(JsonDocument& doc)
{
    JsonVariant value;

    // Current nozzle temperature
    value = doc["nozzleTemp"];
    if (!value.isNull())
    {
        if (value.is<const char*>())
            _status->_nozzleTemp = atof(value.as<const char*>());
        else
            _status->_nozzleTemp = value.as<float>();
    }

    // Current bed temperature
    value = doc["bedTemp0"];
    if (!value.isNull())
    {
        if (value.is<const char*>())
            _status->_bedTemp = atof(value.as<const char*>());
        else
            _status->_bedTemp = value.as<float>();
    }

    // Target nozzle temperature
    value = doc["targetNozzleTemp"];
    if (!value.isNull())
    {
        _status->_targetNozzleTemp = value.as<int>();
    }

    // Target bed temperature
    value = doc["targetBedTemp0"];
    if (!value.isNull())
    {
        _status->_targetBedTemp = value.as<int>();
    }
}

// Reserved for future versions
void Parser::parsePrint(JsonDocument& doc)
{
    (void)doc;
}

// Reserved for future versions
void Parser::parseFans(JsonDocument& doc)
{
    (void)doc;
}

// Reserved for future versions
void Parser::parseState(JsonDocument& doc)
{
    (void)doc;
}

// Reserved for future versions
void Parser::parseMotion(JsonDocument& doc)
{
    (void)doc;
}

// Reserved for future versions
void Parser::parseSystem(JsonDocument& doc)
{
    (void)doc;
}