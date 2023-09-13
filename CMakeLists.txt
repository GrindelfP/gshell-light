#
#    ___ ___ _
#  / __/ __| |
# | (_ \__ \ |__
# \___|___/____|
#
# GShellLight. CMakeLists.txt file of the project.
#


cmake_minimum_required(VERSION 3.26)
project(GShellLight)

set(CMAKE_CXX_STANDARD 17)

add_executable(GShellLight main.cpp
        mainHeader.hpp
        commandControl.hpp
        fileControl.hpp
        tmp.cpp)
