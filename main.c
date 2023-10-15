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
#include "commandControl.h"
#include "fileControl.h"
#include "gls.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {

    perpetual {
        char buffer[CMD_SIZE];
        char command[ARG_SIZE][CMD_SIZE];

        printf("Enter the command (to stop enter 'exit'): ");
        fgets(buffer, CMD_SIZE, stdin);

        char *newline = strchr(buffer, '\n');
        if (newline) *newline = 0;

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        splitCommand(buffer, command);

        int streamRedirection = defineStreamRedirection(command);

        int childPid = fork();

        if (!childPid) {
            if (streamRedirection > 0) {
                int f1 = open(command[streamRedirection + 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
                dup2(f1, 1);
                strcpy(command[streamRedirection], "\0");
            }

            if (filterNativeCommands(command)) {
                run(command, childPid);
            } else {
                execvp(command[0], command);
                printf("Command not found!\n");
            }
        } else {
            wait(NULL);
        }
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
