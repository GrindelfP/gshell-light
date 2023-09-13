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

#include "mainHeader.hpp"

void fileCreate() {
    int fd = open("bb", O_CREAT | O_WRONLY, 0666);
    write(fd, "Hello there!", 12);
    close(fd);
}

#endif //G_SHELL_LIGHT_FILE_CONTROL_HPP
