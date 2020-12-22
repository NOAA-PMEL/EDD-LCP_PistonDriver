#include "shell_commands.h"


#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

bool kv_store_write(const char *key, const void *val, uint32_t len) {
  // Stub
  return true;
}

bool cli_get(const char *key, const void *val, uint32_t len) {
    float temp_f = 0.0f;
    uint16_t temp_u16 = 0u;
    char t_str[64]; 
    if(strncmp(key, "firmware", 8)==0)
    {
      shell_put_line(FIRMWARE);
    }
    
    if(strncmp(key, "motor", 5)==0) {
      if(strncmp(val, "current", 7) == 0) {
        temp_f = DRV8847_read_current();
        sprintf(t_str, "%0.7f", temp_f);
        shell_put_line(t_str);
      }
    }
    
    return true;
}

bool cli_set(const char *key, const void *val, uint32_t len) {
  
    if(strncmp(key, "motor", 8)==0)
    {
//      shell_put_line(FIRMWARE);
      if(strncmp(val,"fwd",3)==0)
      {
        DRV8874_forward();
      } else if(strncmp(val, "rev", 3) == 0) {
        DRV8874_reverse();
      } else if(strncmp(val, "stop", 4) == 0 ) {
        DRV8874_stop();
      } else {
        return false;
      }
    }
    
    return true;
    
    
}


bool led_set_state( const char *key, const void *val, uint32_t len) {
  eLED_t led;
  
  if(strncmp(key, "BLUE", 4) == 0) {
    led = LED_BLUE;
  } else if(strncmp(key, "GREEN", 5) == 0) {
    led = LED_GREEN;
  } else {
    return false;
  }
  
  if(strncmp(val, "ON", 2)==0) {
    BSP_LED_Set(led);
  } else if (strncmp(val, "OFF", 3) == 0) {
    BSP_LED_Clear(led);
  } else {
    return false;
  }
  
  return true;
}



int cli_cmd_kv_write(int argc, char *argv[]) {
  // We expect 3 arguments:
  // 1. Command name
  // 2. Key
  // 3. Value
  if (argc != 3) {
    shell_put_line("> FAIL,1");
    return 1;
  }

  const char *key = argv[1];
  const char *value = argv[2];

  bool result = kv_store_write(key, value, strlen(value));
  if (!result) {
    shell_put_line("> FAIL,2");
  }
  shell_put_line("> OK");
  return 0;
}

int cli_cmd_hello(int argc, char *argv[]) {
  shell_put_line("Hello World!");
  return 0;
}

int cli_cmd_led_state(int argc, char *argv[]) {
  /** Expect 3 arguments 
   * 1. Command Name
   * 2. LED Name (GREEN, BLUE)
   * 3. State (ON, OFF )
   */
  if (argc != 3) {
    shell_put_line("> FAIL,1");
    return 1;
  }

  const char *key = argv[1];
  const char *value = argv[2];

  bool result = led_set_state(key, value, strlen(value));
  if (!result) {
    shell_put_line("> FAIL,2");
  }
  shell_put_line("> OK");
  return 0;
}


int cli_cmd_get(int argc, char *argv[]) {
  /** Expect 3 arguments
    * 1. Command Name
    * 2. Key
    * 3. Value
    */
  if (argc < 2 || argc > 3) {
    shell_put_line("> FAIL,1");
    return 1;
  }

  const char *key = argv[1];
  const char *value = argv[2];

  bool result = cli_get(key, value, strlen(value));
  if (!result) {
    shell_put_line("> FAIL,2");
  }
  shell_put_line("> OK");
  return 0;
}

int cli_cmd_set(int argc, char *argv[]) {
  /** Expect 3 arguments
    * 1. Command Name
    * 2. Key
    * 3. Value
    */
  if (argc != 3) {
    shell_put_line("> FAIL,1");
    return 1;
  }

  const char *key = argv[1];
  const char *value = argv[2];

  bool result = cli_set(key, value, strlen(value));
  if (!result) {
    shell_put_line("> FAIL,2");
  }
  shell_put_line("> OK");
  return 0;
}

static const sShellCommand s_shell_commands[] = {
  {"get", cli_cmd_get, "Get value of register/variable"},
  {"set", cli_cmd_set, "Set value of register/variable"},
  {"kv_write", cli_cmd_kv_write, "Write a Key/Value pair"},
  {"LED", cli_cmd_led_state, "Set LED State"},
  {"hello", cli_cmd_hello, "Say hello"},
  {"help", shell_help_handler, "Lists all commands"},
};

const sShellCommand *const g_shell_commands = s_shell_commands;
const size_t g_num_shell_commands = ARRAY_SIZE(s_shell_commands);