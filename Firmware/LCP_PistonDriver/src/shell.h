#ifndef _SHELL_H
#define _SHELL_H

/**!license Adapted from \
 * https://github.com/memfault/interrupt/tree/master/example/firmware-shell 
 * 
 * 
 * */


#include <stddef.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define SHELL_RX_BUFFER_SIZE    ( 256 )
#define SHELL_MAX_ARGS          ( 16 )
#define SHELL_PROMPT            ( "shell>")

typedef struct ShellCommand {
    const char *command;
    int ( *handler ) ( int argc, char *argv[] );
    const char *help;
} sShellCommand;

extern const sShellCommand *const g_shell_commands;
extern const size_t g_num_shell_commands;

typedef struct ShellImpl {
    /**! Function to call whenever a char needs to be sent out */
    int ( *send_char ) ( char c );
}sShellImpl;

/**! Initializes the shell, to be called early at boot */
void shell_boot( const sShellImpl *impl );

/**! Call when a char is received.  Char is synchronously processed */
void shell_receive_char( char c );

/**! Print help command */
int shell_help_handler( int argc, char *argv[] );

/**! Print a line then a newline */
void shell_put_line( const char *str );

#endif // _SHELL_H
