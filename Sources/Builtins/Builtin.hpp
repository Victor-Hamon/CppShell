//
// Created by VictorHamon on 06/09/2021.
//

#ifndef SISH_BUILTIN_HPP
#define SISH_BUILTIN_HPP

#include <map>
#include <functional>
#include <vector>
#include "../Command.hpp"

struct builtin_command {
    std::string name;
    std::function<int(Command input)> _callback;
};

int Builtin_ChangeDirectory(const Command& input);
bool isBuiltin(const Command& input);

    static std::vector<builtin_command> BuiltinCommands = {
        {"cd", Builtin_ChangeDirectory},
};

#endif //SISH_BUILTIN_HPP
