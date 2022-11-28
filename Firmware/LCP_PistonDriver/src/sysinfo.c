#include "sysinfo.h"
#include "memory.h"
#include <string.h>


STATIC volatile uint8_t storage_ram[256];
STATIC char sys_serial_num[9];
STATIC char sys_user_name[13] = "guest";
STATIC uint16_t sys_year_built;
STATIC bool admin_mode = false;

void SYS_Set_SerialNumber(char* sernum)
{
    uint8_t len = strlen(sernum);
    if(len > 8){
        len = 8;
    }

    strncpy(sys_serial_num, sernum, len);
    MEM_Set_Serial_Number(sernum);
}

uint8_t SYS_Get_SerialNumber(char* sernum)
{
    strncpy(sernum, sys_serial_num, 8);
    return strlen(sernum);
}


void SYS_Set_YearBuilt(uint16_t year)
{
    if( (year > 2020) )
    {
        sys_year_built = year;
    }
    MEM_Set_YearBuilt(year);
}

uint16_t SYS_Get_YearBuilt(void)
{
    return sys_year_built;
}

void SYS_Set_UserName(char *user)
{
    uint8_t len = strlen(user);
    if(len > 12)
    {
        len = 12;
    }
    strncpy(sys_user_name, user, len);
    
    if(strcmp("admin", sys_user_name) == 0)
    {
        admin_mode = true;
    } else {
        admin_mode = false;
    }
}

uint8_t SYS_Get_UserName(char *user)
{
    strncpy(user, sys_user_name, 8);
    return strlen(user);
}

bool SYS_Is_Admin(void)
{
  if(strncmp("admin", sys_user_name,5)==0)
  {
    return true;
  }
  return false;
}
