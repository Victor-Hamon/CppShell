//
// Created by VictorHamon on 06/09/2021.
//

#ifndef SISH_COMMAND_HPP
#define SISH_COMMAND_HPP

#if defined(WIN32)
#include <xstring>
#else
#include <string>
#endif
#include <vector>

class Command {
private:
    std::string _exec;
    std::vector<std::string> _arguments;
    std::vector<std::string> _raw_input;
public:
    Command(std::string exec, std::vector<std::string> arguments);
    Command(std::string  exec, std::vector<std::string>  arguments, std::vector<std::string>  raw_input);
    explicit Command(std::string exec);
    Command();

    //Setters
    void setExec(const std::string &exec);
    void setArguments(const std::vector<std::string> &arguments);
    //Getters
    [[nodiscard]] const std::string &getExec() const;
    [[nodiscard]] const std::vector<std::string> &getArguments() const;
    std::vector<std::string> &getRawInput();
    void setRawInput(const std::vector<std::string> &rawInput);
};

#endif //SISH_COMMAND_HPP
