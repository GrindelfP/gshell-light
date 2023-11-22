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
#include "glsMode.h"

#define CURRENT_DIRECTORY "."

void defineGlsMode(char *const *argv, MODEV glsModeVector);

/**
 * Prints the list of files in the directory
 * (if path not provided - current directory).
 * @param argv arguments vector
 * @return 0 if success, -1 if error occurred
 */
int gls(char *const *argv) {
    printf("gls\n");

    int functionState = 0;

    MODEV glsModeVector;
    defineGlsMode(argv, glsModeVector);
    char *path;
    if (glsModeVector[0] == CLEAN) path = argv[1];
    else path = CURRENT_DIRECTORY;

    printf("Path: %s\n", path);
    for (int i = 0; i < MODEV_SIZE; ++i) {
        printf("%d\n", glsModeVector[i]);
    }

    DIR *directory = opendir(path);
    if (directory == NULL) {
        printf("Error opening directory!\n");
        functionState = -1;
    } else {
        struct dirent *contentEntry = readdir(directory);
        while (contentEntry != NULL) {
            printf("%s\n", contentEntry->d_name);
            contentEntry = readdir(directory);
        }
        closedir(directory);
    }

    return functionState;
}

void defineGlsMode(char *const *argv, MODEV glsModeVector) {
    // Check for the provided path
    if (argv[1][0] != '-') glsModeVector[0] = CLEAN;
    else glsModeVector[0] = UNPATHED;

    if (contains(argv, "-a")) glsModeVector[1] = ALL;
    if (contains(argv, "-r")) glsModeVector[2] = RECURSIVE;
}

#endif //G_SHELL_LIGHT_GLS_HPP