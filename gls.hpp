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

#define CURRENT_DIRECTORY "."
#define CONTENT_LIST_SIZE 1024

int gls(const char *directoryName, char **contentList) {

    std::cout << directoryName << std::endl;
    if (directoryName == nullptr) directoryName = CURRENT_DIRECTORY;

    DIR *directory = opendir(directoryName);
    struct dirent *contentEntry = readdir(directory);
    int i = 0;

    while (contentEntry != nullptr) {
        std::cout << contentEntry->d_name << "\n";
        contentEntry = readdir(directory);
    }

    return 0;
}

int glsRun(char **argv, char **dirContents) {
    if (argv[1] != nullptr) return ERROR;
    std::cout << "gls is running\n";

    gls(argv[0] , dirContents);

    return 0;
}

#endif //G_SHELL_LIGHT_GLS_HPP
