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

        getArgumentsVector(commands);

        for (int i = 0; i < ARG_SIZE; i++) {
            if (strlen(commands[i]) > 0) {
                printf("Command %d: %s\n", i, commands[i]);
            }
        }

        /*printf("%lu", sizeof(commands) / sizeof(commands[0]));

        if (stop(commands)) {
            printf("Stopping the program...\n");
            break;
        }

        for (int i = 0; i < ARG_SIZE; ++i) {
            printf("%d) %s\n", i, commands[i]);
        }

        printf("Command: %s\n", commands[0]);

        int streamRedirection = defineStreamRedirection(commands);

        printf("Stream redirection: %d\n", streamRedirection);

        int childPid = fork();

        printf("Child pid: %d\n", childPid);

        if (!childPid) {
            printf("Child process is running...\n");
            if (streamRedirection) {
                int f1 = open(commands[streamRedirection + 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
                dup2(f1, 1);
                strcpy(commands[streamRedirection], "\0");
            }

            if (isNative(commands)) {
                run(commands, childPid);
            } else {
                printf("Executing %s command...\n", commands[0]);
                execvp(commands[0], (char *const *) commands);
                printf("Command not found!\n");
            }
        } else {
            wait(NULL);
        }
        */
    }

    return 0;
}

int run(char commands[ARG_SIZE][CMD_SIZE], int childPid) {
    char *mainCommand = commands[0];
    if (strcmp(mainCommand, nativeCommands[0]) == 0) {
        printf("gls is running\n");
        int glsResult = gls(commands);
        if (glsResult == ERROR) return error(commands[0]);
    }

    return 0;
}

int error(char *commandName) {
    printf("Error occurred while completing %s command\n", commandName);

    return -1;
}
