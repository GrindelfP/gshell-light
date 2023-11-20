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
 * \brief Check if the command contains a redirection symbol
 * \param commandContainer command container
 * \return if redirection required returns index of redirection symbol, 0 if not
 */
int defineStreamRedirection(char commandContainer[ARG_SIZE][CMD_SIZE]) {
    for (int i = 0; i < ARG_SIZE && commandContainer[i][0] != '\0'; i++) {
        if (strcmp(commandContainer[i], REDIRECTION_SYMBOL) == 0) {
            return i;
        }
    }
    return 0;
}

/**
 * \brief Removes redirection arguments (redirection symbol ">" and file path)
 * from the command container
 * \param commandContainer containter of commands
 * \param redirectionIndex index of redirection symbol in the command container
 */
void removeRedirectionArguments(char commandContainer[ARG_SIZE][CMD_SIZE], int redirectionIndex) {
    for (int i = redirectionIndex; commandContainer[i] != NULL && commandContainer[i + 2] != NULL; i++) {
        strcpy(commandContainer[i], commandContainer[i + 2]);
    }
}

#endif //G_SHELL_LIGHT_FILE_CONTROL_HPP
