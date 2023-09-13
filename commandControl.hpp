/*
 *    ___ ___ _
 *  / __/ __| |
 * | (_ \__ \ |__
 * \___|___/____|
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

#define SEPARATOR " "

void splitCommand(char* buffer, char *commandContainer[]);

void splitCommand(char* buffer, char *commandContainer[]) {
    int i = 0;
    commandContainer[0] = strtok(buffer, SEPARATOR);
    while (commandContainer[i] != nullptr) {
        commandContainer[++i] = strtok(nullptr, SEPARATOR);
    }
}

#endif //G_SHELL_LIGHT_COMMAND_CONTROLLER_HPP
