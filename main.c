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

    perpetual {
        char commands[ARG_SIZE][CMD_SIZE];
        char *trimmedCommands[TRIMMED_ARG_SIZE];
        getArgumentsVector(commands);

        trim(commands, trimmedCommands);

        if (contains(commands, EXIT)) {
            printf("Stopping the program...\n");
            break;
        }

        int streamRedirection = defineStreamRedirection(commands);

        printf("Stream redirection: %d\n", streamRedirection);

        if (!fork()) {
            if (streamRedirection) {
                int f1 = open(commands[streamRedirection + 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
                dup2(f1, 1);
                removeRedirectionArguments(commands, streamRedirection);
            }

            if (isNative(commands)) {
                executeNative(commands);
            } else {
                execvp(trimmedCommands[0], trimmedCommands);
                printf("Command not found!\n");
            }
        } else {
            wait(NULL);
        }
    }

    return 0;
}

int executeNative(char commands[ARG_SIZE][CMD_SIZE]) {
    char *mainCommand = commands[0];
    if (strcmp(mainCommand, nativeCommands[0]) == 0) {
        int glsResult = gls(commands);
        if (glsResult == ERROR) return error(commands[0]);
    }

    return 0;
}

int error(char *commandName) {
    printf("Error occurred while completing %s command\n", commandName);

    return -1;
}
