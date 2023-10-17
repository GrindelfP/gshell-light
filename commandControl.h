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
#include <stdlib.h>
#include "mainHeader.h"
#include "nativeCommands.h"
#include "commandControl.h"
#include "fileControl.h"
#include "gls.h"

#define SEPARATOR " "

int splitCommand(char buffer[INIT_LINE_SIZE], char commands[ARG_SIZE][CMD_SIZE], int *commandsNumber);

int getArgumentsVector(char args[ARG_SIZE][CMD_SIZE]) {
    char buffer[INIT_LINE_SIZE];
    int commandsNumber = 0;

    printf("Enter a command: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Trim the unused space
    size_t length = strlen(buffer);
    if (buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
    }

    splitCommand(buffer, args, &commandsNumber);

    // Split the input line into commands


    // Trim the args array if needed
    for (int i = commandsNumber; i < ARG_SIZE; i++) {
        args[i][0] = '\0';
    }
}

/**
 * Split the command into arguments vector.
 * @param buffer commands buffer
 * @param commandContainer command container where vector will be stored
 * @return 0 if success, -1 if error
 */
int splitCommand(char buffer[INIT_LINE_SIZE], char commands[ARG_SIZE][CMD_SIZE], int *commandsNumber) {
    char *token;
    int numberOfCommands = *commandsNumber;
    token = strtok(buffer, " ");
    while (token != NULL && numberOfCommands < ARG_SIZE) {
        strcpy(commands[numberOfCommands], token);
        token = strtok(NULL, " ");
        numberOfCommands++;
    }

    *commandsNumber = numberOfCommands;

    return 0;
}

/**
 * Check if the argument is in the list of native commands
 * (the commands native to GShellLight)
 * @param commands vector of arguments
 * @return 1 if the argument is in the list, 0 otherwise
 */
int isNative(char commands[ARG_SIZE][CMD_SIZE]) {
    int isNative = 0;
    int i = 0;
    while (nativeCommands[i] != NULL) {
        if (contains(commands, nativeCommands[i])) {
            isNative = 1;
            break;
        }
    }

    return isNative;
}

#endif //G_SHELL_LIGHT_COMMAND_CONTROLLER_H

