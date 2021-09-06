//
// Created by VictorHamon on 06/09/2021.
//

#ifndef SISH_DEFAULTSETTINGS_HPP
#define SISH_DEFAULTSETTINGS_HPP

const int DEFAULT_HISTORY_SIZE = 50;


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
static const std::string slash="\\";
#else
static const std::string slash="/";
#endif

#endif //SISH_DEFAULTSETTINGS_HPP
