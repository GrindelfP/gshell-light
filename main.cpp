/*
 *    ____ ____  _
 *  / ___/ ___|| |
 * | |  _\___ \| |
 * | |_| |___) | |___
 *  \____|____/|_____|
 *
 * GShellLight. A simple shell. The program takes a command from the user and executes it.
 * The program is terminated when the user enters the command 'exit'.
 *
 * Author: Grindelf P.
 * Created on 2023-09-13.
 *
 */

#include "mainHeader.hpp"
#include "commandControl.hpp"

int main() {

    while (true) {
        char buffer[CMD_SIZE];
        char* command[10];

        std::cout << "Enter the command (to stop enter 'exit'): ";
        std::cin.getline(buffer, CMD_SIZE);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        splitCommand(buffer, command);

        if (!fork()) {
            // execlp(buffer, buffer, NULL);
            execvp(command[0], command);
            std::cout << "Command not found!" << std::endl; // if command not found
        } else {
            wait(nullptr);
        }
    }

    return 0;
}
