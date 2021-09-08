//
// Created by VictorHamon on 06/09/2021.
//

#ifndef SISH_SHELL_HPP
#define SISH_SHELL_HPP


#include  <stdio.h>
#include  <stdlib.h>
#include "Command.hpp"
#include "DefaultSettings.hpp"
#include "CommandParser.hpp"

class Shell {
private:
    char **_envp;
    bool _on{};
    int _history_size = DEFAULT_HISTORY_SIZE;
    std::string _last_raw_input;
    std::vector<Command> _history;
    std::vector<std::string> _exec_paths;
public:
    Shell();
    Shell(char **envp);
    virtual ~Shell();
    void StartShell();
    void GetExecPaths();
    void ExecuteCommand(Command& command);
    void StartChildProcess(Command& command);
};

#endif //SISH_SHELL_HPP
