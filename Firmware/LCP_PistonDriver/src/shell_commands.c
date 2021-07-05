#include "shell_commands.h"
#include "memory.h"
#include "sysinfo.h"
#include "logging.h"
#include "DRV8874.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

bool kv_store_write(const char *key, const void *val, uint32_t len) {
  // Stub
  return true;
}

bool cli_get(const char *key, const void *val, uint32_t len) {
    char t_str[64]; 
    memset(t_str, 0, 64);

    if(strncmp(key, "firmware", 8)==0)
    {
      Log.Debug("get firmware called");
      shell_put_line(FIRMWARE);
      return true;
    }
    
    if(strncmp(key, "sys_id", 6)==0)
    {
      Log.Debug("get sys_id called");
      shell_put_line(SYS_ID);
      return true;
    }

    if(strncmp(key, "vset", 4) == 0)
    {
      Log.Debug("get vset called");
      sprintf(t_str, "%f", MEM_Get_VOL_Setpoint());
      shell_put_line(t_str);\
      return true;
    }

    
    if(strncmp(key, "vtotal", 6) == 0)
    {
      Log.Debug("get vtotal called");
      sprintf(t_str, "%f", MEM_Get_VOL_Total());
      shell_put_line(t_str);
      return true;
    }
    
    if(strncmp(key, "vsmall", 6) == 0)
    {
      Log.Debug("get vsmall called");
      sprintf(t_str, "%f", MEM_Get_VOL_Small_Piston());
      shell_put_line(t_str);
      return true;
    }
    
    if(strncmp(key, "vlarge", 6) == 0)
    {
      Log.Debug("get vlarge called");
      sprintf(t_str, "%f", MEM_Get_VOL_Large_Piston());
      shell_put_line(t_str);
      return true;
    }
    
    if(strncmp(key, "vhouse", 6) == 0)
    {
      Log.Debug("get vhouse called");
      sprintf(t_str, "%f", MEM_Get_VOL_Housing());
      shell_put_line(t_str);
      return true;
    }

    
    if(strncmp(key, "asmall", 6) == 0)
    {
      Log.Debug("get asmall called");
      sprintf(t_str, "%f", MEM_Get_AREA_Small_Piston());
      shell_put_line(t_str);
      return true;
    }
    
    if(strncmp(key, "alarge", 6) == 0)
    {
      Log.Debug("get alarge called");
      sprintf(t_str, "%f", MEM_Get_AREA_Large_Piston());
      shell_put_line(t_str);
      return true;
    }
        
    if(strncmp(key, "lset", 4) == 0)
    {
      Log.Debug("get lset called");
      sprintf(t_str, "%f", MEM_Get_LEN_Setpoint());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "ltotal", 6) == 0)
    {
      Log.Debug("get ltotal called");
      sprintf(t_str, "%f", MEM_Get_LEN_Total());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "lsmall", 6) == 0)
    {
      Log.Debug("get lsmall called");
      sprintf(t_str, "%f", MEM_Get_LEN_Small_Piston());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "llarge", 6) == 0)
    {
      Log.Debug("get llarge called");
      sprintf(t_str, "%f", MEM_Get_LEN_Large_Piston());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "pmin", 4) == 0)
    {
      Log.Debug("get pmin called");
      sprintf(t_str, "%f", MEM_Get_PST_Position_Min());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "pmax", 4) == 0)
    {
      Log.Debug("get pmax called");
      sprintf(t_str, "%f", MEM_Get_PST_Position_Max());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "prate", 5) == 0)
    {
      Log.Debug("get prate called");
      sprintf(t_str, "%f", MEM_Get_PST_Rate());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "tdir", 4) == 0)
    {
      Log.Debug("get tdir called");
      sprintf(t_str, "%i", MEM_Get_TRV_Direction());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "teng", 4) == 0)
    {
      Log.Debug("get teng called");
      sprintf(t_str, "%u", (uint8_t) MEM_Get_TRV_Engaged());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "tzero", 5) == 0)
    {
      Log.Debug("get tzero called");
      sprintf(t_str, "%u", (uint8_t) MEM_Get_TRV_Zero());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "tfull", 5) == 0)
    {
      Log.Debug("get tfull called");
      sprintf(t_str, "%u", (uint8_t) MEM_Get_TRV_Full());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "tmin", 4) == 0)
    {
      Log.Debug("get tmin called");
      sprintf(t_str, "%u", (uint8_t) MEM_Get_TRV_Min());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "tmax", 4) == 0)
    {
      Log.Debug("get tmax called");
      sprintf(t_str, "%u", (uint8_t) MEM_Get_TRV_Max());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "pidp", 4) == 0)
    {
      Log.Debug("get pidp called");
      sprintf(t_str, "%f", MEM_Get_PID_Coeff_P());
      shell_put_line(t_str);
      return true;
    }


    if(strncmp(key, "pidi", 4) == 0)
    {
      Log.Debug("get pidi called");
      sprintf(t_str, "%f", MEM_Get_PID_Coeff_I());
      shell_put_line(t_str);
      return true;
    }


    if(strncmp(key, "pidd", 4) == 0)
    {
      Log.Debug("get pidd called");
      sprintf(t_str, "%f", MEM_Get_PID_Coeff_D());
      shell_put_line(t_str);
      return true;
    }


    if(strncmp(key, "pidu", 4) == 0)
    {
      Log.Debug("get pidu called");
      sprintf(t_str, "%u", (uint8_t) MEM_Get_PID_Used());
      shell_put_line(t_str);
      return true;
    }

    if(strncmp(key, "year", 4) == 0)
    {
      Log.Debug("get year called");
      sprintf(t_str, "%u", SYS_Get_YearBuilt());
      shell_put_line(t_str);
      return true;
    }


    if(strncmp(key, "user", 4) == 0)
    {
      Log.Debug("get user called");
      SYS_Get_UserName(t_str);
      shell_put_line(t_str);
      return true;
    }

    
    if(strncmp(key, "level", 5) == 0)
    {
      Log.Debug("get level called");
      sprintf(t_str, "level= %u", Log.Get());
      // sprintf(t_str, "%f", MEM_Get_PID_Coeff_P());
      
//      shell_put_line(t_str);
      return true;
    }

