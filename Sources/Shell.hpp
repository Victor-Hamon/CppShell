//
// Created by VictorHamon on 06/09/2021.
//

#ifndef SISH_SHELL_HPP
#define SISH_SHELL_HPP

#include "Command.hpp"
#include "DefaultSettings.hpp"
#include "CommandParser.hpp"

class Shell {
private:
    bool _on{};
    int _history_size = DEFAULT_HISTORY_SIZE;
    std::string _last_raw_input;
    CommandParser _parser;
    std::vector<Command> _history;
    std::vector<std::string> _exec_paths;
public:
    Shell();
    virtual ~Shell();
    void StartShell();
    void GetExecPaths();
};

#endif //SISH_SHELL_HPP
