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
* IMPORTANT: Using FlowESI GUI "ESI Configuration Files Only" will overwrite 
* this file contents.
*******************************************************************************/


#include "bsp_esi.h"


ESI_AFE1_InitParams gAFE1Settings;


ESI_TSM_InitParams gTSMSettings;
ESI_PSM_InitParams gPSMSettings;
extern int16_t gRotationalCounter;
extern uint8_t  gESIStatusFlag;

__interrupt void ISR_ESCAN_IF(void);


void (*int_0_callback)(void);
void (*int_3_callback)(void);
void (*int_4_callback)(void);
void (*int_5_callback)(void);
void (*int_6_callback)(void);
void (*int_7_callback)(void);
void (*int_8_callback)(void);
void esiRegINTCallback(uint16_t int_num, void function(void));
void esiUnregINTCallback(uint16_t int_num);
void handleIncrementCount(void);
void handleDecrementCount(void);
void handleRotationDetection(void);





uint16_t gTSMTable[] = {
	0x0400, 					  // DAC=off, CA=off,  1xACLK
	0x202C + CHANNEL_0_SELECTION, // DAC=off, CA=off,  5xESICLK, excitation
	0x0404 + CHANNEL_0_SELECTION, // DAC=off, CA=off,  1xACLK
	0x0024 + CHANNEL_0_SELECTION, // DAC=off, CA=off,  1xESIFCLK  , delay tunable
	0x0024 + CHANNEL_0_SELECTION, // DAC=off, CA=off,  1xESIFCLK  , delay tunable
	0x0024 + CHANNEL_0_SELECTION, // DAC=off, CA=off,  1xESIFCLK  , delay tunable
	0x0024 + CHANNEL_0_SELECTION, // DAC=off, CA=off,  1xESIFCLK  , delay tunable
	0x0024 + CHANNEL_0_SELECTION, // DAC=off, CA=off,  1xESIFCLK  , delay tunable
	0xF134 + CHANNEL_0_SELECTION, // DAC=on,  CA=on,   31xESIFCLK,
	0x5974 + CHANNEL_0_SELECTION, // DAC=on,  CA=on,   OUTPUT LATCHES ENABLED,  12xESICLK
	0X0401 + CHANNEL_0_SELECTION, // DAC=off, CA=off,  1xACLCK, Internally damped
	0x202C + CHANNEL_1_SELECTION, // DAC=off, CA=off,  5xESICLK, excitation
	0x0404 + CHANNEL_1_SELECTION, // DAC=off, CA=off,  1xACLK
	0x0024 + CHANNEL_1_SELECTION, // DAC=off, CA=off,  1xESIFCLK  , delay tunable
	0x0024 + CHANNEL_1_SELECTION, // DAC=off, CA=off,  1xESIFCLK  , delay tunable
	0x0024 + CHANNEL_1_SELECTION, // DAC=off, CA=off,  1xESIFCLK  , delay tunable
	0x0024 + CHANNEL_1_SELECTION, // DAC=off, CA=off,  1xESIFCLK  , delay tunable
	0x0024 + CHANNEL_1_SELECTION, // DAC=off, CA=off,  1xESIFCLK  , delay tunable
	0xF134 + CHANNEL_1_SELECTION, // DAC=on,  CA=on,   31xESIFCLK,
	0x5974 + CHANNEL_1_SELECTION, // DAC=on,  CA=on,   OUTPUT LATCHES ENABLED,  12xESICLK
	0x0200, // stop
};


uint8_t gPSMTable[] = {
		0x00, 0x43, 0x0C, 0x89,
		0x04, 0x01, 0x88, 0x4B,
		0X42, 0X81, 0X08, 0X0D,
		0X80, 0X05, 0X4A, 0X09
 };





