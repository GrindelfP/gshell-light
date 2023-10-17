/*
 *    ____ ____  _
 *  / ___/ ___|| |
 * | |  _\___ \| |
 * | |_| |___) | |___
 *  \____|____/|_____|
 *
 * GShellLight. Header file for file operations.
 *
 * Author: Grindelf P.
 * Created on 2023-09-13.
 *
 */

#ifndef G_SHELL_LIGHT_FILE_CONTROL_HPP
#define G_SHELL_LIGHT_FILE_CONTROL_HPP

#include <fcntl.h>
#include "mainHeader.h"

#define REDIRECTION_SYMBOL ">"

/**
 * Check if the command contains a redirection symbol
 * @param commandContainer command container
 * @return 1 if redirection required, 0 if not
 */
int defineStreamRedirection(char commandContainer[ARG_SIZE][CMD_SIZE]) {
    int streamRedirection = contains(commandContainer, REDIRECTION_SYMBOL);

    return streamRedirection;
}

#endif //G_SHELL_LIGHT_FILE_CONTROL_HPP
