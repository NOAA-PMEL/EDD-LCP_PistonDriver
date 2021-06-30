#include "logging.h"


#define INCLUDE_CONSOLE
#include "bsp.h"

sLog_t Log;

STATIC eLogging_t LogLevel = LOG_NONE;

STATIC char sendstr[256];

void LOG_Debug(const char *data)
{   
    if( LogLevel == LOG_Debug)
    {
        BSP_CNSL_puts("DEBUG: ");
        BSP_CNSL_puts(data);
    }
    LOG_Log(data, LOG_DEBUG);
}

void LOG_Warning(const char *data)
{
    if( (LogLevel == LOG_Debug) || (LogLevel == LOG_Warning) )
    {
        BSP_CNSL_puts("WARNING: ");
        BSP_CNSL_puts(data);
    }
}

void LOG_Error(const char *data)
{
    if( (LogLevel >= LOG_Debug) && (LogLevel <= LOG_Error))
    {
        BSP_CNSL_puts("ERROR: ");
        BSP_CNSL_puts(data);
    }
}

void LOG_SetLevel(eLogging_t type)
{
    LogLevel = type;
}

eLogging_t LOG_GetLevel(void)
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
}