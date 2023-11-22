/*
 *    ____ ____  _
 *  / ___/ ___|| |
 * | |  _\___ \| |
 * | |_| |___) | |___
 *  \____|____/|_____|
 *
 * GShellLight. Main header file.
 *
 * Author: Grindelf P.
 * Created on 2023-09-13.
 *
 */

#ifndef G_SHELL_LIGHT_MAIN_HEADER_HPP
#define G_SHELL_LIGHT_MAIN_HEADER_HPP

#include <sys/file.h>
#include "common.h"
#include "commandControl.h"
#include "fileControl.h"
#include "gls.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

#define while_is_used while (1)
#define EXIT "exit"
#define STOP_NOW strcmp(commands[0], EXIT) == 0
#define STOP {printf("Stopping the program...\n"); break;}
#define OK 0
#define ERROR (-1)
#define WAIT_FOR_CHILD wait(NULL)

/**
 * Executes the provided command.
 * @param command command name
 * @param argv arguments vector
 */
void execute(const char *command, char *const *argv);

/**
 * Executes the provided native command.
 * @param command native command name
 * @param argv arguments vector
 * @return nothing if success (because current process is stopped),
 * error code if error occurred
 */
int execna(const char *command, char *const *argv);

void execute(const char *command, char *const *argv) {
    if (isNative(command)) {
        execna(command, argv);
        printf("Error executing native command!\n");
    } else {
        execvp(command, argv);
        printf("Command not found!\n");
    }
}

int execna(const char *command, char *const *argv) {
    int completionStatus = OK;
    if (GLS) completionStatus = gls(argv);
    else if (GCAT) printf("gcat not implemented yet\n");

    if (completionStatus == OK) exit(getpid()); // if everything is ok, exit the child process

    return completionStatus; // if error occurred return error code
}

#endif //G_SHELL_LIGHT_MAIN_HEADER_HPP
