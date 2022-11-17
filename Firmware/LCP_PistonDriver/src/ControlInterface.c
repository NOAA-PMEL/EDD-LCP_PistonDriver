/** @file "ControlInterface.c"
* @brief Embedded C File Template
*/

/**********************************************************************************
* Includes
*********************************************************************************/
#include "ControlInterface.h"
/**********************************************************************************
* Preprocessor Constants
*********************************************************************************/

/**********************************************************************************
* Preprocessor Macros
*********************************************************************************/

/**********************************************************************************
* Module Typedefs
*********************************************************************************/
typedef struct sControlCmd {
    const uint8_t startByte;    /**< Msg Start value */
    uint8_t page;           /**< Page # */
    uint8_t addr;           /**< Starting Address */
    uint8_t len;            /**< Length of message to send */
    uint8_t crc32[4];       /**< CRC32 from message */
}sControlCmd_t;
/**********************************************************************************
* Module Variable Definitions
*********************************************************************************/
sControlCmd_t incomingCmd = {
    .startByte = 0xCE
};
/**********************************************************************************
* Function Prototypes
*********************************************************************************/

/**********************************************************************************
* Function Definitions
*********************************************************************************/

/**********************************************************************************
* Function: FrameDecoder()
*
*//**
* \b Description:
* 
* This function decodes the I2C frames from the Controller.
* 
* Frame should be in the shape:
* | Start Char | Page # | Addr | Length | CRC[4] |
* ------------------------------------------------
* |    0x22    |  0x01  | 0x00 | 0xFF | Byte[0] | Byte[1] | Byte[2] | Byte[3] |
*  
* That frame would be 0x220100FF00112233
* Where the last 4 bytes are the CRC value applied
* across the message.
* 
* PRE-CONDITION: None
* 
* POST-CONDITION: None
* 
* @param None
* 
* @return void
* 
* \b Example:
* @code
* FrameDecoder
* @endcode
* 
* @see MOD_Init
*/
void CIF_FrameDecoder(uint8_t *block)
{
    #define MAX_FRAME_LEN (256+8)
    uint8_t frame[FRAME_LEN];
    while(1)
    {
        memset(frame, 0, FRAME_LEN);
        // while(frame[0] != FRAME_START_CHAR)
    }
}
/**********************************************************************************
* Function: MOD_Init()
*
*//**
* \b Description:
* 
* This function does XXX, YYY & ZZZ
* 
* PRE-CONDITION: None
* 
* POST-CONDITION: None
* 
* @param None
* 
* @return void
* 
* \b Example:
* @code
* MOD_Init();
* printf("Module is initialized!\n");
* @endcode
* 
* @see MOD_Init
*/
void MOD_Init(void)
{

}
