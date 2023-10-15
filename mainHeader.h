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

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/file.h>
#include "common.h"

#define ERROR (-1)
#define perpetual while (1)

int run(char commands[ARG_SIZE][CMD_SIZE], int childPid);

int error(char *commandName);

#endif //G_SHELL_LIGHT_MAIN_HEADER_HPP