//    char user[24];
    if(SYS_Is_Admin() == true)
    {
      
      
      Log.Debug("Checking ADMIN functions");
      
      if(strncmp(key, "utest", 5) == 0)
      {
        Log.Debug("get utest called");
        // sprintf(t_str, "%f", MEM_Get_PID_Coeff_P());
        shell_put_line(t_str);
        return true;
      }

      if(strncmp(key, "udir", 5) == 0)
      {
        Log.Debug("get udir called");
        sprintf(t_str, "%i", MEM_Get_TRV_Direction());
        shell_put_line(t_str);
        return true;
      }

      if(strncmp(key, "ueng", 5) == 0)
      {
        Log.Debug("get ueng called");
        sprintf(t_str, "%u", MEM_Get_TRV_Engaged());
        shell_put_line(t_str);
        return true;
      }

      if(strncmp(key, "urate", 5) == 0)
      {
        Log.Debug("get urate called");
        sprintf(t_str, "%f", MEM_Get_PST_Rate());
        shell_put_line(t_str);
        return true;
      }


      if(strncmp(key, "ulset", 5) == 0)
      {
        Log.Debug("get ulset called");
        sprintf(t_str, "%f", MEM_Get_PST_Position_Max());
        shell_put_line(t_str);
        return true;
      }

      if(strncmp(key, "serial", 5) == 0)
      {
        Log.Debug("get serial called");
        SYS_Get_SerialNumber(t_str);
        shell_put_line(t_str);
        return true;
      }
    }
    sprintf(t_str, "Invalid get function %s called", key);
    Log.Error(t_str);
    return false;
}

