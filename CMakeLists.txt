cmake_minimum_required(VERSION 3.16)
project(SiSH)

set(CMAKE_CXX_STANDARD 20)

include_directories(Sources)
add_executable(SiSH main.cpp Sources/Shell.cpp Sources/Shell.hpp Sources/Command.cpp Sources/Command.hpp Sources/DefaultSettings.hpp Sources/CommandParser.cpp Sources/CommandParser.hpp Sources/Builtins/Builtin.cpp Sources/Builtins/Builtin.hpp Sources/Builtins/ChangeDirectory.cpp Sources/ManageChildProcess.cpp Sources/ManageChildProcess.hpp)

