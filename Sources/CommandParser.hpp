//
// Created by VictorHamon on 06/09/2021.
//

#ifndef SISH_COMMANDPARSER_HPP
#define SISH_COMMANDPARSER_HPP

#include "Command.hpp"

class CommandParser {
private:
public:
    static Command ParseString(std::string input);
};

#endif //SISH_COMMANDPARSER_HPP
