//
// Created by VictorHamon on 06/09/2021.
//

#ifndef SISH_COMMAND_HPP
#define SISH_COMMAND_HPP

#include <xstring>
#include <vector>

class Command {
private:
    std::string _exec;
    std::vector<std::string> _arguments;
public:
    Command(std::string exec, std::vector<std::string> arguments);
    explicit Command(std::string exec);
    Command();

    //Setters
    void setExec(const std::string &exec);
    void setArguments(const std::vector<std::string> &arguments);
    //Getters
    [[nodiscard]] const std::string &getExec() const;
    [[nodiscard]] const std::vector<std::string> &getArguments() const;
};

#endif //SISH_COMMAND_HPP
