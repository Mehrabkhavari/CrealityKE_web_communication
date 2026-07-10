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

    // Parse each message group
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

// Parse print information
void Parser::parsePrint(JsonDocument& doc)
{
    JsonVariant value;

    // Print progress
    value = doc["printProgress"];
    if (!value.isNull())
    {
        _status->_progress = value.as<int>();
    }

    // Current layer
    value = doc["layer"];
    if (!value.isNull())
    {
        _status->_currentLayer = value.as<int>();
    }

    // Total layers
    value = doc["TotalLayer"];
    if (!value.isNull())
    {
        _status->_totalLayers = value.as<int>();
    }

    // Elapsed print time
    value = doc["printJobTime"];
    if (!value.isNull())
    {
        _status->_printTime = value.as<int>();
    }

    // Remaining print time
    value = doc["printLeftTime"];
    if (!value.isNull())
    {
        _status->_remainingTime = value.as<int>();
    }
}

// Parse cooling system
void Parser::parseFans(JsonDocument& doc)
{
    JsonVariant value;

    // Main fan status
    value = doc["fan"];
    if (!value.isNull())
    {
        _status->_fan = value.as<int>() != 0;
    }

    // Model fan speed
    value = doc["modelFanPct"];
    if (!value.isNull())
    {
        _status->_modelFan = value.as<int>();
    }

    // Case fan speed
    value = doc["caseFanPct"];
    if (!value.isNull())
    {
        _status->_caseFan = value.as<int>();
    }

    // Auxiliary fan speed
    value = doc["auxiliaryFanPct"];
    if (!value.isNull())
    {
        _status->_auxiliaryFan = value.as<int>();
    }

    // Filament sensor enabled
    value = doc["materialDetect"];
    if (!value.isNull())
    {
        _status->_materialDetected = value.as<int>() != 0;
    }

    // Filament available
    value = doc["materialStatus"];
    if (!value.isNull())
    {
        _status->_materialStatus = value.as<int>() != 0;
    }
}

// Parse printer state
void Parser::parseState(JsonDocument& doc)
{
    JsonVariant value;

    // Printer state
    value = doc["state"];
    if (!value.isNull())
    {
        _status->_state = value.as<int>();
    }
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