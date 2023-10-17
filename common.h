//
// Created by Gregory Shipunov on 10/10/23.
//

#ifndef G_SHELL_LIGHT_COMMON_H
#define G_SHELL_LIGHT_COMMON_H

#include <string.h>
#include <stdio.h>

#define CMD_SIZE 100
#define ARG_SIZE 10
#define INIT_LINE_SIZE (CMD_SIZE * ARG_SIZE + ARG_SIZE)

/**
 * Check if the argument is in the provided vector of arguments
 * @param args vector of arguments
 * @param argument argument which is to be found
 * @return 1 if the argument is in the list, 0 otherwise
 */
int contains(char commands[ARG_SIZE][CMD_SIZE], char argument[CMD_SIZE]) {
    int contains = 0;
    for (int i = 0; i < ARG_SIZE && strlen(commands[i]) > 0; i++) {
        if (strcmp(commands[i], argument) == 0) {
            contains = 1;
            break;
        }
    }

    return contains;
}

#endif //G_SHELL_LIGHT_COMMON_H
