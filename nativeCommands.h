/*
 *    ____ ____  _
 *  / ___/ ___|| |
 * | |  _\___ \| |
 * | |_| |___) | |___
 *  \____|____/|_____|
 *
 * GShellLight. List of native GShell commands
 *
 * Author: Grindelf P.
 * Created on 2023-10-04.
 *
 */

#ifndef G_SHELL_LIGHT_NATIVE_COMMANDS_HPP
#define G_SHELL_LIGHT_NATIVE_COMMANDS_HPP

#define NATIVE_CMDS_SIZE 2

#define gls_name "gls"
#define gcat_name "gcat"
#define GLS strcmp(command, gls_name) == 0
#define GCAT strcmp(command, gcat_name) == 0

char nativeCommands[NATIVE_CMDS_SIZE][CMD_SIZE] = {"gls", "gcat"};

#endif //G_SHELL_LIGHT_NATIVE_COMMANDS_HPP
