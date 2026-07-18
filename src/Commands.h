#ifndef COMMANDS_H
#define COMMANDS_H

#include <Arduino.h>

class Connection;

// Handles all printer commands
class Commands
{
public:

    Commands();

    // Attach connection object
    void begin(Connection* connection);

    // Send raw JSON command
    bool send(const String& json);

    // Temperature control
    bool setNozzleTemp(uint16_t temperature);

    bool setBedTemp(uint16_t temperature);

protected:

    // Shared printer connection
    Connection* _connection = nullptr;
};

#endif