bool cli_set(const char *key, const void *val, uint32_t len) {
  
    char v_str[62];
    memset(v_str, 0, 64);
    if(Log.Get() == LOG_DEBUG)
    {
      sprintf(v_str, "value= %s", (char*)val);
    }
  
    if(strncmp(key, "vset", 4) == 0)
    {
      Log.Debug("set vset called");
      Log.Debug(v_str);
      MEM_Set_VOL_Setpoint(atof(val));
      return true;
    }

    if(strncmp(key, "lset", 4) == 0)
    {
      Log.Debug("set lset called");
      Log.Debug(v_str);
      MEM_Set_LEN_Setpoint(atof(val));
      return true;
    }

    if(strncmp(key, "pidp", 4) == 0)
    {
      Log.Debug("set pidp called");
      Log.Debug(v_str);
      MEM_Set_PID_Coeff_P(atof(val));
      return true;
    }

    if(strncmp(key, "pidi", 4) == 0)
    {
      Log.Debug("set pidi called");
      Log.Debug(v_str);
      MEM_Set_PID_Coeff_I(atof(val));
      return true;
    }

    if(strncmp(key, "pidd", 4) == 0)
    {
      Log.Debug("set pidd called");
      Log.Debug(v_str);
      MEM_Set_PID_Coeff_D(atof(val));
      return true;
    }

    if(strncmp(key, "pidu", 4) == 0)
    {
      Log.Debug("set pidu called");
      Log.Debug(v_str);
      MEM_Set_PID_Used((bool)atoi(val));
      return true;
    }

    if(strncmp(key, "level", 5) == 0)
    {
      Log.Debug("set level called");
      Log.Debug(v_str);
      /** @todo Set Logging level */
      Log.Set((eLogging_t)atoi(val));
      Log.Debug("Debug Active");
      Log.Warning("Warning Active");
      Log.Error("Error Active");
      return true;
    }

    if(strncmp(key, "reset", 5) == 0)
    {
      Log.Debug("set reset called");
      Log.Debug(v_str);
      /** @todo Reset the board */
      return true;
    }
    if(strncmp(key, "user", 4) == 0)
    {
      Log.Debug("set user called");
      Log.Debug(v_str);
      /** Set the username */
      SYS_Set_UserName((char*) val);
      
      return true;
    } 


    if(SYS_Is_Admin() == true)
    {        
      if(strncmp(key, "utest", 5) == 0)
      {
        Log.Debug("set utest called");
        Log.Debug(v_str);
        /** Not currently implemented */
        return true;
      }

      if(strncmp(key, "udir", 4) == 0)
      {
        Log.Debug("set udir called");
        Log.Debug(v_str);
        MEM_Set_Travel_Direction((uint8_t)atoi(val));
        return true;
      }

      if(strncmp(key, "ueng", 4) == 0)
      {
        Log.Debug("set ueng called");
        Log.Debug(v_str);
        MEM_Set_Travel_Direction((uint8_t)atoi(val));
        return true;
      }

      if(strncmp(key, "urate", 5) == 0)
      {
        Log.Debug("set urate called");
        Log.Debug(v_str);
        /** Not currently implemented */
        return true;
      }

      if(strncmp(key, "ulmax", 5) == 0)
      {
        Log.Debug("set ulmax called");
        Log.Debug(v_str);
        MEM_Set_PST_Position_Max(atof(val));
        return true;
      }
      
      if(strncmp(key, "year", 4) == 0)
      {
        Log.Debug("set year called");
        Log.Debug(v_str);
        SYS_Set_YearBuilt((uint16_t) atoi(val));
        return true;
      }

      if(strncmp(key, "serial", 6) == 0)
      {
        Log.Debug("set serial called");
        Log.Debug(v_str);
        SYS_Set_SerialNumber((char*)val);
        return true;
      }

      if(strncmp(key, "factory", 7) == 0)
      {
        Log.Debug("set factory called");
        Log.Debug(v_str);
        /** @todo Factory reset call */
        return true;
      }
    }
    
    sprintf(v_str, "Invalid set function %s called", key);
    Log.Error(v_str);
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


int cli_cmd_get_id(int argc, char *argv[]){
  shell_put_line(SYS_ID);
  return 1;
}

int cli_cmd_get_firmware(int argc, char *argv[]){
  shell_put_line(FIRMWARE);
  return 1;
}

int cli_cmd_get_report(int argc, char *argv[]){
  char report[64];
  char t_str[16];
  memset(report, 0, 64);
  // Serial Number:     value
  // System ID:         value
  // Firmware Version:  value
  // vset(in3):         value
  // Log Level:         value
  shell_put_line("********* SYSTEM REPORT *********");
  sprintf(report, "System ID\t\t: %s", SYS_ID);
  shell_put_line(report);
  SYS_Get_SerialNumber(t_str);
  sprintf(report, "Serial Number\t\t: %s", t_str);
  shell_put_line(report);
  sprintf(report, "Firmware Version\t: %s", FIRMWARE);
  shell_put_line(report);
  sprintf(report, "Year Built\t\t: %u", SYS_Get_YearBuilt());
  shell_put_line(report);
  sprintf(report, "Log Level\t\t: %u", Log.Get());
  shell_put_line(report);
  
  return 1;
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

int cli_get_ser(int argc, char *argv[]){

  return true;
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
  {"ser", cli_get_ser, "Get Serial Number"},
  {"id", cli_cmd_get_id,"Return system id"},
  {"ver", cli_cmd_get_firmware, "Return firmware version"},
  {"report", cli_cmd_get_report, "Return System Report"},
  {"", NULL, "*** Other ***"},
  {"LED", cli_cmd_led_state, "Set LED State"},
//  {"restart", cli_cmd_restart, "Restart micro"},
  {"hello", cli_cmd_hello, "Say hello"},
  {"help", shell_help_handler, "Lists all commands"},
};


//static const sGetCommand s_shell_get_commands[] = {
//  {"vset", NULL, "Get desired volume setpoint (in^3/float)"},
//  {"vtotal", NULL, "Get current total volume (in^3/float)"},
//  {"lset", NULL, "Get piston length setpoint(in/float)"},
//  
//};
const sShellCommand *const g_shell_commands = s_shell_commands;
const size_t g_num_shell_commands = ARRAY_SIZE(s_shell_commands);