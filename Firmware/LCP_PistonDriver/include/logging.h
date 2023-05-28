/**********************************************************************************
 * @Title       :   Piston Control
 * @Filename    :   piston.h
 * @Author      :   Matt Casari
 * @Origin Date :   1/12/2021
 * @Version     :   1.0.0
 * @Compiler    :   IAR, GCC
 * @Target      :   MSP430FR5989
 * @Notes       :   None
 * @Bugs        :   No known bugs
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights 
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *********************************************************************************/

#ifndef _LOGGING_H
#define _LOGGING_H

/**********************************************************************************
 * Includes
 *********************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "config.h"
#include "encoder.h"
#include "DRV8874.h"

/**********************************************************************************
 * Configuration Constants
 *********************************************************************************/
#define LOG_BUFFER_SIZE ( 256 )

/**********************************************************************************
 * Typdefs
 *********************************************************************************/
/**
 * Log Level Options
 */
typedef enum eLogging {
    LOG_NONE = 0,       /**< Log Nothing */
    LOG_DEBUG = 1,      /**< Log Everything */
    LOG_WARNING = 2,    /**< Log Warning & Errors */
    LOG_ERROR = 3       /**< Log Errors only */
}eLogging_t;


typedef void (*logFunc)(const char *val);
typedef void (*logSet)(const eLogging_t logtype);
typedef eLogging_t (*logGet)(void);
typedef struct sLog {
    logFunc Debug;
    logFunc Warning;
    logFunc Error;
    logSet Set;
    logGet Get;
}sLog_t;


/**********************************************************************************
 * Function Prototypes
 *********************************************************************************/
extern sLog_t Log;

/**********************************************************************************
 * Function Prototypes
 *********************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void LOG_Init(void);


/**********************************************************************************
 * Unit Test Variables & Static Prototpyes
 *********************************************************************************/
#ifdef TEST
#ifdef DOXYGEN_IGNORE_THIS
#endif // DOXYGEN_IGNORE_THIS
#endif


#ifdef __cplusplus
} // extern "C"
#endif

#endif // _LOGGING_H
