/**********************************************************************************
* @Title       :   Module Name
* @Filename    :   sysinfo.h
* @Author      :   Matt Casari
* @Origin Date :   6/30/21
* @Version     :   1.0.0
* @Compiler    :   IAR, GCC
* @Target      :   
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
/**********************************************************************************
* Build Log
* Data    | Initials |  Description
*--------------------------------
* 6/30/21 |    MJC   | Initial design, conforming to MAP Version 0x01
*********************************************************************************/
#ifndef SYSINFO_H
#define SYSINFO_H


/**********************************************************************************
* Includes
*********************************************************************************/
#include <stdint.h>
#include <stdbool.h>
/**********************************************************************************
* Configuration Constants
*********************************************************************************/

///**********************************************************************************
//* MACROS
//*********************************************************************************/
///** Remove STATIC and PERSISTENT values if running TEST */
///** Add the actual values if running release */
//#ifdef TEST
//#ifndef STATIC
//#define STATIC
//#endif
//#ifndef PERSISTENT
//#define PERSISTENT
//#endif
//#else

#ifndef STATIC
#define STATIC static
#endif

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#define PERSISTENT __persistent
#elif defined(__GNUC__)
#define PERSISTENT __attribute__((section (".persistent")))
#endif

/**********************************************************************************
* Typdefs
*********************************************************************************/


/**********************************************************************************
* Variables
*********************************************************************************/

/**********************************************************************************
* Function Prototypes
*********************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif
void SYS_Set_SerialNumber(char* sernum);
uint8_t SYS_Get_SerialNumber(char* sernum);
void SYS_Set_YearBuilt(uint16_t year);
uint16_t SYS_Get_YearBuilt(void);
void SYS_Set_UserName(char *user);
uint8_t SYS_Get_UserName(char *user);
bool SYS_Is_Admin(void);
/**********************************************************************************
* Unit Test Variables & Static Prototpyes
*********************************************************************************/
#ifdef TEST
#ifndef DOXYGEN_IGNORE_THIS

#endif // DOXYGEN_IGNORE_THIS
#endif



#ifdef __cplusplus
} // extern "C"
#endif

#endif // SYSINFO_H
