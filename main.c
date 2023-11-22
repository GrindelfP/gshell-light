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

        if (STOP_NOW) STOP

        // int streamRedirection = defineStreamRedirection(commands);

        if (!fork()) execute(trimmedCommands[0], trimmedCommands);
        else WAIT_FOR_CHILD;
    }

    return 0;
}
