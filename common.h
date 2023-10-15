//
// Created by Gregory Shipunov on 10/10/23.
//

#ifndef G_SHELL_LIGHT_COMMON_H
#define G_SHELL_LIGHT_COMMON_H

#include <string.h>

#define CMD_SIZE 100
#define ARG_SIZE 10

int contains(char **array, char *element) {
    int i = 0;
    while (array[i] != NULL) {
        if (strcmp(array[i], element) == 0) {
            return 1;
        }
        i++;
    }
    return 0;
}

#endif //G_SHELL_LIGHT_COMMON_H
