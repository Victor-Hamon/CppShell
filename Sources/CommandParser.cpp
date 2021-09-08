//
// Created by VictorHamon on 06/09/2021.
//

#include <iostream>
#include <sstream>
#include "CommandParser.hpp"
#include "DefaultSettings.hpp"

std::vector<Command> CommandParser::ParseInput(const std::string &input) {
    std::vector<Command> commands;
    std::stringstream ss(input);
    std::string temp_command_buffer;
    std::string temp_argument_buffer;

    while (std::getline(ss, temp_command_buffer, ';')) {
        if (temp_command_buffer.find_first_not_of(' ') != std::string::npos) {
            std::stringstream ss_temp(temp_command_buffer);
            std::vector<std::string> raw;
            std::vector<std::string> arguments;
            std::string exec_name;

            //TODO gérer les tabs en plus des espaces
            while (std::getline(ss_temp, temp_argument_buffer, ' ')) {
                if (temp_argument_buffer.find_first_not_of(' ') != std::string::npos) {
                    arguments.push_back(temp_argument_buffer);
                }
                else continue;
            }
            raw = arguments;
            exec_name = arguments[0];
            arguments.erase(arguments.begin());
            commands.emplace_back(exec_name, arguments, raw);
        } else continue;
    }

    return commands;
}