//******************************************************************************
//
//! \\brief Configures ESI Module
//!
//! This function is automatically generated.
//!
//! \\return None
//
//******************************************************************************
void esiConfig(void)
{
	// Init the status flag with non-runtime calibration
	gESIStatusFlag = 0;
	
	// Clear all AFE1 and AFE2 DAC values
	ESI_setAFE1DACValue(0, ESI_DAC1_REG0);
	ESI_setAFE1DACValue(0, ESI_DAC1_REG1);
	ESI_setAFE1DACValue(0, ESI_DAC1_REG2);
	ESI_setAFE1DACValue(0, ESI_DAC1_REG3);
	ESI_setAFE1DACValue(0, ESI_DAC1_REG4);
	ESI_setAFE1DACValue(0, ESI_DAC1_REG5);
	ESI_setAFE1DACValue(0, ESI_DAC1_REG6);
	ESI_setAFE1DACValue(0, ESI_DAC1_REG7);
	ESI_setAFE2DACValue(0, ESI_DAC2_REG0);
	ESI_setAFE2DACValue(0, ESI_DAC2_REG1);
	ESI_setAFE2DACValue(0, ESI_DAC2_REG2);
	ESI_setAFE2DACValue(0, ESI_DAC2_REG3);
	ESI_setAFE2DACValue(0, ESI_DAC2_REG4);
	ESI_setAFE2DACValue(0, ESI_DAC2_REG5);
	ESI_setAFE2DACValue(0, ESI_DAC2_REG6);
	ESI_setAFE2DACValue(0, ESI_DAC2_REG7);
	

	// Enable INT7 (increment on CNT0)
	ESI_setIFG7Source(ESI_IFG7_SOURCE_EVERY_COUNT_OF_CNT0);
	ESI_clearInterrupt(ESI_INTERRUPT_FLAG_ESICNT0_COUNT_INTERVAL);
	ESI_enableInterrupt(ESI_INTERRUPT_ESICNT0_COUNT_INTERVAL);
	esiRegINTCallback(7, &handleIncrementCount);


	// Enable INT4 (increment on CNT2)
	ESI_setIFG4Source(ESI_IFG4_SOURCE_EVERY_COUNT_OF_CNT2);
	ESI_clearInterrupt(ESI_INTERRUPT_FLAG_ESICNT2);
	ESI_enableInterrupt(ESI_INTERRUPT_FLAG_ESICNT2);
	esiRegINTCallback(4, &handleDecrementCount);


	// Enable INT5 (detects Q6 was set)
//	ESI_clearInterrupt(ESI_INTERRUPT_FLAG_Q6_BIT_SET);
//	ESI_enableInterrupt(ESI_INTERRUPT_Q6_BIT_SET);
//	esiRegINTCallback(5, &handleRotationDetection);



	ESI_setESICLKFQ(0x20);


	

	// Port pin selection for ESI, all channels for ESI should be selected, even
	// if not all ESICHx channels are used.
	// The un-used pin should be floating, not connected to any other circuit.

	GPIO_setAsPeripheralModuleFunctionInputPin(
			ESICHX_PORT,
			ESICH0_PIN | ESICH1_PIN,
			GPIO_TERNARY_MODULE_FUNCTION);
			
			
	// Disabling input buffer for COMP E can help reduce the leakage current of 
	// I/O.
	Comp_E_disableInputBuffer(COMP_E_BASE,
			COMP_E_INPUT8 | COMP_E_INPUT9 | COMP_E_INPUT10 |
			COMP_E_INPUT11| COMP_E_INPUT12| COMP_E_INPUT13 |
			COMP_E_INPUT14| COMP_E_INPUT15);		

	// Initialization of AFE1
	gAFE1Settings  = ESI_AFE1_INITPARAMS_DEFAULT;
	gAFE1Settings.excitationCircuitSelect = ESI_EXCITATION_CIRCUIT_DISABLED;
	gAFE1Settings.midVoltageGeneratorSelect = ESI_MID_VOLTAGE_GENERATOR_ENABLED;
	gAFE1Settings.sampleAndHoldSelect = ESI_SAMPLE_HOLD_VSS_BY_TSM;
	gAFE1Settings.inverterSelectOutputAFE1 = ESI_INVERTER_FOR_AFE1_ENABLE;
	ESI_AFE1_init(&gAFE1Settings);
	

	// Initialization of TSM with sampling frequency to ~2340 KHz for initial
	// calibration routines
	gTSMSettings = ESI_TSM_INITPARAMS_DEFAULT;
	gTSMSettings.startTriggerAclkDivider = ESI_TSM_START_TRIGGER_DIV_14;
	gTSMSettings.startTriggerSelection = ESI_TSM_START_TRIGGER_ACLK_OR_SOFTWARE;
	ESI_TSM_init(&gTSMSettings);

	// Initialization of PSM.
	gPSMSettings = ESI_PSM_INITPARAMS_DEFAULT;
	gPSMSettings.count0Select = ESI_PSM_CNT0_ENABLE;
	gPSMSettings.count0Reset = ESI_PSM_CNT0_RESET;
	gPSMSettings.count1Select = ESI_PSM_CNT1_ENABLE;
	gPSMSettings.count1Reset = ESI_PSM_CNT1_RESET;
	gPSMSettings.count2Select = ESI_PSM_CNT2_ENABLE;
	gPSMSettings.count2Reset = ESI_PSM_CNT2_RESET;

	gPSMSettings.V2Select = ESI_PSM_Q0_SELECT;


	ESI_PSM_init(&gPSMSettings);


	ESI_psmSourceSelect(PSM_S1_SOURCE, ESI_PSM_SOURCE_IS_ESIOUT0);
	ESI_psmSourceSelect(PSM_S2_SOURCE, ESI_PSM_SOURCE_IS_ESIOUT1);
	
	ESI_timerAInputSelect(ESI_TIMERA_INPUT_TSM_PPUSRC);

	ESI_TSM_copyTable(gTSMTable, sizeof(gTSMTable));

	ESI_PSM_copyTable(gPSMTable,sizeof(gPSMTable));


//	TSM_Auto_cal();

//	Find_Noise_level();
	


	
	// User need to switch on the motor with half-covered metal disc to
	// finish the calibration.
//	Set_DAC();
	
	// Set the ESI control registers for normal operation
	gAFE1Settings = ESI_AFE1_INITPARAMS_DEFAULT;
	gAFE1Settings.inverterSelectOutputAFE1 = ESI_INVERTER_FOR_AFE1_ENABLE;
	gAFE1Settings.midVoltageGeneratorSelect = ESI_MID_VOLTAGE_GENERATOR_ENABLED;
	gAFE1Settings.excitationCircuitSelect = ESI_EXCITATION_CIRCUIT_ENABLED;
	ESI_AFE1_init(&gAFE1Settings);
	
	// Set sampling frequency to User selected sampling frequency
	gTSMSettings = ESI_TSM_INITPARAMS_DEFAULT;
	gTSMSettings.startTriggerSelection = ESI_TSM_START_TRIGGER_ACLK_OR_SOFTWARE;
	gTSMSettings.startTriggerAclkDivider = ESI_TSM_START_TRIGGER_DIV_2;
	ESI_TSM_init(&gTSMSettings);
	
		// Initialization of PSM.
	gPSMSettings = ESI_PSM_INITPARAMS_DEFAULT;
	gPSMSettings.count0Select = ESI_PSM_CNT0_ENABLE;
	gPSMSettings.count0Reset = ESI_PSM_CNT0_RESET;
	gPSMSettings.count1Select = ESI_PSM_CNT1_ENABLE;
	gPSMSettings.count1Reset = ESI_PSM_CNT1_RESET;
	gPSMSettings.count2Select = ESI_PSM_CNT2_ENABLE;
	gPSMSettings.count2Reset = ESI_PSM_CNT2_RESET;

	gPSMSettings.V2Select = ESI_PSM_Q0_SELECT;


	ESI_PSM_init(&gPSMSettings);
	
	

	// Indicate Calibration of DAC process completed
	gESIStatusFlag |= DAC_CALIBRATION_COMPLETE;
	


	ESI_enable();
	
	
} 



