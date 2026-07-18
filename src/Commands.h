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
    bool sendRaw(const String& json);

    // Send GET request
    bool sendGet(const String& parameter);

    // Send SET request
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

protected:

    // Shared printer connection
    Connection* _connection = nullptr;
};

#endif