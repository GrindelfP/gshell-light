#
#    ____ ____  _
#  / ___/ ___|| |
# | |  _\___ \| |
# | |_| |___) | |___
#  \____|____/|_____|
#
# GShellLight. CMakeLists.txt file of the project.
#


cmake_minimum_required(VERSION 3.26)
project(gshell-light)

set(CMAKE_C_STANDARD 17)

add_executable(gshell-light main.c
        mainHeader.h
        commandControl.h
        fileControl.h
        gls.h
        nativeCommands.h
        common.h
)
