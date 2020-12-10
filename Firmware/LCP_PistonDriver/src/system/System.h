/* --COPYRIGHT--,ESD
 *  Copyright (c) 2008 Texas Instruments. All rights reserved. 
 *  This program and the accompanying materials are made available under the 
 *  terms of the Eclipse Public License v1.0 and Eclipse Distribution License
 *  v. 1.0 which accompanies this distribution. The Eclipse Public License is
 *  available at http://www.eclipse.org/legal/epl-v10.html and the Eclipse
 *  Distribution License is available at 
 *  http://www.eclipse.org/org/documents/edl-v10.php.
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 * --/COPYRIGHT--*/

/*
 *  ========  ========
 *  Register-level / API-based Chip Configuration Tool
 */

#ifndef ti_mcu_msp430_System__include
#define ti_mcu_msp430_System__include

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== _init ========
 *  Initialize all peripherals configured by 
 *  
 *  This function is main entry point into the 
 *  generated initialization code and it initializes only
 *  the set of peripherals specified by the application's
 *  configuration script.
 *
 *  This function should be called just once.  Applications
 *  should not access any peripheral initialized by
 *  _init() before it's called.
 *
 *  The signature of this function is always the same, but
 *  the generated function body varies depending on the set
 *  of peripherals to be initialized.
 */
/* external peripheral initialization functions */
void Timer0_A3_Init(void);
void Timer2_A2_Init(void);
void Timer3_A2_Init(void);
void FRCTL_Init(void);
void GPIO_Init(void);
void CS_A_Init(void);
void PMM_Init(void);
void EUSCI_A0_Init(void);
void EUSCI_A1_Init(void);
void EUSCI_B0_Init(void);
void InterruptVectors_Init(void);
void SYS_init(void);
void DMA_Init(void);
void RTC_C_Init(void);
void WDT_A_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_mcu_msp430___include */
