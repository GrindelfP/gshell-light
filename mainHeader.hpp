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

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/file.h>

#define CMD_SIZE 100
#define ERROR (-1)

int run(char **commands);

int error(char *commandName);

#endif //G_SHELL_LIGHT_MAIN_HEADER_HPP
