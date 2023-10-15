/*
 *    ____ ____  _
 *  / ___/ ___|| |
 * | |  _\___ \| |
 * | |_| |___) | |___
 *  \____|____/|_____|
 *
 * GShellLight. Header file for gls command, which is similar to
 * regular shell ls command.
 *
 * Author: Grindelf P.
 * Created on 2023-10-04.
 *
 */

#ifndef G_SHELL_LIGHT_GLS_HPP
#define G_SHELL_LIGHT_GLS_HPP

#include <sys/dir.h>
#include "mainHeader.h"

#define CURRENT_DIRECTORY "."
#define CONTENT_LIST_SIZE 1024

int gls(char argv[ARG_SIZE][CMD_SIZE]) {

    char *directoryName = argv[0];

    if (directoryName == NULL) directoryName = CURRENT_DIRECTORY;

    DIR *directory = opendir(directoryName);
    struct dirent *contentEntry = readdir(directory);

    while (contentEntry != NULL) {
        printf("%s\n", contentEntry->d_name);
        contentEntry = readdir(directory);
    }

    return 0;
}

#endif //G_SHELL_LIGHT_GLS_HPP