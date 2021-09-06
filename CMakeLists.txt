cmake_minimum_required(VERSION 3.20)
project(SiSH)

set(CMAKE_CXX_STANDARD 23)

add_executable(SiSH main.cpp Sources/Shell.cpp Sources/Shell.hpp Sources/Command.cpp Sources/Command.hpp Sources/DefaultSettings.hpp Sources/CommandParser.cpp Sources/CommandParser.hpp Sources/CustomCommand.cpp Sources/CustomCommand.hpp)
