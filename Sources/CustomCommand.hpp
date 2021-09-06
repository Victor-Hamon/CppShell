//
// Created by VictorHamon on 06/09/2021.
//

#ifndef SISH_CUSTOMCOMMAND_HPP
#define SISH_CUSTOMCOMMAND_HPP

#include <map>
#include <functional>
#include <vector>
#include "Command.hpp"

struct custom_command {
    std::string name;
    std::function<int(Command input)> _callback;
};

int CustomCommand_ChangeDirectory(const Command& input);

static std::vector<custom_command> CustomCommands = {
        {"cd", CustomCommand_ChangeDirectory},
};

#endif //SISH_CUSTOMCOMMAND_HPP
