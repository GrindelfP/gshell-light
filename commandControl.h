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

/**
 * Trims the commands array to the first empty element.
 *
 * <p><strong>Example:</strong> if the commands array is:</p>
 * {0: ls
 * 1: -a
 * 2: -l
 * 3: \0
 * ...
 * 9: \0}
 * <p>the trimmedCommands array will be:<p>
 * {0: ls
 * 1: -a
 * 2: -l
 * 3: \0}
 * @param commands vector of arguments
 * @param trimmedCommands trimmed vector of arguments
 * @return 0 if success
 */
int trim(char commands[ARG_SIZE][CMD_SIZE], char *trimmedCommands[ARG_SIZE]) {
    int i;
    for (i = 0; i < 10; ++i) {
        if (commands[i][0] == '\0') {
            break;
        }
        trimmedCommands[i] = commands[i];
    }

    return 0;
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
    token = strtok(buffer, SEPARATOR);
    while (token != NULL && numberOfCommands < ARG_SIZE) {
        strcpy(commands[numberOfCommands], token);
        token = strtok(NULL, SEPARATOR);
        numberOfCommands++;
    }

    *commandsNumber = numberOfCommands;

    return 0;
}
/**
 * Get the arguments vector from the input line
 * @param commands arguments vector
 * @return 0 if success, -1 if error
 */
int getArgumentsVector(char commands[ARG_SIZE][CMD_SIZE]) {
    char buffer[INIT_LINE_SIZE];
    int commandsNumber = 0;

    printf("Enter your command ('exit' if you want to stop): ");
    fgets(buffer, sizeof(buffer), stdin);

    // Trim the unused space
    size_t length = strlen(buffer);
    if (buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
    }

    if (splitCommand(buffer, commands, &commandsNumber) == -1) {
        return -1;
    }

    // Trim the commands array if needed
    for (int i = commandsNumber; i < ARG_SIZE; i++) {
        commands[i][0] = '\0';
    }

    return 0;
}

/**
 * Check if the argument is in the list of native command
 * (the command native to GShellLight)
 * @param command vector of arguments
 * @return 1 if the argument is in the list, 0 otherwise
 */
int isNative(const char *command) {
    int isNative = 0;
    for (int i = 0; i < NATIVE_CMDS_SIZE; ++i) {
        if (strcmp(command, nativeCommands[i]) == 0) {
            isNative = 1;
            break;
        }
    }

    return isNative;
}

#endif //G_SHELL_LIGHT_COMMAND_CONTROLLER_H

