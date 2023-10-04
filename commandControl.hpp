/*
 *    ____ ____  _
 *  / ___/ ___|| |
 * | |  _\___ \| |
 * | |_| |___) | |___
 *  \____|____/|_____|
 *
 * GShellLight. Header file for command operations.
 *
 * Author: Grindelf P.
 * Created on 2023-09-13.
 *
 */

#ifndef G_SHELL_LIGHT_COMMAND_CONTROLLER_HPP
#define G_SHELL_LIGHT_COMMAND_CONTROLLER_HPP

#include "mainHeader.hpp"
#include "nativeCommands.hpp"

#define SEPARATOR " "

void splitCommand(char *buffer, char *commandContainer[]) {
    int i = 0;
    commandContainer[0] = strtok(buffer, SEPARATOR);
    while (commandContainer[i] != nullptr) {
        commandContainer[++i] = strtok(nullptr, SEPARATOR);
    }
}

int filterNativeCommands(char **commands) {
    int isNative = 0;
    int i = 0;
    while (nativeCommands[i] != nullptr) {
        if (strcmp(nativeCommands[i], commands[0]) == 0) {
            isNative = 1;
            break;
        }
        i++;
    }

    return isNative;
}

#endif //G_SHELL_LIGHT_COMMAND_CONTROLLER_HPP
