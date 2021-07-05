#include "logging.h"


//#define INCLUDE_CONSOLE
#include <bsp/bsp.h>

sLog_t Log;

STATIC eLogging_t LogLevel = LOG_NONE;

STATIC char sendstr[256];

STATIC void LOG_Debug(const char *data)
{   
    if( LogLevel == LOG_DEBUG)
    {
        BSP_CNSL_puts("DEBUG: ");
        BSP_CNSL_puts((char*)data);
        BSP_CNSL_puts("\r\n");
    }
}

STATIC void LOG_Warning(const char *data)
{
    if( (LogLevel == LOG_DEBUG) || (LogLevel == LOG_WARNING) )
    {
        BSP_CNSL_puts("WARNING: ");
        BSP_CNSL_puts((char*)data);
        BSP_CNSL_puts("\r\n");
    }
}

STATIC void LOG_Error(const char *data)
{
    if( (LogLevel >= LOG_DEBUG) && (LogLevel <= LOG_ERROR))
    {
        BSP_CNSL_puts("ERROR: ");
        BSP_CNSL_puts(data);
        BSP_CNSL_puts("\r\n");
    }
}

STATIC void LOG_SetLevel(eLogging_t type)
{
    LogLevel = type;
}

STATIC eLogging_t LOG_GetLevel(void)
{
    return LogLevel;
}


void LOG_Init(void)
{
    Log.Debug = &LOG_Debug;
    Log.Warning = &LOG_Warning;
    Log.Error = &LOG_Error;
    Log.Set = &LOG_SetLevel;
    Log.Get = &LOG_GetLevel;
    
    Log.Set(LOG_NONE);
}