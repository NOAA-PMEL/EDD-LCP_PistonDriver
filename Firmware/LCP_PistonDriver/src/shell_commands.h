#include "shell.h"

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

// #include "bsp.h"
//#include "bsp_led.h"


bool kv_store_write(const char *key, const void *val, uint32_t len);
bool led_set_state( const char *key, const void *val, uint32_t len);

bool cli_get(const char *key, const void *val, uint32_t len);
bool cli_set(const char *key, const void *val, uint32_t len);

int cli_cmd_kv_write(int argc, char *argv[]);
int cli_cmd_debug(int argc, char *argv[]);
int cli_cmd_rev(int argc, char *argv[]);
int cli_cmd_fwd(int argc, char *argv[]);
int cli_cmd_stop(int argc, char *argv[]);
int cli_cmd_led_state(int argc, char *argv[]);
int cli_cmd_mem_dump( int argc, char *argv[]);
int cli_cmd_hello(int argc, char *argv[]);
int cli_cmd_get(int argc, char *argv[]);
int cli_cmd_set(int argc, char *argv[]);
int cli_get_ser(int argc, char *argv[]);
int cli_cmd_get_id(int argc, char *argv[]);
int cli_cmd_get_firmware(int argc, char *argv[]);
int cli_cmd_get_report(int argc, char *argv[]);

// extern const sShellCommand *const g_shell_commands; 
// extern const size_t g_num_shell_commands;