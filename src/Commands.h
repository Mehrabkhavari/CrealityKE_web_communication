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

protected:

    // Shared printer connection
    Connection* _connection = nullptr;
};

#endif