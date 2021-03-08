/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/


// Generated by FlowMeter Design Center: Fri Feb 26 16:05:04 PST 2021


/*******************************************************************************
* IMPORTANT: This is an autogenerated file. DO NOT MODIFY!
*******************************************************************************/



#ifndef ESICALIBRATION_H_
#define ESICALIBRATION_H_

#include <stdint.h>
#include <stdlib.h>
#ifndef TEST
#include <driverlib/driverlib.h>
#endif
#include "config.h"


// Recalibration defines and gRecalFlag bitfields definitions
#define DELTA_LEVEL 					10
#define VALID_RECALIBRATION				BIT0
#define RECALIBRATION_TIMEOUT			BIT1
#define INITIAL_AFE2_RECALIBRATION		BIT5
#define PERIODIC_AFE2_RECALIBRATION		BIT6



//define for gESIStatusFlag
#define VALID_SEPARATION_CH0 						BIT0
#define VALID_SEPARATION_CH1 						BIT1
#define VALID_SEPARATION_CH2 						BIT2
#define DAC_CALIBRATION_COMPLETE					BIT4


#define CHANNEL_0_SELECTION							0
#define CHANNEL_0_PPU_SELECT						ESI_AFE1_CHANNEL0_SELECT
#define CHANNEL_0_DAC1_UPPER_REGISTER				ESI_DAC1_REG0
#define CHANNEL_0_DAC1_LOWER_REGISTER				ESI_DAC1_REG1
#define CHANNEL_0_DAC2_UPPER_REGISTER				ESI_DAC2_REG0
#define CHANNEL_0_DAC2_LOWER_REGISTER				ESI_DAC2_REG1
#define CHANNEL_1_SELECTION							1
#define CHANNEL_1_PPU_SELECT						ESI_AFE1_CHANNEL1_SELECT
#define CHANNEL_1_DAC1_UPPER_REGISTER				ESI_DAC1_REG2
#define CHANNEL_1_DAC1_LOWER_REGISTER				ESI_DAC1_REG3
#define CHANNEL_1_DAC2_UPPER_REGISTER				ESI_DAC2_REG2
#define CHANNEL_1_DAC2_LOWER_REGISTER				ESI_DAC2_REG3
#define CHANNEL_2_SELECTION							0
#define PPU2_SOURCE									0
#define CHANNEL_2_PPU_SELECT						0
#define CHANNEL_2_DAC1_UPPER_REGISTER				0
#define CHANNEL_2_DAC1_LOWER_REGISTER				0
#define CHANNEL_2_DAC2_UPPER_REGISTER				0
#define CHANNEL_2_DAC2_LOWER_REGISTER				0





typedef struct fastParams {
        uint8_t channel0Enabled;
        uint8_t channel1Enabled;
        uint8_t channel2Enabled;
        uint16_t channel0StartingPoint;
        uint16_t channel1StartingPoint;
        uint16_t channel2StartingPoint;
        uint16_t range;
} fastParams;

typedef struct findDACParams {
        uint8_t channel0Enabled;
        uint8_t channel1Enabled;
        uint8_t channel2Enabled;
} findDACParams;




extern void ReCalScanIF(void);
extern void TSM_Auto_cal(void);
extern void Find_Noise_level(void);
extern void Set_DAC(void);



#endif /* ESICALIBRATION_H_ */
