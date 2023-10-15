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

#ifndef G_SHELL_LIGHT_COMMAND_CONTROLLER_H
#define G_SHELL_LIGHT_COMMAND_CONTROLLER_H

#include <string.h>
#include "mainHeader.h"
#include "nativeCommands.h"

#define SEPARATOR " "

int splitCommand(char *buffer, char commandContainer[ARG_SIZE][CMD_SIZE]) {
    int i = 0;
    char *token = strtok(buffer, SEPARATOR);
    while (token != NULL) {
        strcpy(commandContainer[i++], token);
        token = strtok(NULL, SEPARATOR);
    }
    commandContainer[i][0] = '\0'; // Ensure the last element is NULL

    return 0;
}


int filterNativeCommands(char commands[ARG_SIZE][CMD_SIZE]) {
    int isNative = 0;
    int i = 0;
    while (nativeCommands[i] != NULL) {
        if (strcmp(nativeCommands[i], commands[0]) == 0) {
            isNative = 1;
            break;
        }
        i++;
    }

    return isNative;
}

#endif //G_SHELL_LIGHT_COMMAND_CONTROLLER_H

