//
// Created by VictorHamon on 06/09/2021.
//

#include "Command.hpp"

#include <utility>

Command::Command() = default;

Command::Command(std::string exec) : _exec(std::move(exec)) {

}

Command::Command(std::string exec, std::vector<std::string> arguments) : _exec(std::move(exec)),
                                                                         _arguments(std::move(arguments)) {

}

const std::string &Command::getExec() const {
    return _exec;
}

void Command::setExec(const std::string &exec) {
    _exec = exec;
}

const std::vector<std::string> &Command::getArguments() const {
    return _arguments;
}

void Command::setArguments(const std::vector<std::string> &arguments) {
    _arguments = arguments;
}
