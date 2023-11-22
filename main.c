/*
 *    ____ ____  _
 *  / ___/ ___|| |
 * | |  _\___ \| |
 * | |_| |___) | |___
 *  \____|____/|_____|
 *
 * GShellLight. A simple shell. The program takes a command from the user and executes it.
 * The program is terminated when the user enters the command 'exit'.
 *
 * Author: Grindelf P.
 * Created on 2023-09-13.
 *
 */

#include "mainHeader.h"

int main() {

    while_is_used {
        char commands[ARG_SIZE][CMD_SIZE];
        char *trimmedCommands[TRIMMED_ARG_SIZE];
        getArgumentsVector(commands);

        trim(commands, trimmedCommands);

        if (STOP_NOW) STOP;

        // int streamRedirection = defineStreamRedirection(commands);

        if (!fork()) {
            if (isNative(trimmedCommands[0])) {
                executeNative(NULL);
            } else {
                execvp(trimmedCommands[0], trimmedCommands);
                printf("Command not found!\n");
            }
        } else WAIT_FOR_CHILD;
    }

    return 0;
}

int executeNative(char *const *commands) {
    int completionStatus = OK;
    char *mainCommand = commands[0];
    if (strcmp(mainCommand, nativeCommands[0]) == 0) {
        completionStatus = gls(commands);
    }

    return completionStatus;
}
