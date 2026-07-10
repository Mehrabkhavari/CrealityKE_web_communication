#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>

class Parser
{
public:

    Parser();

    void parse(const String& payload);

};

#endif