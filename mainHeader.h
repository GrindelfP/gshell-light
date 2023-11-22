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


int executeNative(char *const *commands);

#endif //G_SHELL_LIGHT_MAIN_HEADER_HPP
