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

#define ERROR (-1)
#define perpetual while (1)
#define EXIT "exit"

int executeNative(char commands[ARG_SIZE][CMD_SIZE]);

int error(char *commandName);

#endif //G_SHELL_LIGHT_MAIN_HEADER_HPP