//*****************************************************************************
//
//! \brief Configures handles Increments in count
//!
//! This function is automatically generated.
//!
//! \return None
//
//*****************************************************************************

void handleIncrementCount(void)
{
	
}



//*****************************************************************************
//
//! \brief Configures handles Decrements in count
//!
//! This function is automatically generated.
//!
//! \return None
//
//*****************************************************************************

void handleDecrementCount(void)
{
	
}



//*****************************************************************************
//
//! \brief Handles Rotation Detections 
//!
//! This function is automatically generated.
//!
//! \return None
//
//*****************************************************************************

void handleRotationDetection(void)
{
	
			// Check for completion of Calibration of DAC
			// If yes, LCD is to display the rotation number
			if(gESIStatusFlag & DAC_CALIBRATION_COMPLETE){
}
}





void (*int_0_callback)(void) = 0;
void (*int_3_callback)(void) = 0;
void (*int_4_callback)(void) = 0;
void (*int_5_callback)(void) = 0;
void (*int_6_callback)(void) = 0;
void (*int_7_callback)(void) = 0;
void (*int_8_callback)(void) = 0;

// Register callback functions for ESI interrupt
void esiRegINTCallback(uint16_t int_num, void function(void))
{
	switch (int_num)
	{
		case 0: int_0_callback = function; break;
		case 3: int_3_callback = function; break;
		case 4: int_4_callback = function; break;
		case 5: int_5_callback = function; break;
		case 6:	int_6_callback = function; break;
		case 7: int_7_callback = function; break;
		case 8: int_8_callback = function; break;
		default: break;
	}
}

