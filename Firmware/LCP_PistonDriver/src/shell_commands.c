#include "shell_commands.h"
#include "memory.h"
#include "sysinfo.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

bool kv_store_write(const char *key, const void *val, uint32_t len) {
  // Stub
  return true;
}

bool cli_get(const char *key, const void *val, uint32_t len) {
    float temp_f = 0.0f;
    uint16_t temp_u16 = 0u;
    char t_str[64]; 
    memset(t_str, 0, 64);

    if(strncmp(key, "firmware", 8)==0)
    {
      shell_put_line(FIRMWARE);
      return true;
    }
    
    if(strncmp(key, "sys_id", 6)==0)
    {
      shell_put_line(SYS_ID);
      return true;
    }

    if(strncmp(key, "vset", 4) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_VOL_Setpoint());
      shell_put_line(t_str);\
      return true;
    }

    
    if(strncmp(key, "vtotal", 6) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_VOL_Total());
      shell_put_line(t_str);
      return true;
    }
    
    if(strncmp(key, "vsmall", 6) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_VOL_Small_Piston());
      shell_put_line(t_str);
      return true;
    }
    
    if(strncmp(key, "vlarge", 6) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_VOL_Large_Piston());
      shell_put_line(t_str);
      return true;
    }
    
    if(strncmp(key, "vhouse", 6) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_VOL_Housing());
      shell_put_line(t_str);
      return true;
    }

    
    if(strncmp(key, "asmall", 6) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_AREA_Small_Piston());
      shell_put_line(t_str);
      return true;
    }
    
    if(strncmp(key, "alarge", 6) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_AREA_Large_Piston());
      shell_put_line(t_str);
      return true;
    }
        
    if(strncmp(key, "lset", 4) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_LEN_Setpoint());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "ltotal", 6) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_LEN_Total());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "lsmall", 6) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_LEN_Small_Piston());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "llarge", 6) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_LEN_Large_Piston());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "pmin", 4) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_PST_Position_Min());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "pmax", 4) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_PST_Position_Max());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "prate", 5) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_PST_Rate());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "tdir", 4) == 0)
    {
      sprintf(t_str, "%i", MEM_Get_TRV_Direction());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "teng", 4) == 0)
    {
      sprintf(t_str, "%u", (uint8_t) MEM_Get_TRV_Engaged());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "tzero", 5) == 0)
    {
      sprintf(t_str, "%u", (uint8_t) MEM_Get_TRV_Zero());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "tfull", 5) == 0)
    {
      sprintf(t_str, "%u", (uint8_t) MEM_Get_TRV_Full());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "tmin", 4) == 0)
    {
      sprintf(t_str, "%u", (uint8_t) MEM_Get_TRV_Min());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "tmax", 4) == 0)
    {
      sprintf(t_str, "%u", (uint8_t) MEM_Get_TRV_Max());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "pidp", 4) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_PID_Coeff_P());
      shell_put_line(t_str);
      return true;
    }


    if(strncmp(key, "pidi", 4) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_PID_Coeff_I());
      shell_put_line(t_str);
      return true;
    }


    if(strncmp(key, "pidd", 4) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_PID_Coeff_D());
      shell_put_line(t_str);
      return true;
    }


    if(strncmp(key, "pidu", 4) == 0)
    {
      sprintf(t_str, "%u", (uint8_t) MEM_Get_PID_Used());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "year", 4) == 0)
    {
      sprintf(t_str, "%u", SYS_Get_YearBuilt);
      shell_put_line(t_str);
      return true;
    }


    if(strncmp(key, "user", 4) == 0)
    {
      SYS_Get_UserName(t_str);
      shell_put_line(t_str);
      return true;
    }

    
    if(strncmp(key, "level", 5) == 0)
    {
      // sprintf(t_str, "%f", MEM_Get_PID_Coeff_P());
      shell_put_line(t_str);
      return true;
    }

    char user[24];
    if(SYS_Is_Admin() != true)
    {
      return false;
    }

    if(strncmp(key, "utest", 5) == 0)
    {
      // sprintf(t_str, "%f", MEM_Get_PID_Coeff_P());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "udir", 5) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_TRV_Direction());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "ueng", 5) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_TRV_Engaged());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "urate", 5) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_PST_Rate());
      shell_put_line(t_str);
      return true;
    }


    if(strncmp(key, "ulset", 5) == 0)
    {
      sprintf(t_str, "%f", MEM_Get_PST_Position_Max());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "serial", 5) == 0)
    {
      // sprintf(t_str, "%f", MEM_Get_PID_Coeff_P());
      SYS_Get_SerialNumber(t_str);
      shell_put_line(t_str);
      return true;
    }
    
    return false;
}

