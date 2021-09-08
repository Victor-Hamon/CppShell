//
// Created by VictorHamon on 06/09/2021.
//

#include <iostream>
#include <algorithm>
#include <ranges>

#include "Builtin.hpp"

bool isBuiltin(const Command &input) {
    auto compareNames = [input] () {
        return [input](const builtin_command &cmd) { return cmd.name == input.getExec(); };
    };
    return std::ranges::any_of(BuiltinCommands, compareNames());
}

