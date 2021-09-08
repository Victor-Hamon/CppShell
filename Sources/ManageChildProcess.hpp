//
// Created by VictorHamon on 07/09/2021.
//

#ifndef SISH_MANAGECHILDPROCESS_HPP
#define SISH_MANAGECHILDPROCESS_HPP

class ManageChildProcess {

public:
    static int CreateChildProcess(const char *pathname, char **args, char **env, char *rawline = nullptr);
};

#endif //SISH_MANAGECHILDPROCESS_HPP
