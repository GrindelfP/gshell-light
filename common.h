//
// Created by Gregory Shipunov on 10/10/23.
//

#ifndef G_SHELL_LIGHT_COMMON_H
#define G_SHELL_LIGHT_COMMON_H

#include <cstring>

int contains(char **array, char *element) {
    int i = 0;
    while (array[i] != nullptr) {
        if (strcmp(array[i], element) == 0) {
            return 1;
        }
        i++;
    }
    return 0;
}

#endif //G_SHELL_LIGHT_COMMON_H
