//
// Created by VictorHamon on 06/09/2021.
//

#include <iostream>
#include <filesystem>
#include <thread>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include "Shell.hpp"
#include "Builtins/Builtin.hpp"
#include "ManageChildProcess.hpp"

#if defined(WIN32)
#include <io.h>
#else
#endif

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

        if (_last_raw_input == "quit") {
            _on = false;
            break;
        }
        auto commands = CommandParser::ParseInput(_last_raw_input);
        for (auto &command: commands) {
            this->ExecuteCommand(command);
        }
    }

}

void Shell::GetExecPaths() {
    try {
        std::string paths = std::getenv("PATH");
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        std::string delimiter = ";";
#else
        std::string delimiter = ":";
#endif
        std::string token;
        unsigned int pos;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-constant-out-of-range-compare"
        while ((pos = paths.find(delimiter)) != std::string::npos && !paths.empty()) {
            token = paths.substr(0, pos);
            token += (token.back() == slash[0]) ? "" : slash;
            _exec_paths.push_back(token);
            paths.erase(0, pos + delimiter.length());
        }
#pragma clang diagnostic pop
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void Shell::ExecuteCommand(Command &command) {
    _history.push_back(command);

    if (isBuiltin(command)) {
        std::cout << "BUILTIN" << std::endl;
        return;
    } else {
        StartChildProcess(command);
    }
}

Shell::Shell(char **envp) : Shell() {
    _envp = envp;
    std::cout << "oui" << std::endl;
}

void Shell::StartChildProcess(Command &command) {
    for (auto &path: _exec_paths) {
        std::vector<std::vector<char>> vstrings;
        std::vector<char *> cstrings;

        vstrings.reserve(command.getRawInput().size() + 1);
        cstrings.reserve(command.getRawInput().size() + 1);
        command.getRawInput()[0] = path + command.getExec();
        for (const auto &i: command.getRawInput()) {
            vstrings.emplace_back(i.begin(), i.end());
            vstrings.back().push_back('\0');
            cstrings.push_back(vstrings.back().data());
        }
        cstrings.push_back(NULL);
        std::string concat = std::accumulate(std::begin(command.getRawInput()) + 1, std::end(command.getRawInput()),
                                             command.getRawInput()[0],
                                             [](std::string s0, std::string const &s1) { return s0 += " " + s1; });
        int err = ManageChildProcess::CreateChildProcess(command.getRawInput()[0].c_str(), cstrings.data(), _envp,
                                               const_cast<char *>(concat.c_str()));
        if (err == 0)
            break;
        //std::future<int> error = std::async(execve, command.getRawInput()[0].c_str(), cstrings.data(), _envp);

        //std::cout << "Error nb : " << error.get() << ", [ERROR] " << std::strerror(errno) << std::endl;
    }
}
