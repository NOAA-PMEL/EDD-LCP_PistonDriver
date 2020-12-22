
#ifndef CONFIG_H_
#define CONFIG_H

/** Motor Driver Mode Selection */
//#define MD_CONFIG_MODE_PHEN
#define MD_CONFIG_MODE_PWM

#define FIRMWARE        ("v0.1")




/** Encoder Settings */
#define SYS_ENCODER_MIN_COUNT_DEFAULT   ( 0 ) 
#define SYS_ENCODER_MAX_COUNT_DEFAULT   ( 1000000 )
#define SYS_ENCODER_LENGTH_DEFAULT      ( 11.77 )

/*******************************************************************************
 * Extended Scan Interface Settings
 ******************************************************************************/

// The section provides all the define used in this application for
// gInterruptFlags

#define FLUSH_COUNTER_REGISTERS			        BITF
#define FLUSH_DEBUG_REGISTERS					BITE
//#define 				BITD
//#define 				BITC
//#define 				BITB
//#define 				BITA
//#define 				BIT9
//#define 				BIT8
//#define 				BIT7
//#define 				BIT6
//#define 				BIT5
//#define 				BIT4
#define DEBUG_REGISTER_FLUSH_ENABLED		                BIT3
#define PERIODIC_COUNTER_FLUSH_ENABLED		                BIT2
#define START_CONFIG_ESI_MODULE				BIT1
#define COMM_CAL_DONE 						BIT0

#define ESICHX_PORT				GPIO_PORT_P9
#define ESICH0_PIN				GPIO_PIN0
#define ESICH1_PIN				GPIO_PIN1
#define ESICH2_PIN				GPIO_PIN2
#define ESICH3_PIN				GPIO_PIN3




//---- ESIOSC frequency setting based user selection for ACLK frequency

#define ACLK_FREQUENCY_IN_HZ				32768


#define ESIOSC_DEFAULT  4800000/ACLK_FREQUENCY_IN_HZ
#define ESIOSC_3MHz     3000000/ACLK_FREQUENCY_IN_HZ
#define ESIOSC_4MHz     4000000/ACLK_FREQUENCY_IN_HZ
#define ESIOSC_5MHz     5000000/ACLK_FREQUENCY_IN_HZ
#define ESIOSC_6MHz     6000000/ACLK_FREQUENCY_IN_HZ
#define ESIOSC_7MHz     7000000/ACLK_FREQUENCY_IN_HZ
   
   
#define RECAL_TIME_OUT				8192
#define TIMER_RECALIBRATION_SELECTION				TIMER_A0_BASE
#define TIMER_RECALIBRATION_CLK_SOURCE				TIMER_A_CLOCKSOURCE_ACLK
#define TIME_TO_RECAL				61440
#define TIME_TO_RECAL_REPEAT						4
#define RECALIBRATION_TIMER_VECTOR_0				TIMER0_A0_VECTOR

#endif