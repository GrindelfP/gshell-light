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
#include "mainHeader.hpp"
#include "common.h"

#define CURRENT_DIRECTORY "."
#define CONTENT_LIST_SIZE 1024
#define MAX_PATH_LENGTH 1024

int isRecursive(char **argv);

int flag(char *parameter);

int printIndentation(int indentationLevel) {
    for (int i = 0; i < indentationLevel; i++) {
        printf("    ");
    }

    return 0;
}

int gls(char **argv, int indentationLevel) {
    char *directoryPath = ".";
    int isRecursive = 0;
    int isAbsoluteRecursive = 0;

    if (argv[1] != NULL) {
        if (argv[1][0] != '-') {
            directoryPath = argv[1];
        } else {
            if (strcmp(argv[1], "-r") == 0) {
                isRecursive = 1;
            } else if (strcmp(argv[1], "-rr") == 0) {
                isRecursive = 1;
                isAbsoluteRecursive = 1;
            }
        }
    }

    DIR *directory;
    struct dirent *entry;

    directory = opendir(directoryPath);
    if (directory == NULL) {
        printf("Unable to open directory: %s\n", directoryPath);
        return -1;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        printIndentation(indentationLevel);
        printf("%s\n", entry->d_name);

        if (entry->d_type == DT_DIR && (isRecursive || isAbsoluteRecursive)) {
            char subdirectoryPath[MAX_PATH_LENGTH];
            snprintf(subdirectoryPath, sizeof(subdirectoryPath), "%s/%s", directoryPath, entry->d_name);
            printf("\n");
            printIndentation(indentationLevel);
            printf("->\n");
            gls((char *[]){argv[0], subdirectoryPath, argv[2]}, indentationLevel + 1, isAbsoluteRecursive);
            printIndentation(indentationLevel);
            printf("<-\n");
        }
    }

    closedir(directory);

    return 0;
}


int flag(char *parameter) {
    int isRecursive = 0;
    if (strcmp(parameter, "-r") == 0 ||
            strcmp(parameter, "-rr") == 0) isRecursive = 1;

    return isRecursive;
}

int isRecursive(char **argv) {
    int recursive = contains(argv, "-r");

    return recursive;
}

#endif //G_SHELL_LIGHT_GLS_HPP