bool cli_set(const char *key, const void *val, uint32_t len) {
  
    if(strncmp(key, "vset", 4) == 0)
    {
      MEM_Set_VOL_Setpoint(atof(val));
      return true;
    }

    if(strncmp(key, "lset", 4) == 0)
    {
      MEM_Set_LEN_Setpoint(atof(val));
      return true;
    }

    if(strncmp(key, "pidp", 4) == 0)
    {
      MEM_Set_PID_Coeff_P(float(val));
      return true;
    }

    if(strncmp(key, "pidi", 4) == 0)
    {
      MEM_Set_PID_Coeff_I(float(val));
      return true;
    }

    if(strncmp(key, "pidd", 4) == 0)
    {
      MEM_Set_PID_Coeff_D(float(val));
      return true;
    }

    if(strncmp(key, "pidu", 4) == 0)
    {
      MEM_Set_PID_Used((bool)atoi(val));
      return true;
    }

    if(strncmp(key, "level", 5) == 0)
    {
      /** @todo Set Logging level */
      return true;
    }

    if(strncmp(key, "reset", 5) == 0)
    {
      /** @todo Reset the board */
      return true;
    }


    if(SYS_Is_Admin() != true)
    {
      return false;
    }

    if(strncmp(key, "utest", 5) == 0)
    {
      /** Not currently implemented */
      return true;
    }

    if(strncmp(key, "udir", 4) == 0)
    {
      MEM_Set_Travel_Direction((uint8_t)atoi(val));
      return true;
    }

    if(strncmp(key, "ueng", 4) == 0)
    {
      MEM_Set_Travel_Direction((uint8_t)atoi(val));
      return true;
    }

    if(strncmp(key, "urate", 5) == 0)
    {
      /** Not currently implemented */
      return true;
    }

    if(strncmp(key, "ulmax", 5) == 0)
    {
      MEM_Set_PST_Position_Max(atof(val));
      return true;
    }
    
    if(strncmp(key, "year", 4) == 0)
    {
      SYS_Set_YearBuilt(val);
      return true;
    }

    if(strncmp(key, "serial", 6) == 0)
    {
      SYS_Set_SerialNumber(val);
      return true;
    }

    if(strncmp(key, "factory", 7) == 0)
    {
      /** @todo Factory reset call */
      return true;
    }
    return false;
    
    
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

bool cli_cmd_get_sernum(const char *key, const void *val, uint32_t len) {

}

bool cli_cmd_get_id(const char *key, const void *val, uint32_t len) {

}

bool cli_cmd_get_firmware(const char *key, const void *val, uint32_t len) {
  shell_put_line(FIRMWARE);
}

bool cli_cmd_get_rerport(const char *key, const void *val, uint32_t len) {

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
  {"", NULL, "***System Information***"},
  {"ser", cli_cmd_get_sernum, "Return serial number"},
  {"id", cli_cmd_get_id,"Return system id"},
  {"ver", cli_cmd_get_firmware, "Return firmware version"},
  {"report", cli_cmd_get_report, "Return System Report"},
  {"", NULL, "*** Other ***"},
  {"LED", cli_cmd_led_state, "Set LED State"},
  {"restart", cli_cmd_restart, "Restart micro"},
  {"hello", cli_cmd_hello, "Say hello"},
  {"help", shell_help_handler, "Lists all commands"},
};


static const sGetCommand s_shell_get_commands[] = {
  {"vset", NULL, "Get desired volume setpoint (in^3/float)"},
  {"vtotal", NULL, "Get current total volume (in^3/float)"},
  {"lset", NULL, "Get piston length setpoint(in/float)"},
  
}
const sShellCommand *const g_shell_commands = s_shell_commands;
const size_t g_num_shell_commands = ARRAY_SIZE(s_shell_commands);