// Unregister callback functions for ESI interrupt
void esiUnregINTCallback(uint16_t int_num)
{
	switch (int_num)
	{
		case 0: int_0_callback = 0; break;
		case 3: int_3_callback = 0; break;
		case 4: int_4_callback = 0; break;
		case 5: int_5_callback = 0; break;
		case 6: int_6_callback = 0; break;
		case 7: int_7_callback = 0; break;
		case 8: int_8_callback = 0; break;
		default: break;
	}
}

#pragma vector=ESCAN_IF_VECTOR
__interrupt void ISR_ESCAN_IF(void)
{
	switch (__even_in_range(ESIIV,ESIIV_ESIIFG2))
	{
		case ESIIV_ESIIFG1:			// ESIIFG1, ESISTOP flag
			ESI_clearInterrupt(ESI_INTERRUPT_FLAG_ESISTOP);
			

			
			__low_power_mode_off_on_exit();
			break;

		case ESIIV_ESIIFG0:			// ESIIFG0, ESIOUT0 to ESIOUT3 conditions
			if (int_0_callback)
				int_0_callback();
			break;
			
		case ESIIV_ESIIFG8:			// ESIIFG8, ESIOUT4 to ESIOUT7 conditions 
			if (int_8_callback)
				int_8_callback();
			break;
			
		case ESIIV_ESIIFG3:			// ESIIFG3, ESICNT1 conditions
			if (int_3_callback)
				int_3_callback();
			break;
			
		case ESIIV_ESIIFG6:			// ESIIFG6, PSM Q7
			if (int_6_callback)
				int_6_callback();
			break;
			
		case ESIIV_ESIIFG5:			// ESIIFG5, PSM Q6
			if (int_5_callback)
				int_5_callback();
				__low_power_mode_off_on_exit();
			break;
			
		case ESIIV_ESIIFG4:			// ESIIFG4, ESICNT2
			if (int_4_callback)
				int_4_callback();
			break;
			
		case ESIIV_ESIIFG7:			// ESIIFG7, ESICNT0
			if (int_7_callback)
				int_7_callback();
			break;
			
		case ESIIV_ESIIFG2: break;	// ESIIFG2, start of TSM sequence
		default: break;
	}
}
