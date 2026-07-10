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
    if (_status == nullptr)
        return;

    JsonDocument doc;

    if (deserializeJson(doc, json))
        return;

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

    value = doc["nozzleTemp"];
    if (!value.isNull())
    {
        if (value.is<const char*>())
            _status->_nozzleTemp = atof(value.as<const char*>());
        else
            _status->_nozzleTemp = value.as<float>();
    }

    value = doc["bedTemp0"];
    if (!value.isNull())
    {
        if (value.is<const char*>())
            _status->_bedTemp = atof(value.as<const char*>());
        else
            _status->_bedTemp = value.as<float>();
    }

    value = doc["targetNozzleTemp"];
    if (!value.isNull())
        _status->_targetNozzleTemp = value.as<int>();

    value = doc["targetBedTemp0"];
    if (!value.isNull())
        _status->_targetBedTemp = value.as<int>();
}

// Parse print information
void Parser::parsePrint(JsonDocument& doc)
{
    JsonVariant value;

    value = doc["printProgress"];
    if (!value.isNull())
        _status->_progress = value.as<int>();

    value = doc["layer"];
    if (!value.isNull())
        _status->_currentLayer = value.as<int>();

    value = doc["TotalLayer"];
    if (!value.isNull())
        _status->_totalLayers = value.as<int>();

    value = doc["printJobTime"];
    if (!value.isNull())
        _status->_printTime = value.as<int>();

    value = doc["printLeftTime"];
    if (!value.isNull())
        _status->_remainingTime = value.as<int>();
}

// Parse cooling system
void Parser::parseFans(JsonDocument& doc)
{
    JsonVariant value;

    value = doc["fan"];
    if (!value.isNull())
        _status->_fan = value.as<int>() != 0;

    value = doc["modelFanPct"];
    if (!value.isNull())
        _status->_modelFan = value.as<int>();

    value = doc["caseFanPct"];
    if (!value.isNull())
        _status->_caseFan = value.as<int>();

    value = doc["auxiliaryFanPct"];
    if (!value.isNull())
        _status->_auxiliaryFan = value.as<int>();

    value = doc["materialDetect"];
    if (!value.isNull())
        _status->_materialDetected = value.as<int>() != 0;

    value = doc["materialStatus"];
    if (!value.isNull())
        _status->_materialStatus = value.as<int>() != 0;
}

// Parse printer state
void Parser::parseState(JsonDocument& doc)
{
    JsonVariant value;

    value = doc["state"];
    if (!value.isNull())
        _status->_state = value.as<int>();
}

// Reserved for future versions
void Parser::parseMotion(JsonDocument& doc)
{
    (void)doc;
}

// Parse device information
void Parser::parseSystem(JsonDocument& doc)
{
    JsonVariant value;

    // Printer hostname
    value = doc["hostname"];
    if (!value.isNull())
        _status->_hostname = value.as<const char*>();

    // Printer model
    value = doc["model"];
    if (!value.isNull())
        _status->_model = value.as<const char*>();

    // Firmware version
    value = doc["modelVersion"];
    if (!value.isNull())
        _status->_version = value.as<const char*>();

    // Printer connection status
    value = doc["connect"];
    if (!value.isNull())
        _status->_connected = value.as<int>() != 0;

    // Maximum nozzle temperature
    value = doc["maxNozzleTemp"];
    if (!value.isNull())
        _status->_maxNozzleTemp = value.as<int>();

    // Maximum bed temperature
    value = doc["maxBedTemp"];
    if (!value.isNull())
        _status->_maxBedTemp = value.as<int>();
}