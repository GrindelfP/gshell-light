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

int isArgument(const char *argument);

int avoidHiddenFiles(char argv[ARG_SIZE][CMD_SIZE]) {
    return contains(argv, "-a");
}

int isHiddenFile(char *fileName) {
    return fileName[0] == '.' || strcmp(fileName, "..") == 0;
}

int gls(char argv[ARG_SIZE][CMD_SIZE]) {

    char *directoryName;

    if (argv[1][0] != '\0' && !isArgument(argv[1])) directoryName = argv[1];
    else directoryName = CURRENT_DIRECTORY;

    DIR *directory = opendir(directoryName);
    struct dirent *contentEntry = readdir(directory);

    while (contentEntry != NULL) {
        if (avoidHiddenFiles(argv) && isHiddenFile(contentEntry->d_name)) {
            contentEntry = readdir(directory);
        } else {
            printf("%s\n", contentEntry->d_name);
            contentEntry = readdir(directory);
        }
    }

    return 0;
}

int isArgument(const char *argument) {
    return argument[0] == '-';
}

#endif //G_SHELL_LIGHT_GLS_HPP