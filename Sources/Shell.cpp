//
// Created by VictorHamon on 06/09/2021.
//

#include <iostream>
#include <filesystem>
#include "Shell.hpp"
#include "Builtins/Builtin.hpp"

Shell::Shell() {
    this->GetExecPaths();
};

Shell::~Shell() {
    std::cout << "Shell exited" << std::endl;
}

void Shell::StartShell() {
    _on = true;
    int n = 0;

    while (_on) {
        std::cout << "SiSH >";
        std::getline(std::cin, _last_raw_input);
        std::stringstream s(_last_raw_input);
        if (s >> n)
            continue;

        if (_last_raw_input == "exit")
            _on = false;
        auto commands = CommandParser::ParseInput(_last_raw_input);
        for (auto& command:commands) {
            this->ExecuteCommand(command);
            std::cout << command.getExec() << std::endl;
        }
    }

}

void Shell::GetExecPaths() {
    try {
        std::string paths = std::getenv("PATH");
        std::string delimiter = ";";
        std::string token;
        unsigned int pos;

        while ((pos = paths.find(delimiter)) != std::string::npos) {
            token = paths.substr(0, pos);
            token += (token.back() == slash[0]) ? "" : slash;
            _exec_paths.push_back(token);
            paths.erase(0, pos + delimiter.length());
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void Shell::ExecuteCommand(Command& command) {
    _history.push_back(command);
    if (isBuiltin(command)) {
        std::cout << "OUI LE BUILTIN" << std::endl;
    } else {

    }
}
