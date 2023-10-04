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
#include "fileControl.hpp"
#include "gls.hpp"

int main() {

    while (true) {
        char buffer[CMD_SIZE];
        char *command[10];

        std::cout << "Enter the command (to stop enter 'exit'): ";
        std::cin.getline(buffer, CMD_SIZE);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        splitCommand(buffer, command);

        int streamRedirection = defineStreamRedirection(*command);

        int childPid = fork();

        if (!childPid) {
            if (streamRedirection > 0) {
                int f1 = open(command[streamRedirection + 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
                dup2(f1, 1);
                command[streamRedirection] = nullptr;
            }

            if (filterNativeCommands(command)) {
                std::cout << "Native\n";
                run(command, childPid);
            } else {
                execvp(command[0], command);
                std::cout << "Command not found!" << std::endl;
            }
        } else {
            wait(nullptr);
        }
    }

    return 0;
}

int run(char **commands, int childPid) {
    char *mainCommand = commands[0];
    if (strcmp(mainCommand, nativeCommands[0]) == 0) {
        std::cout << "gls is running\n";
        char *directoryContents[CONTENT_LIST_SIZE];
        int glsResult = gls(++commands);
        if (glsResult == ERROR) return error(--commands[0]);
    }

    return 0;
}

int error(char *commandName) {
    std::cout << "Error occurred while completing\n";

    return -1;
}
