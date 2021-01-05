
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


#ifdef TEST
#define PIN0        ( 1u << 0 )
#define PIN1        ( 1u << 1 )
#define PIN2        ( 1u << 2 )
#define PIN3        ( 1u << 3 )
#define PIN4        ( 1u << 4 )
#define PIN5        ( 1u << 5 )
#define PIN6        ( 1u << 6 )
#define PIN7        ( 1u << 7 )

#define PORT_P1     ( 1u << 0 )
#define PORT_P2     ( 1u << 1 )
#define PORT_P3     ( 1u << 2 )
#define PORT_P4     ( 1u << 3 )
#define PORT_P5     ( 1u << 4 )
#define PORT_P6     ( 1u << 5 )
#define PORT_P7     ( 1u << 6 )
#define PORT_P8     ( 1u << 7 )
#define PORT_P9     ( 1 << 8 )

#define DEFAULT_MODULE_FUNCITON     ( 0 )
#define PRIMARY_MODULE_FUNCTION    ( 1 )
#define SECONDARY_MODULE_FUNCTION    ( 2 )
#define TERNARY_MODULE_FUNCTION    ( 3 )

#else
#define PIN0        ( GPIO_PIN0 )
#define PIN1        ( GPIO_PIN1 )
#define PIN2        ( GPIO_PIN2 )
#define PIN3        ( GPIO_PIN3 )
#define PIN4        ( GPIO_PIN4 )
#define PIN5        ( GPIO_PIN5 )
#define PIN6        ( GPIO_PIN6 )
#define PIN7        ( GPIO_PIN7 )


#define PORT_P1     ( GPIO_PORT_P1 )
#define PORT_P2     ( GPIO_PORT_P2 )
#define PORT_P3     ( GPIO_PORT_P3 )
#define PORT_P4     ( GPIO_PORT_P4 )
#define PORT_P5     ( GPIO_PORT_P5 )
#define PORT_P6     ( GPIO_PORT_P6 )
#define PORT_P7     ( GPIO_PORT_P7 )
#define PORT_P8     ( GPIO_PORT_P8 )
#define PORT_P9     ( GPIO_PORT_P9 )

#define DEFAULT_MDOULE_FUNCTION     ( 0 )
#define PRIMARY_MODULE_FUNCTION     ( GPIO_PRIMARY_MODULE_FUNCTION )
#define SECONDARY_MODULE_FUNCTION   ( GPIO_SECONDARY_MODULE_FUNCTION )
#define TERNARY_MODULE_FUNCTION     ( GPIO_TERNARY_MODULE_FUNCTION )

#endif

#endif