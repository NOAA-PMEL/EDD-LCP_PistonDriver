/**********************************************************************************
* @Title       :   LCP Piston Control Interface
* @Filename    :   ControlInterface.h
* @Author      :   Matt Casari
* @Origin Date :   1/16/2021
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
#ifndef _CONTROLINTERFACE_H
#define _CONTROLINTERFACE_H



/**********************************************************************************
* Includes
*********************************************************************************/
#include <stdint.h>
/**********************************************************************************
* Configuration Constants
*********************************************************************************/

/**********************************************************************************
* MACROS
*********************************************************************************/
/** Remove STATIC and PERSISTENT values if running TEST */
/** Add the actual values if running release */
#ifdef TEST
#ifndef STATIC
#define STATIC  
#endif
#ifndef PERSISTENT
#define PERSISTENT
#endif
#else
#ifndef STATIC
#define STATIC  static
#endif
#ifndef PERSISTENT
#define PERSISTENT __persistent 
#endif
#endif


#define FRAME_START_CHAR    (0x22)

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
void CIF_FrameDecoder(uint8_t *block);

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

#endif // _CONTROLINTERFACE_H
