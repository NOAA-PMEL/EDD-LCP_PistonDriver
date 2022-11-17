#ifndef _MSP430FR5994_H
#define _MSP430FR5994_H

#include <stdint.h>


/* CSCTL2 Control Bits */
#define SELM                             (0x0007)        /* Selects the MCLK source */
#define SELM_L                           (0x0007)
#define SELM0                            (0x0001)        /* Selects the MCLK source */
#define SELM0_L                          (0x0001)
#define SELM1                            (0x0002)        /* Selects the MCLK source */
#define SELM1_L                          (0x0002)
#define SELM2                            (0x0004)        /* Selects the MCLK source */
#define SELM2_L                          (0x0004)
#define SELM_0                           (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK */
#define SELM_1                           (0x0001)        /* VLOCLK */
#define SELM_1_L                         (0x0001)
#define SELM_2                           (0x0002)        /* LFMODCLK */
#define SELM_2_L                         (0x0002)
#define SELM_3                           (0x0003)        /* DCOCLK */
#define SELM_3_L                         (0x0003)
#define SELM_4                           (0x0004)        /* MODCLK */
#define SELM_4_L                         (0x0004)
#define SELM_5                           (0x0005)        /* HFXTCLK when HFXT available, otherwise DCOCLK */
#define SELM_5_L                         (0x0005)
#define SELM__LFXTCLK                    (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK */
#define SELM__VLOCLK                     (0x0001)        /* VLOCLK */
#define SELM__VLOCLK_L                   (0x0001)
#define SELM__LFMODCLK                   (0x0002)        /* LFMODCLK */
#define SELM__LFMODCLK_L                 (0x0002)
#define SELM__DCOCLK                     (0x0003)        /* DCOCLK */
#define SELM__DCOCLK_L                   (0x0003)
#define SELM__MODCLK                     (0x0004)        /* MODCLK */
#define SELM__MODCLK_L                   (0x0004)
#define SELM__HFXTCLK                    (0x0005)        /* HFXTCLK when HFXT available, otherwise DCOCLK */
#define SELM__HFXTCLK_L                  (0x0005)
#define SELS                             (0x0070)        /* Selects the SMCLK source */
#define SELS_L                           (0x0070)
#define SELS0                            (0x0010)        /* Selects the SMCLK source */
#define SELS0_L                          (0x0010)
#define SELS1                            (0x0020)        /* Selects the SMCLK source */
#define SELS1_L                          (0x0020)
#define SELS2                            (0x0040)        /* Selects the SMCLK source */
#define SELS2_L                          (0x0040)
#define SELS_0                           (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK. */
#define SELS_1                           (0x0010)        /* VLOCLK */
#define SELS_1_L                         (0x0010)
#define SELS_2                           (0x0020)        /* LFMODCLK */
#define SELS_2_L                         (0x0020)
#define SELS_3                           (0x0030)        /* DCOCLK */
#define SELS_3_L                         (0x0030)
#define SELS_4                           (0x0040)        /* MODCLK */
#define SELS_4_L                         (0x0040)
#define SELS_5                           (0x0050)        /* HFXTCLK when HFXT available, otherwise DCOCLK. */
#define SELS_5_L                         (0x0050)
#define SELS__LFXTCLK                    (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK. */
#define SELS__VLOCLK                     (0x0010)        /* VLOCLK */
#define SELS__VLOCLK_L                   (0x0010)
#define SELS__LFMODCLK                   (0x0020)        /* LFMODCLK */
#define SELS__LFMODCLK_L                 (0x0020)
#define SELS__DCOCLK                     (0x0030)        /* DCOCLK */
#define SELS__DCOCLK_L                   (0x0030)
#define SELS__MODCLK                     (0x0040)        /* MODCLK */
#define SELS__MODCLK_L                   (0x0040)
#define SELS__HFXTCLK                    (0x0050)        /* HFXTCLK when HFXT available, otherwise DCOCLK. */
#define SELS__HFXTCLK_L                  (0x0050)
#define SELA                             (0x0700)        /* Selects the ACLK source */
#define SELA_H                           (0x0007)
#define SELA0                            (0x0100)        /* Selects the ACLK source */
#define SELA0_H                          (0x0001)
#define SELA1                            (0x0200)        /* Selects the ACLK source */
#define SELA1_H                          (0x0002)
#define SELA2                            (0x0400)        /* Selects the ACLK source */
#define SELA2_H                          (0x0004)
#define SELA_0                           (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK. */
#define SELA_1                           (0x0100)        /* VLOCLK */
#define SELA_1_H                         (0x0001)
#define SELA_2                           (0x0200)        /* LFMODCLK */
#define SELA_2_H                         (0x0002)
#define SELA__LFXTCLK                    (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK. */
#define SELA__VLOCLK                     (0x0100)        /* VLOCLK */
#define SELA__VLOCLK_H                   (0x0001)
#define SELA__LFMODCLK                   (0x0200)        /* LFMODCLK */
#define SELA__LFMODCLK_H                 (0x0002)

/* CSCTL6 Control Bits */
#define ACLKREQEN                        (0x0001)        /* ACLK clock request enable */
#define ACLKREQEN_L                      (0x0001)
#define ACLKREQEN_0                      (0x0000)        /* ACLK conditional requests are disabled */
#define ACLKREQEN_1                      (0x0001)        /* ACLK conditional requests are enabled */
#define ACLKREQEN_1_L                    (0x0001)
#define ACLKREQEN__DISABLE               (0x0000)        /* ACLK conditional requests are disabled */
#define ACLKREQEN__ENABLE                (0x0001)        /* ACLK conditional requests are enabled */
#define ACLKREQEN__ENABLE_L              (0x0001)
#define MCLKREQEN                        (0x0002)        /* MCLK clock request enable */
#define MCLKREQEN_L                      (0x0002)
#define MCLKREQEN_0                      (0x0000)        /* MCLK conditional requests are disabled */
#define MCLKREQEN_1                      (0x0002)        /* MCLK conditional requests are enabled */
#define MCLKREQEN_1_L                    (0x0002)
#define MCLKREQEN__DISABLE               (0x0000)        /* MCLK conditional requests are disabled */
#define MCLKREQEN__ENABLE                (0x0002)        /* MCLK conditional requests are enabled */
#define MCLKREQEN__ENABLE_L              (0x0002)
#define SMCLKREQEN                       (0x0004)        /* SMCLK clock request enable */
#define SMCLKREQEN_L                     (0x0004)
#define SMCLKREQEN_0                     (0x0000)        /* SMCLK conditional requests are disabled */
#define SMCLKREQEN_1                     (0x0004)        /* SMCLK conditional requests are enabled */
#define SMCLKREQEN_1_L                   (0x0004)
#define SMCLKREQEN__DISABLE              (0x0000)        /* SMCLK conditional requests are disabled */
#define SMCLKREQEN__ENABLE               (0x0004)        /* SMCLK conditional requests are enabled */
#define SMCLKREQEN__ENABLE_L             (0x0004)
#define MODCLKREQEN                      (0x0008)        /* MODCLK clock request enable */
#define MODCLKREQEN_L                    (0x0008)
#define MODCLKREQEN_0                    (0x0000)        /* MODCLK conditional requests are disabled */
#define MODCLKREQEN_1                    (0x0008)        /* MODCLK conditional requests are enabled */
#define MODCLKREQEN_1_L                  (0x0008)
#define MODCLKREQEN__DISABLE             (0x0000)        /* MODCLK conditional requests are disabled */
#define MODCLKREQEN__ENABLE              (0x0008)        /* MODCLK conditional requests are enabled */
#define MODCLKREQEN__ENABLE_L            (0x0008)

/* CSCTL4 Control Bits */
#define LFXTOFF                          (0x0001)        /* LFXT off */
#define LFXTOFF_L                        (0x0001)
#define LFXTOFF_0                        (0x0000)        /* LFXT is on if LFXT is selected via the port selection and LFXT
                                                            is not in bypass mode of operation */
#define LFXTOFF_1                        (0x0001)        /* LFXT is off if it is not used as a source for ACLK, MCLK, or 
                                                            SMCLK */
#define LFXTOFF_1_L                      (0x0001)
#define SMCLKOFF                         (0x0002)        /* SMCLK off */
#define SMCLKOFF_L                       (0x0002)
#define SMCLKOFF_0                       (0x0000)        /* SMCLK on */
#define SMCLKOFF_1                       (0x0002)        /* SMCLK off */
#define SMCLKOFF_1_L                     (0x0002)
#define VLOOFF                           (0x0008)        /* VLO off */
#define VLOOFF_L                         (0x0008)
#define VLOOFF_0                         (0x0000)        /* VLO is on */
#define VLOOFF_1                         (0x0008)        /* VLO is off if it is not used as a source for ACLK, MCLK, or 
                                                            SMCLK or if not used as a source for the RTC in LPM3.5 */
#define VLOOFF_1_L                       (0x0008)
#define LFXTBYPASS                       (0x0010)        /* LFXT bypass select */
#define LFXTBYPASS_L                     (0x0010)
#define LFXTBYPASS_0                     (0x0000)        /* LFXT sourced from external crystal */
#define LFXTBYPASS_1                     (0x0010)        /* LFXT sourced from external clock signal */
#define LFXTBYPASS_1_L                   (0x0010)
#define LFXTDRIVE                        (0x00c0)        /* LFXT oscillator current */
#define LFXTDRIVE_L                      (0x00c0)
#define LFXTDRIVE0                       (0x0040)        /* LFXT oscillator current */
#define LFXTDRIVE0_L                     (0x0040)
#define LFXTDRIVE1                       (0x0080)        /* LFXT oscillator current */
#define LFXTDRIVE1_L                     (0x0080)
#define LFXTDRIVE_0                      (0x0000)        /* Lowest drive strength and current consumption LFXT oscillator */
#define LFXTDRIVE_1                      (0x0040)        /* Increased drive strength LFXT oscillator */
#define LFXTDRIVE_1_L                    (0x0040)
#define LFXTDRIVE_2                      (0x0080)        /* Increased drive strength LFXT oscillator */
#define LFXTDRIVE_2_L                    (0x0080)
#define LFXTDRIVE_3                      (0x00c0)        /* Maximum drive strength and maximum current consumption LFXT 
                                                            oscillator */
#define LFXTDRIVE_3_L                    (0x00c0)
#define HFXTOFF                          (0x0100)        /* Turns off the HFXT oscillator */
#define HFXTOFF_H                        (0x0001)
#define HFXTOFF_0                        (0x0000)        /* HFXT is on if HFXT is selected via the port selection and HFXT
                                                            is not in bypass mode of operation */
#define HFXTOFF_1                        (0x0100)        /* HFXT is off if it is not used as a source for ACLK, MCLK, or 
                                                            SMCLK */
#define HFXTOFF_1_H                      (0x0001)
#define HFFREQ                           (0x0c00)        /* HFXT frequency selection */
#define HFFREQ_H                         (0x000c)
#define HFFREQ0                          (0x0400)        /* HFXT frequency selection */
#define HFFREQ0_H                        (0x0004)
#define HFFREQ1                          (0x0800)        /* HFXT frequency selection */
#define HFFREQ1_H                        (0x0008)
#define HFFREQ_0                         (0x0000)        /* 0 to 4 MHz */
#define HFFREQ_1                         (0x0400)        /* Greater than 4 MHz to 8 MHz */
#define HFFREQ_1_H                       (0x0004)
#define HFFREQ_2                         (0x0800)        /* Greater than 8 MHz to 16 MHz */
#define HFFREQ_2_H                       (0x0008)
#define HFFREQ_3                         (0x0c00)        /* Greater than 16 MHz to 24 MHz */
#define HFFREQ_3_H                       (0x000c)
#define HFXTBYPASS                       (0x1000)        /* HFXT bypass select */
#define HFXTBYPASS_H                     (0x0010)
#define HFXTBYPASS_0                     (0x0000)        /* HFXT sourced from external crystal */
#define HFXTBYPASS_1                     (0x1000)        /* HFXT sourced from external clock signal */
#define HFXTBYPASS_1_H                   (0x0010)
#define HFXTDRIVE                        (0xc000)        /* HFXT oscillator current */
#define HFXTDRIVE_H                      (0x00c0)
#define HFXTDRIVE0                       (0x4000)        /* HFXT oscillator current */
#define HFXTDRIVE0_H                     (0x0040)
#define HFXTDRIVE1                       (0x8000)        /* HFXT oscillator current */
#define HFXTDRIVE1_H                     (0x0080)
#define HFXTDRIVE_0                      (0x0000)        /* Lowest current consumption */
#define HFXTDRIVE_1                      (0x4000)        /* Increased drive strength HFXT oscillator */
#define HFXTDRIVE_1_H                    (0x0040)
#define HFXTDRIVE_2                      (0x8000)        /* Increased drive strength HFXT oscillator */
#define HFXTDRIVE_2_H                    (0x0080)
#define HFXTDRIVE_3                      (0xc000)        /* Maximum drive strength HFXT oscillator */


/* UCA0IE Control Bits */
#define UCRXIE                           (0x0001)        /* Receive interrupt enable */
#define UCRXIE_L                         (0x0001)
#define UCRXIE_0                         (0x0000)        /* Interrupt disabled */
#define UCRXIE_1                         (0x0001)        /* Interrupt enabled */
#define UCRXIE_1_L                       (0x0001)
#define UCTXIE                           (0x0002)        /* Transmit interrupt enable */
#define UCTXIE_L                         (0x0002)
#define UCTXIE_0                         (0x0000)        /* Interrupt disabled */
#define UCTXIE_1                         (0x0002)        /* Interrupt enabled */
#define UCTXIE_1_L                       (0x0002)
#define UCSTTIE                          (0x0004)        /* Start bit interrupt enable */
#define UCSTTIE_L                        (0x0004)
#define UCSTTIE_0                        (0x0000)        /* Interrupt disabled */
#define UCSTTIE_1                        (0x0004)        /* Interrupt enabled */
#define UCSTTIE_1_L                      (0x0004)
#define UCTXCPTIE                        (0x0008)        /* Transmit complete interrupt enable */
#define UCTXCPTIE_L                      (0x0008)
#define UCTXCPTIE_0                      (0x0000)        /* Interrupt disabled */
#define UCTXCPTIE_1                      (0x0008)        /* Interrupt enabled */
#define UCTXCPTIE_1_L                    (0x0008)

/* UCA0IFG Control Bits */
#define UCRXIFG                          (0x0001)        /* Receive interrupt flag */
#define UCRXIFG_L                        (0x0001)
#define UCRXIFG_0                        (0x0000)        /* No interrupt pending */
#define UCRXIFG_1                        (0x0001)        /* Interrupt pending */
#define UCRXIFG_1_L                      (0x0001)
#define UCTXIFG                          (0x0002)        /* Transmit interrupt flag */
#define UCTXIFG_L                        (0x0002)
#define UCTXIFG_0                        (0x0000)        /* No interrupt pending */
#define UCTXIFG_1                        (0x0002)        /* Interrupt pending */
#define UCTXIFG_1_L                      (0x0002)
#define UCSTTIFG                         (0x0004)        /* Start bit interrupt flag */
#define UCSTTIFG_L                       (0x0004)
#define UCSTTIFG_0                       (0x0000)        /* No interrupt pending */
#define UCSTTIFG_1                       (0x0004)        /* Interrupt pending */
#define UCSTTIFG_1_L                     (0x0004)
#define UCTXCPTIFG                       (0x0008)        /* Transmit ready interrupt enable */
#define UCTXCPTIFG_L                     (0x0008)
#define UCTXCPTIFG_0                     (0x0000)        /* No interrupt pending */
#define UCTXCPTIFG_1                     (0x0008)        /* Interrupt pending */
#define UCTXCPTIFG_1_L                   (0x0008)


/* UCA0CTLW0 Control Bits */
#define UCSWRST                          (0x0001)        /* Software reset enable */
#define UCSWRST_L                        (0x0001)
#define UCSWRST_0                        (0x0000)        /* Disabled. eUSCI_A reset released for operation */
#define UCSWRST_1                        (0x0001)        /* Enabled. eUSCI_A logic held in reset state */
#define UCSWRST_1_L                      (0x0001)
#define UCSWRST__DISABLE                 (0x0000)        /* Disabled. eUSCI_A reset released for operation */
#define UCSWRST__ENABLE                  (0x0001)        /* Enabled. eUSCI_A logic held in reset state */
#define UCSWRST__ENABLE_L                (0x0001)
#define UCTXBRK                          (0x0002)        /* Transmit break */
#define UCTXBRK_L                        (0x0002)
#define UCTXBRK_0                        (0x0000)        /* Next frame transmitted is not a break */
#define UCTXBRK_1                        (0x0002)        /* Next frame transmitted is a break or a break/synch */
#define UCTXBRK_1_L                      (0x0002)
#define UCTXADDR                         (0x0004)        /* Transmit address */
#define UCTXADDR_L                       (0x0004)
#define UCTXADDR_0                       (0x0000)        /* Next frame transmitted is data */
#define UCTXADDR_1                       (0x0004)        /* Next frame transmitted is an address */
#define UCTXADDR_1_L                     (0x0004)
#define UCDORM                           (0x0008)        /* Dormant */
#define UCDORM_L                         (0x0008)
#define UCDORM_0                         (0x0000)        /* Not dormant. All received characters set UCRXIFG. */
#define UCDORM_1                         (0x0008)        /* Dormant. Only characters that are preceded by an idle-line or 
                                                            with address bit set UCRXIFG. In UART mode with automatic baud-
                                                            rate detection, only the combination of a break and synch 
                                                            field sets UCRXIFG. */
#define UCDORM_1_L                       (0x0008)
#define UCBRKIE                          (0x0010)        /* Receive break character interrupt enable */
#define UCBRKIE_L                        (0x0010)
#define UCBRKIE_0                        (0x0000)        /* Received break characters do not set UCRXIFG */
#define UCBRKIE_1                        (0x0010)        /* Received break characters set UCRXIFG */
#define UCBRKIE_1_L                      (0x0010)
#define UCRXEIE                          (0x0020)        /* Receive erroneous-character interrupt enable */
#define UCRXEIE_L                        (0x0020)
#define UCRXEIE_0                        (0x0000)        /* Erroneous characters rejected and UCRXIFG is not set */
#define UCRXEIE_1                        (0x0020)        /* Erroneous characters received set UCRXIFG */
#define UCRXEIE_1_L                      (0x0020)
#define UCSSEL                           (0x00c0)        /* eUSCI_A clock source select */
#define UCSSEL_L                         (0x00c0)
#define UCSSEL0                          (0x0040)        /* eUSCI_A clock source select */
#define UCSSEL0_L                        (0x0040)
#define UCSSEL1                          (0x0080)        /* eUSCI_A clock source select */
#define UCSSEL1_L                        (0x0080)
#define UCSSEL_0                         (0x0000)        /* UCLK */
#define UCSSEL_1                         (0x0040)        /* ACLK */
#define UCSSEL_1_L                       (0x0040)
#define UCSSEL_2                         (0x0080)        /* SMCLK */
#define UCSSEL_2_L                       (0x0080)
#define UCSSEL__UCLK                     (0x0000)        /* UCLK */
#define UCSSEL__ACLK                     (0x0040)        /* ACLK */
#define UCSSEL__ACLK_L                   (0x0040)
#define UCSSEL__SMCLK                    (0x0080)        /* SMCLK */
#define UCSSEL__SMCLK_L                  (0x0080)
#define UCSYNC                           (0x0100)        /* Synchronous mode enable */
#define UCSYNC_H                         (0x0001)
#define UCSYNC_0                         (0x0000)        /* Asynchronous mode */
#define UCSYNC_1                         (0x0100)        /* Synchronous mode */
#define UCSYNC_1_H                       (0x0001)
#define UCSYNC__ASYNC                    (0x0000)        /* Asynchronous mode */
#define UCSYNC__SYNC                     (0x0100)        /* Synchronous mode */
#define UCSYNC__SYNC_H                   (0x0001)
#define UCMODE                           (0x0600)        /* eUSCI_A mode */
#define UCMODE_H                         (0x0006)
#define UCMODE0                          (0x0200)        /* eUSCI_A mode */
#define UCMODE0_H                        (0x0002)
#define UCMODE1                          (0x0400)        /* eUSCI_A mode */
#define UCMODE1_H                        (0x0004)
#define UCMODE_0                         (0x0000)        /* UART mode */
#define UCMODE_1                         (0x0200)        /* Idle-line multiprocessor mode */
#define UCMODE_1_H                       (0x0002)
#define UCMODE_2                         (0x0400)        /* Address-bit multiprocessor mode */
#define UCMODE_2_H                       (0x0004)
#define UCMODE_3                         (0x0600)        /* UART mode with automatic baud-rate detection */
#define UCMODE_3_H                       (0x0006)
#define UCSPB                            (0x0800)        /* Stop bit select */
#define UCSPB_H                          (0x0008)
#define UCSPB_0                          (0x0000)        /* One stop bit */
#define UCSPB_1                          (0x0800)        /* Two stop bits */
#define UCSPB_1_H                        (0x0008)
#define UC7BIT                           (0x1000)        /* Character length */
#define UC7BIT_H                         (0x0010)
#define UC7BIT_0                         (0x0000)        /* 8-bit data */
#define UC7BIT_1                         (0x1000)        /* 7-bit data */
#define UC7BIT_1_H                       (0x0010)
#define UC7BIT__8BIT                     (0x0000)        /* 8-bit data */
#define UC7BIT__7BIT                     (0x1000)        /* 7-bit data */
#define UC7BIT__7BIT_H                   (0x0010)
#define UCMSB                            (0x2000)        /* MSB first select */
#define UCMSB_H                          (0x0020)
#define UCMSB_0                          (0x0000)        /* LSB first */
#define UCMSB_1                          (0x2000)        /* MSB first */
#define UCMSB_1_H                        (0x0020)
#define UCPAR                            (0x4000)        /* Parity select */
#define UCPAR_H                          (0x0040)
#define UCPAR_0                          (0x0000)        /* Odd parity */
#define UCPAR_1                          (0x4000)        /* Even parity */
#define UCPAR_1_H                        (0x0040)
#define UCPAR__ODD                       (0x0000)        /* Odd parity */
#define UCPAR__EVEN                      (0x4000)        /* Even parity */
#define UCPAR__EVEN_H                    (0x0040)
#define UCPEN                            (0x8000)        /* Parity enable */
#define UCPEN_H                          (0x0080)
#define UCPEN_0                          (0x0000)        /* Parity disabled */
#define UCPEN_1                          (0x8000)        /* Parity enabled. Parity bit is generated (UCAxTXD) and expected
                                                             (UCAxRXD). In address-bit multiprocessor mode, the address 
                                                            bit is included in the parity calculation. */
#define UCPEN_1_H                        (0x0080)
#define UCSWRST     (0x0001)
#define UCSSEL__UCLK                     (0x0000)        /* UCLK */
#define UCSSEL__ACLK                     (0x0040)        /* ACLK */
#define UCSSEL__ACLK_L                   (0x0040)
#define UCSSEL__SMCLK                    (0x0080)        /* SMCLK */
#define UCSSEL__SMCLK_L                  (0x0080)

#define __MSP430_BASEADDRESS_EUSCI_A0__ 0x05C0
#define EUSCI_A0_BASE          __MSP430_BASEADDRESS_EUSCI_A0__
#define __MSP430_BASEADDRESS_EUSCI_A1__ 0x05E0
#define EUSCI_A1_BASE          __MSP430_BASEADDRESS_EUSCI_A1__
#define __MSP430_BASEADDRESS_EUSCI_A2__ 0x0600
#define EUSCI_A2_BASE          __MSP430_BASEADDRESS_EUSCI_A2__
#define __MSP430_BASEADDRESS_EUSCI_A3__ 0x0620
#define EUSCI_A3_BASE          __MSP430_BASEADDRESS_EUSCI_A3__

#define __MSP430_BASEADDRESS_EUSCI_B0__ 0x0640
#define EUSCI_B0_BASE          __MSP430_BASEADDRESS_EUSCI_B0__
#define __MSP430_BASEADDRESS_EUSCI_B1__ 0x0680
#define EUSCI_B1_BASE          __MSP430_BASEADDRESS_EUSCI_B1__
#define __MSP430_BASEADDRESS_EUSCI_B2__ 0x06C0
#define EUSCI_B2_BASE          __MSP430_BASEADDRESS_EUSCI_B2__
#define __MSP430_BASEADDRESS_EUSCI_B3__ 0x0700
#define EUSCI_B3_BASE          __MSP430_BASEADDRESS_EUSCI_B3__


/* UCB0CTLW0 Control Bits */
#define UCTXSTT                          (0x0002)        /* Transmit START condition in master mode */
#define UCTXSTT_L                        (0x0002)
#define UCTXSTT_0                        (0x0000)        /* Do not generate START condition */
#define UCTXSTT_1                        (0x0002)        /* Generate START condition */
#define UCTXSTT_1_L                      (0x0002)
#define UCTXSTP                          (0x0004)        /* Transmit STOP condition in master mode */
#define UCTXSTP_L                        (0x0004)
#define UCTXSTP_0                        (0x0000)        /* No STOP generated */
#define UCTXSTP_1                        (0x0004)        /* Generate STOP */
#define UCTXSTP_1_L                      (0x0004)
#define UCTXNACK                         (0x0008)        /* Transmit a NACK */
#define UCTXNACK_L                       (0x0008)
#define UCTXNACK_0                       (0x0000)        /* Acknowledge normally */
#define UCTXNACK_1                       (0x0008)        /* Generate NACK */
#define UCTXNACK_1_L                     (0x0008)
#define UCTR                             (0x0010)        /* Transmitter/receiver */
#define UCTR_L                           (0x0010)
#define UCTR_0                           (0x0000)        /* Receiver */
#define UCTR_1                           (0x0010)        /* Transmitter */
#define UCTR_1_L                         (0x0010)
#define UCTR__RX                         (0x0000)        /* Receiver */
#define UCTR__TX                         (0x0010)        /* Transmitter */
#define UCTR__TX_L                       (0x0010)
#define UCTXACK                          (0x0020)        /* Transmit ACK condition in slave mode */
#define UCTXACK_L                        (0x0020)
#define UCTXACK_0                        (0x0000)        /* Do not acknowledge the slave address */
#define UCTXACK_1                        (0x0020)        /* Acknowledge the slave address */
#define UCTXACK_1_L                      (0x0020)
#define UCSSEL_3                         (0x00c0)        /* SMCLK */
#define UCSSEL_3_L                       (0x00c0)
#define UCSSEL__UCLKI                    (0x0000)        /* UCLKI */
#define UCMM                             (0x2000)        /* Multi-master environment select */
#define UCMM_H                           (0x0020)
#define UCMM_0                           (0x0000)        /* Single master environment. There is no other master in the 
                                                            system. The address compare unit is disabled. */
#define UCMM_1                           (0x2000)        /* Multi-master environment */
#define UCMM_1_H                         (0x0020)
#define UCMM__SINGLE                     (0x0000)        /* Single master environment. There is no other master in the 
                                                            system. The address compare unit is disabled. */
#define UCMM__MULTI                      (0x2000)        /* Multi-master environment */
#define UCMM__MULTI_H                    (0x0020)
#define UCSLA10                          (0x4000)        /* Slave addressing mode select */
#define UCSLA10_H                        (0x0040)
#define UCSLA10_0                        (0x0000)        /* Address slave with 7-bit address */
#define UCSLA10_1                        (0x4000)        /* Address slave with 10-bit address */
#define UCSLA10_1_H                      (0x0040)
#define UCSLA10__7BIT                    (0x0000)        /* Address slave with 7-bit address */
#define UCSLA10__10BIT                   (0x4000)        /* Address slave with 10-bit address */
#define UCSLA10__10BIT_H                 (0x0040)
#define UCA10                            (0x8000)        /* Own addressing mode select */
#define UCA10_H                          (0x0080)
#define UCA10_0                          (0x0000)        /* Own address is a 7-bit address */
#define UCA10_1                          (0x8000)        /* Own address is a 10-bit address */
#define UCA10_1_H                        (0x0080)



/* CSCTL0 Control Bits */
#define CSKEY                            (0xa500)        /* CSKEY password */
#define CSKEY_H                          (0x00a5)
#define CSKEY0                           (0x0100)        /* CSKEY password */
#define CSKEY0_H                         (0x0001)
#define CSKEY1                           (0x0200)        /* CSKEY password */
#define CSKEY1_H                         (0x0002)
#define CSKEY2                           (0x0400)        /* CSKEY password */
#define CSKEY2_H                         (0x0004)
#define CSKEY3                           (0x0800)        /* CSKEY password */
#define CSKEY3_H                         (0x0008)
#define CSKEY4                           (0x1000)        /* CSKEY password */
#define CSKEY4_H                         (0x0010)
#define CSKEY5                           (0x2000)        /* CSKEY password */
#define CSKEY5_H                         (0x0020)
#define CSKEY6                           (0x4000)        /* CSKEY password */
#define CSKEY6_H                         (0x0040)
#define CSKEY7                           (0x8000)        /* CSKEY password */
#define CSKEY7_H                         (0x0080)

/* CSCTL1 Control Bits */
#define DCOFSEL                          (0x000e)        /* DCO frequency select */
#define DCOFSEL_L                        (0x000e)
#define DCOFSEL0                         (0x0002)        /* DCO frequency select */
#define DCOFSEL0_L                       (0x0002)
#define DCOFSEL1                         (0x0004)        /* DCO frequency select */
#define DCOFSEL1_L                       (0x0004)
#define DCOFSEL2                         (0x0008)        /* DCO frequency select */
#define DCOFSEL2_L                       (0x0008)
#define DCOFSEL_0                        (0x0000)        /* If DCORSEL = 0: 1 MHz; If DCORSEL = 1: 1 MHz */
#define DCOFSEL_1                        (0x0002)        /* If DCORSEL = 0: 2.67 MHz; If DCORSEL = 1: 5.33 MHz */
#define DCOFSEL_1_L                      (0x0002)
#define DCOFSEL_2                        (0x0004)        /* If DCORSEL = 0: 3.33 MHz; If DCORSEL = 1: 6.67 MHz */
#define DCOFSEL_2_L                      (0x0004)
#define DCOFSEL_3                        (0x0006)        /* If DCORSEL = 0: 4 MHz; If DCORSEL = 1: 8 MHz */
#define DCOFSEL_3_L                      (0x0006)
#define DCOFSEL_4                        (0x0008)        /* If DCORSEL = 0: 5.33 MHz; If DCORSEL = 1: 16 MHz */
#define DCOFSEL_4_L                      (0x0008)
#define DCOFSEL_5                        (0x000a)        /* If DCORSEL = 0: 6.67 MHz; If DCORSEL = 1: 21 MHz */
#define DCOFSEL_5_L                      (0x000a)
#define DCOFSEL_6                        (0x000c)        /* If DCORSEL = 0: 8 MHz; If DCORSEL = 1: 24 MHz */
#define DCOFSEL_6_L                      (0x000c)
#define DCOFSEL_7                        (0x000e)        /* If DCORSEL = 0: Reserved. Defaults to 8. It is not recommended
                                                             to use this setting; If DCORSEL = 1: Reserved. Defaults to 24.
                                                            It is not recommended to use this setting */
#define DCOFSEL_7_L                      (0x000e)
#define DCORSEL                          (0x0040)        /* DCO range select */
#define DCORSEL_L                        (0x0040)

/* CSCTL2 Control Bits */
#define SELM                             (0x0007)        /* Selects the MCLK source */
#define SELM_L                           (0x0007)
#define SELM0                            (0x0001)        /* Selects the MCLK source */
#define SELM0_L                          (0x0001)
#define SELM1                            (0x0002)        /* Selects the MCLK source */
#define SELM1_L                          (0x0002)
#define SELM2                            (0x0004)        /* Selects the MCLK source */
#define SELM2_L                          (0x0004)
#define SELM_0                           (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK */
#define SELM_1                           (0x0001)        /* VLOCLK */
#define SELM_1_L                         (0x0001)
#define SELM_2                           (0x0002)        /* LFMODCLK */
#define SELM_2_L                         (0x0002)
#define SELM_3                           (0x0003)        /* DCOCLK */
#define SELM_3_L                         (0x0003)
#define SELM_4                           (0x0004)        /* MODCLK */
#define SELM_4_L                         (0x0004)
#define SELM_5                           (0x0005)        /* HFXTCLK when HFXT available, otherwise DCOCLK */
#define SELM_5_L                         (0x0005)
#define SELM__LFXTCLK                    (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK */
#define SELM__VLOCLK                     (0x0001)        /* VLOCLK */
#define SELM__VLOCLK_L                   (0x0001)
#define SELM__LFMODCLK                   (0x0002)        /* LFMODCLK */
#define SELM__LFMODCLK_L                 (0x0002)
#define SELM__DCOCLK                     (0x0003)        /* DCOCLK */
#define SELM__DCOCLK_L                   (0x0003)
#define SELM__MODCLK                     (0x0004)        /* MODCLK */
#define SELM__MODCLK_L                   (0x0004)
#define SELM__HFXTCLK                    (0x0005)        /* HFXTCLK when HFXT available, otherwise DCOCLK */
#define SELM__HFXTCLK_L                  (0x0005)
#define SELS                             (0x0070)        /* Selects the SMCLK source */
#define SELS_L                           (0x0070)
#define SELS0                            (0x0010)        /* Selects the SMCLK source */
#define SELS0_L                          (0x0010)
#define SELS1                            (0x0020)        /* Selects the SMCLK source */
#define SELS1_L                          (0x0020)
#define SELS2                            (0x0040)        /* Selects the SMCLK source */
#define SELS2_L                          (0x0040)
#define SELS_0                           (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK. */
#define SELS_1                           (0x0010)        /* VLOCLK */
#define SELS_1_L                         (0x0010)
#define SELS_2                           (0x0020)        /* LFMODCLK */
#define SELS_2_L                         (0x0020)
#define SELS_3                           (0x0030)        /* DCOCLK */
#define SELS_3_L                         (0x0030)
#define SELS_4                           (0x0040)        /* MODCLK */
#define SELS_4_L                         (0x0040)
#define SELS_5                           (0x0050)        /* HFXTCLK when HFXT available, otherwise DCOCLK. */
#define SELS_5_L                         (0x0050)
#define SELS__LFXTCLK                    (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK. */
#define SELS__VLOCLK                     (0x0010)        /* VLOCLK */
#define SELS__VLOCLK_L                   (0x0010)
#define SELS__LFMODCLK                   (0x0020)        /* LFMODCLK */
#define SELS__LFMODCLK_L                 (0x0020)
#define SELS__DCOCLK                     (0x0030)        /* DCOCLK */
#define SELS__DCOCLK_L                   (0x0030)
#define SELS__MODCLK                     (0x0040)        /* MODCLK */
#define SELS__MODCLK_L                   (0x0040)
#define SELS__HFXTCLK                    (0x0050)        /* HFXTCLK when HFXT available, otherwise DCOCLK. */
#define SELS__HFXTCLK_L                  (0x0050)
#define SELA                             (0x0700)        /* Selects the ACLK source */
#define SELA_H                           (0x0007)
#define SELA0                            (0x0100)        /* Selects the ACLK source */
#define SELA0_H                          (0x0001)
#define SELA1                            (0x0200)        /* Selects the ACLK source */
#define SELA1_H                          (0x0002)
#define SELA2                            (0x0400)        /* Selects the ACLK source */
#define SELA2_H                          (0x0004)
#define SELA_0                           (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK. */
#define SELA_1                           (0x0100)        /* VLOCLK */
#define SELA_1_H                         (0x0001)
#define SELA_2                           (0x0200)        /* LFMODCLK */
#define SELA_2_H                         (0x0002)
#define SELA__LFXTCLK                    (0x0000)        /* LFXTCLK when LFXT available, otherwise VLOCLK. */
#define SELA__VLOCLK                     (0x0100)        /* VLOCLK */
#define SELA__VLOCLK_H                   (0x0001)
#define SELA__LFMODCLK                   (0x0200)        /* LFMODCLK */
#define SELA__LFMODCLK_H                 (0x0002)

/* CSCTL3 Control Bits */
#define DIVM                             (0x0007)        /* MCLK source divider */
#define DIVM_L                           (0x0007)
#define DIVM0                            (0x0001)        /* MCLK source divider */
#define DIVM0_L                          (0x0001)
#define DIVM1                            (0x0002)        /* MCLK source divider */
#define DIVM1_L                          (0x0002)
#define DIVM2                            (0x0004)        /* MCLK source divider */
#define DIVM2_L                          (0x0004)
#define DIVM_0                           (0x0000)        /* /1 */
#define DIVM_1                           (0x0001)        /* /2 */
#define DIVM_1_L                         (0x0001)
#define DIVM_2                           (0x0002)        /* /4 */
#define DIVM_2_L                         (0x0002)
#define DIVM_3                           (0x0003)        /* /8 */
#define DIVM_3_L                         (0x0003)
#define DIVM_4                           (0x0004)        /* /16 */
#define DIVM_4_L                         (0x0004)
#define DIVM_5                           (0x0005)        /* /32 */
#define DIVM_5_L                         (0x0005)
#define DIVM__1                          (0x0000)        /* /1 */
#define DIVM__2                          (0x0001)        /* /2 */
#define DIVM__2_L                        (0x0001)
#define DIVM__4                          (0x0002)        /* /4 */
#define DIVM__4_L                        (0x0002)
#define DIVM__8                          (0x0003)        /* /8 */
#define DIVM__8_L                        (0x0003)
#define DIVM__16                         (0x0004)        /* /16 */
#define DIVM__16_L                       (0x0004)
#define DIVM__32                         (0x0005)        /* /32 */
#define DIVM__32_L                       (0x0005)
#define DIVS                             (0x0070)        /* SMCLK source divider */
#define DIVS_L                           (0x0070)
#define DIVS0                            (0x0010)        /* SMCLK source divider */
#define DIVS0_L                          (0x0010)
#define DIVS1                            (0x0020)        /* SMCLK source divider */
#define DIVS1_L                          (0x0020)
#define DIVS2                            (0x0040)        /* SMCLK source divider */
#define DIVS2_L                          (0x0040)
#define DIVS_0                           (0x0000)        /* /1 */
#define DIVS_1                           (0x0010)        /* /2 */
#define DIVS_1_L                         (0x0010)
#define DIVS_2                           (0x0020)        /* /4 */
#define DIVS_2_L                         (0x0020)
#define DIVS_3                           (0x0030)        /* /8 */
#define DIVS_3_L                         (0x0030)
#define DIVS_4                           (0x0040)        /* /16 */
#define DIVS_4_L                         (0x0040)
#define DIVS_5                           (0x0050)        /* /32 */
#define DIVS_5_L                         (0x0050)
#define DIVS__1                          (0x0000)        /* /1 */
#define DIVS__2                          (0x0010)        /* /2 */
#define DIVS__2_L                        (0x0010)
#define DIVS__4                          (0x0020)        /* /4 */
#define DIVS__4_L                        (0x0020)
#define DIVS__8                          (0x0030)        /* /8 */
#define DIVS__8_L                        (0x0030)
#define DIVS__16                         (0x0040)        /* /16 */
#define DIVS__16_L                       (0x0040)
#define DIVS__32                         (0x0050)        /* /32 */
#define DIVS__32_L                       (0x0050)
#define DIVA                             (0x0700)        /* ACLK source divider */
#define DIVA_H                           (0x0007)
#define DIVA0                            (0x0100)        /* ACLK source divider */
#define DIVA0_H                          (0x0001)
#define DIVA1                            (0x0200)        /* ACLK source divider */
#define DIVA1_H                          (0x0002)
#define DIVA2                            (0x0400)        /* ACLK source divider */
#define DIVA2_H                          (0x0004)
#define DIVA_0                           (0x0000)        /* /1 */
#define DIVA_1                           (0x0100)        /* /2 */
#define DIVA_1_H                         (0x0001)
#define DIVA_2                           (0x0200)        /* /4 */
#define DIVA_2_H                         (0x0002)
#define DIVA_3                           (0x0300)        /* /8 */
#define DIVA_3_H                         (0x0003)
#define DIVA_4                           (0x0400)        /* /16 */
#define DIVA_4_H                         (0x0004)
#define DIVA_5                           (0x0500)        /* /32 */
#define DIVA_5_H                         (0x0005)
#define DIVA__1                          (0x0000)        /* /1 */
#define DIVA__2                          (0x0100)        /* /2 */
#define DIVA__2_H                        (0x0001)
#define DIVA__4                          (0x0200)        /* /4 */
#define DIVA__4_H                        (0x0002)
#define DIVA__8                          (0x0300)        /* /8 */
#define DIVA__8_H                        (0x0003)
#define DIVA__16                         (0x0400)        /* /16 */
#define DIVA__16_H                       (0x0004)
#define DIVA__32                         (0x0500)        /* /32 */
#define DIVA__32_H                       (0x0005)

/* CSCTL4 Control Bits */
#define LFXTOFF                          (0x0001)        /* LFXT off */
#define LFXTOFF_L                        (0x0001)
#define LFXTOFF_0                        (0x0000)        /* LFXT is on if LFXT is selected via the port selection and LFXT
                                                            is not in bypass mode of operation */
#define LFXTOFF_1                        (0x0001)        /* LFXT is off if it is not used as a source for ACLK, MCLK, or 
                                                            SMCLK */
#define LFXTOFF_1_L                      (0x0001)
#define SMCLKOFF                         (0x0002)        /* SMCLK off */
#define SMCLKOFF_L                       (0x0002)
#define SMCLKOFF_0                       (0x0000)        /* SMCLK on */
#define SMCLKOFF_1                       (0x0002)        /* SMCLK off */
#define SMCLKOFF_1_L                     (0x0002)
#define VLOOFF                           (0x0008)        /* VLO off */
#define VLOOFF_L                         (0x0008)
#define VLOOFF_0                         (0x0000)        /* VLO is on */
#define VLOOFF_1                         (0x0008)        /* VLO is off if it is not used as a source for ACLK, MCLK, or 
                                                            SMCLK or if not used as a source for the RTC in LPM3.5 */
#define VLOOFF_1_L                       (0x0008)
#define LFXTBYPASS                       (0x0010)        /* LFXT bypass select */
#define LFXTBYPASS_L                     (0x0010)
#define LFXTBYPASS_0                     (0x0000)        /* LFXT sourced from external crystal */
#define LFXTBYPASS_1                     (0x0010)        /* LFXT sourced from external clock signal */
#define LFXTBYPASS_1_L                   (0x0010)
#define LFXTDRIVE                        (0x00c0)        /* LFXT oscillator current */
#define LFXTDRIVE_L                      (0x00c0)
#define LFXTDRIVE0                       (0x0040)        /* LFXT oscillator current */
#define LFXTDRIVE0_L                     (0x0040)
#define LFXTDRIVE1                       (0x0080)        /* LFXT oscillator current */
#define LFXTDRIVE1_L                     (0x0080)
#define LFXTDRIVE_0                      (0x0000)        /* Lowest drive strength and current consumption LFXT oscillator */
#define LFXTDRIVE_1                      (0x0040)        /* Increased drive strength LFXT oscillator */
#define LFXTDRIVE_1_L                    (0x0040)
#define LFXTDRIVE_2                      (0x0080)        /* Increased drive strength LFXT oscillator */
#define LFXTDRIVE_2_L                    (0x0080)
#define LFXTDRIVE_3                      (0x00c0)        /* Maximum drive strength and maximum current consumption LFXT 
                                                            oscillator */
#define LFXTDRIVE_3_L                    (0x00c0)
#define HFXTOFF                          (0x0100)        /* Turns off the HFXT oscillator */
#define HFXTOFF_H                        (0x0001)
#define HFXTOFF_0                        (0x0000)        /* HFXT is on if HFXT is selected via the port selection and HFXT
                                                            is not in bypass mode of operation */
#define HFXTOFF_1                        (0x0100)        /* HFXT is off if it is not used as a source for ACLK, MCLK, or 
                                                            SMCLK */
#define HFXTOFF_1_H                      (0x0001)
#define HFFREQ                           (0x0c00)        /* HFXT frequency selection */
#define HFFREQ_H                         (0x000c)
#define HFFREQ0                          (0x0400)        /* HFXT frequency selection */
#define HFFREQ0_H                        (0x0004)
#define HFFREQ1                          (0x0800)        /* HFXT frequency selection */
#define HFFREQ1_H                        (0x0008)
#define HFFREQ_0                         (0x0000)        /* 0 to 4 MHz */
#define HFFREQ_1                         (0x0400)        /* Greater than 4 MHz to 8 MHz */
#define HFFREQ_1_H                       (0x0004)
#define HFFREQ_2                         (0x0800)        /* Greater than 8 MHz to 16 MHz */
#define HFFREQ_2_H                       (0x0008)
#define HFFREQ_3                         (0x0c00)        /* Greater than 16 MHz to 24 MHz */
#define HFFREQ_3_H                       (0x000c)
#define HFXTBYPASS                       (0x1000)        /* HFXT bypass select */
#define HFXTBYPASS_H                     (0x0010)
#define HFXTBYPASS_0                     (0x0000)        /* HFXT sourced from external crystal */
#define HFXTBYPASS_1                     (0x1000)        /* HFXT sourced from external clock signal */
#define HFXTBYPASS_1_H                   (0x0010)
#define HFXTDRIVE                        (0xc000)        /* HFXT oscillator current */
#define HFXTDRIVE_H                      (0x00c0)
#define HFXTDRIVE0                       (0x4000)        /* HFXT oscillator current */
#define HFXTDRIVE0_H                     (0x0040)
#define HFXTDRIVE1                       (0x8000)        /* HFXT oscillator current */
#define HFXTDRIVE1_H                     (0x0080)
#define HFXTDRIVE_0                      (0x0000)        /* Lowest current consumption */
#define HFXTDRIVE_1                      (0x4000)        /* Increased drive strength HFXT oscillator */
#define HFXTDRIVE_1_H                    (0x0040)
#define HFXTDRIVE_2                      (0x8000)        /* Increased drive strength HFXT oscillator */
#define HFXTDRIVE_2_H                    (0x0080)
#define HFXTDRIVE_3                      (0xc000)        /* Maximum drive strength HFXT oscillator */
#define HFXTDRIVE_3_H                    (0x00c0)

/* CSCTL5 Control Bits */
#define LFXTOFFG                         (0x0001)        /* LFXT oscillator fault flag */
#define LFXTOFFG_L                       (0x0001)
#define LFXTOFFG_0                       (0x0000)        /* No fault condition occurred after the last reset */
#define LFXTOFFG_1                       (0x0001)        /* LFXT fault; an LFXT fault occurred after the last reset */
#define LFXTOFFG_1_L                     (0x0001)
#define HFXTOFFG                         (0x0002)        /* HFXT oscillator fault flag */
#define HFXTOFFG_L                       (0x0002)
#define HFXTOFFG_0                       (0x0000)        /* No fault condition occurred after the last reset */
#define HFXTOFFG_1                       (0x0002)        /* HFXT fault; an HFXT fault occurred after the last reset */
#define HFXTOFFG_1_L                     (0x0002)
#define ENSTFCNT1                        (0x0040)        /* Enable start counter for LFXT */
#define ENSTFCNT1_L                      (0x0040)
#define ENSTFCNT1_0                      (0x0000)        /* Startup fault counter disabled. Counter is cleared. */
#define ENSTFCNT1_1                      (0x0040)        /* Startup fault counter enabled */
#define ENSTFCNT1_1_L                    (0x0040)
#define ENSTFCNT1__DISABLE               (0x0000)        /* Startup fault counter disabled. Counter is cleared. */
#define ENSTFCNT1__ENABLE                (0x0040)        /* Startup fault counter enabled */
#define ENSTFCNT1__ENABLE_L              (0x0040)
#define ENSTFCNT2                        (0x0080)        /* Enable start counter for HFXT */
#define ENSTFCNT2_L                      (0x0080)
#define ENSTFCNT2_0                      (0x0000)        /* Startup fault counter disabled. Counter is cleared. */
#define ENSTFCNT2_1                      (0x0080)        /* Startup fault counter enabled */
#define ENSTFCNT2_1_L                    (0x0080)
#define ENSTFCNT2__DISABLE               (0x0000)        /* Startup fault counter disabled. Counter is cleared. */
#define ENSTFCNT2__ENABLE                (0x0080)        /* Startup fault counter enabled */
#define ENSTFCNT2__ENABLE_L              (0x0080)

/* CSCTL6 Control Bits */
#define ACLKREQEN                        (0x0001)        /* ACLK clock request enable */
#define ACLKREQEN_L                      (0x0001)
#define ACLKREQEN_0                      (0x0000)        /* ACLK conditional requests are disabled */
#define ACLKREQEN_1                      (0x0001)        /* ACLK conditional requests are enabled */
#define ACLKREQEN_1_L                    (0x0001)
#define ACLKREQEN__DISABLE               (0x0000)        /* ACLK conditional requests are disabled */
#define ACLKREQEN__ENABLE                (0x0001)        /* ACLK conditional requests are enabled */
#define ACLKREQEN__ENABLE_L              (0x0001)
#define MCLKREQEN                        (0x0002)        /* MCLK clock request enable */
#define MCLKREQEN_L                      (0x0002)
#define MCLKREQEN_0                      (0x0000)        /* MCLK conditional requests are disabled */
#define MCLKREQEN_1                      (0x0002)        /* MCLK conditional requests are enabled */
#define MCLKREQEN_1_L                    (0x0002)
#define MCLKREQEN__DISABLE               (0x0000)        /* MCLK conditional requests are disabled */
#define MCLKREQEN__ENABLE                (0x0002)        /* MCLK conditional requests are enabled */
#define MCLKREQEN__ENABLE_L              (0x0002)
#define SMCLKREQEN                       (0x0004)        /* SMCLK clock request enable */
#define SMCLKREQEN_L                     (0x0004)
#define SMCLKREQEN_0                     (0x0000)        /* SMCLK conditional requests are disabled */
#define SMCLKREQEN_1                     (0x0004)        /* SMCLK conditional requests are enabled */
#define SMCLKREQEN_1_L                   (0x0004)
#define SMCLKREQEN__DISABLE              (0x0000)        /* SMCLK conditional requests are disabled */
#define SMCLKREQEN__ENABLE               (0x0004)        /* SMCLK conditional requests are enabled */
#define SMCLKREQEN__ENABLE_L             (0x0004)
#define MODCLKREQEN                      (0x0008)        /* MODCLK clock request enable */
#define MODCLKREQEN_L                    (0x0008)
#define MODCLKREQEN_0                    (0x0000)        /* MODCLK conditional requests are disabled */
#define MODCLKREQEN_1                    (0x0008)        /* MODCLK conditional requests are enabled */
#define MODCLKREQEN_1_L                  (0x0008)
#define MODCLKREQEN__DISABLE             (0x0000)        /* MODCLK conditional requests are disabled */
#define MODCLKREQEN__ENABLE              (0x0008)        /* MODCLK conditional requests are enabled */
#define MODCLKREQEN__ENABLE_L            (0x0008)

/* UCA0CTLW0_SPI Control Bits */
#define UCSTEM                           (0x0002)        /* STE mode select in master mode. */
#define UCSTEM_L                         (0x0002)
#define UCSTEM_0                         (0x0000)        /* STE pin is used to prevent conflicts with other masters */
#define UCSTEM_1                         (0x0002)        /* STE pin is used to generate the enable signal for a 4-wire 
                                                            slave */
#define UCSTEM_1_L                       (0x0002)
#define UCMST                            (0x0800)        /* Master mode select */
#define UCMST_H                          (0x0008)
#define UCMST_0                          (0x0000)        /* Slave mode */
#define UCMST_1                          (0x0800)        /* Master mode */
#define UCMST_1_H                        (0x0008)
#define UCMST__SLAVE                     (0x0000)        /* Slave mode */
#define UCMST__MASTER                    (0x0800)        /* Master mode */
#define UCMST__MASTER_H                  (0x0008)
#define UCCKPL                           (0x4000)        /* Clock polarity select */
#define UCCKPL_H                         (0x0040)
#define UCCKPL_0                         (0x0000)        /* The inactive state is low */
#define UCCKPL_1                         (0x4000)        /* The inactive state is high */
#define UCCKPL_1_H                       (0x0040)
#define UCCKPL__LOW                      (0x0000)        /* The inactive state is low */
#define UCCKPL__HIGH                     (0x4000)        /* The inactive state is high */
#define UCCKPL__HIGH_H                   (0x0040)
#define UCCKPH                           (0x8000)        /* Clock phase select */
#define UCCKPH_H                         (0x0080)
#define UCCKPH_0                         (0x0000)        /* Data is changed on the first UCLK edge and captured on the 
                                                            following edge. */
#define UCCKPH_1                         (0x8000)        /* Data is captured on the first UCLK edge and changed on the 
                                                            following edge. */
#define UCCKPH_1_H                       (0x0080)

/* UCA0CTLW1 Control Bits */
#define UCGLIT                           (0x0003)        /


#define __MSP430_BASEADDRESS_TA0__ 0x0340
#define TA0_BASE               __MSP430_BASEADDRESS_TA0__

/* TA0CTL Control Bits */
#define TAIFG                            (0x0001)        /* TimerA interrupt flag */
#define TAIFG_L                          (0x0001)
#define TAIFG_0                          (0x0000)        /* No interrupt pending */
#define TAIFG_1                          (0x0001)        /* Interrupt pending */
#define TAIFG_1_L                        (0x0001)
#define TAIE                             (0x0002)        /* TimerA interrupt enable */
#define TAIE_L                           (0x0002)
#define TAIE_0                           (0x0000)        /* Interrupt disabled */
#define TAIE_1                           (0x0002)        /* Interrupt enabled */
#define TAIE_1_L                         (0x0002)
#define TACLR                            (0x0004)        /* TimerA clear */
#define TACLR_L                          (0x0004)
#define MC                               (0x0030)        /* Mode control */
#define MC_L                             (0x0030)
#define MC0                              (0x0010)        /* Mode control */
#define MC0_L                            (0x0010)
#define MC1                              (0x0020)        /* Mode control */
#define MC1_L                            (0x0020)
#define MC_0                             (0x0000)        /* Stop mode: Timer is halted */
#define MC_1                             (0x0010)        /* Up mode: Timer counts up to TAxCCR0 */
#define MC_1_L                           (0x0010)
#define MC_2                             (0x0020)        /* Continuous mode: Timer counts up to 0FFFFh */
#define MC_2_L                           (0x0020)
#define MC_3                             (0x0030)        /* Up/down mode: Timer counts up to TAxCCR0 then down to 0000h */
#define MC_3_L                           (0x0030)
#define MC__STOP                         (0x0000)        /* Stop mode: Timer is halted */
#define MC__UP                           (0x0010)        /* Up mode: Timer counts up to TAxCCR0 */
#define MC__UP_L                         (0x0010)
#define MC__CONTINUOUS                   (0x0020)        /* Continuous mode: Timer counts up to 0FFFFh */
#define MC__CONTINUOUS_L                 (0x0020)
#define MC__UPDOWN                       (0x0030)        /* Up/down mode: Timer counts up to TAxCCR0 then down to 0000h */
#define MC__UPDOWN_L                     (0x0030)
#define ID                               (0x00c0)        /* Input divider */
#define ID_L                             (0x00c0)
#define ID0                              (0x0040)        /* Input divider */
#define ID0_L                            (0x0040)
#define ID1                              (0x0080)        /* Input divider */
#define ID1_L                            (0x0080)
#define ID_0                             (0x0000)        /* /1 */
#define ID_1                             (0x0040)        /* /2 */
#define ID_1_L                           (0x0040)
#define ID_2                             (0x0080)        /* /4 */
#define ID_2_L                           (0x0080)
#define ID_3                             (0x00c0)        /* /8 */
#define ID_3_L                           (0x00c0)
#define ID__1                            (0x0000)        /* /1 */
#define ID__2                            (0x0040)        /* /2 */
#define ID__2_L                          (0x0040)
#define ID__4                            (0x0080)        /* /4 */
#define ID__4_L                          (0x0080)
#define ID__8                            (0x00c0)        /* /8 */
#define ID__8_L                          (0x00c0)
#define TASSEL                           (0x0300)        /* TimerA clock source select */
#define TASSEL_H                         (0x0003)
#define TASSEL0                          (0x0100)        /* TimerA clock source select */
#define TASSEL0_H                        (0x0001)
#define TASSEL1                          (0x0200)        /* TimerA clock source select */
#define TASSEL1_H                        (0x0002)
#define TASSEL_0                         (0x0000)        /* TAxCLK */
#define TASSEL_1                         (0x0100)        /* ACLK */
#define TASSEL_1_H                       (0x0001)
#define TASSEL_2                         (0x0200)        /* SMCLK */
#define TASSEL_2_H                       (0x0002)
#define TASSEL_3                         (0x0300)        /* INCLK */
#define TASSEL_3_H                       (0x0003)
#define TASSEL__TACLK                    (0x0000)        /* TAxCLK */
#define TASSEL__ACLK                     (0x0100)        /* ACLK */
#define TASSEL__ACLK_H                   (0x0001)
#define TASSEL__SMCLK                    (0x0200)        /* SMCLK */
#define TASSEL__SMCLK_H                  (0x0002)
#define TASSEL__INCLK                    (0x0300)        /* INCLK */
#define TASSEL__INCLK_H                  (0x0003)

/* TA0CCTL Control Bits */
#define CCIFG                            (0x0001)        /* Capture/compare interrupt flag */
#define CCIFG_L                          (0x0001)
#define CCIFG_0                          (0x0000)        /* No interrupt pending */
#define CCIFG_1                          (0x0001)        /* Interrupt pending */
#define CCIFG_1_L                        (0x0001)
#define COV                              (0x0002)        /* Capture overflow */
#define COV_L                            (0x0002)
#define COV_0                            (0x0000)        /* No capture overflow occurred */
#define COV_1                            (0x0002)        /* Capture overflow occurred */
#define COV_1_L                          (0x0002)
#define OUT                              (0x0004)        /* Output */
#define OUT_L                            (0x0004)
#define OUT_0                            (0x0000)        /* Output low */
#define OUT_1                            (0x0004)        /* Output high */
#define OUT_1_L                          (0x0004)
#define OUT__LOW                         (0x0000)        /* Output low */
#define OUT__HIGH                        (0x0004)        /* Output high */
#define OUT__HIGH_L                      (0x0004)
#define CCI                              (0x0008)        /* Capture/compare input */
#define CCI_L                            (0x0008)
#define CCIE                             (0x0010)        /* Capture/compare interrupt enable */
#define CCIE_L                           (0x0010)
#define CCIE_0                           (0x0000)        /* Interrupt disabled */
#define CCIE_1                           (0x0010)        /* Interrupt enabled */
#define CCIE_1_L                         (0x0010)
#define OUTMOD                           (0x00e0)        /* Output mode */
#define OUTMOD_L                         (0x00e0)
#define OUTMOD0                          (0x0020)        /* Output mode */
#define OUTMOD0_L                        (0x0020)
#define OUTMOD1                          (0x0040)        /* Output mode */
#define OUTMOD1_L                        (0x0040)
#define OUTMOD2                          (0x0080)        /* Output mode */
#define OUTMOD2_L                        (0x0080)
#define OUTMOD_0                         (0x0000)        /* OUT bit value */
#define OUTMOD_1                         (0x0020)        /* Set */
#define OUTMOD_1_L                       (0x0020)
#define OUTMOD_2                         (0x0040)        /* Toggle/reset */
#define OUTMOD_2_L                       (0x0040)
#define OUTMOD_3                         (0x0060)        /* Set/reset */
#define OUTMOD_3_L                       (0x0060)
#define OUTMOD_4                         (0x0080)        /* Toggle */
#define OUTMOD_4_L                       (0x0080)
#define OUTMOD_5                         (0x00a0)        /* Reset */
#define OUTMOD_5_L                       (0x00a0)
#define OUTMOD_6                         (0x00c0)        /* Toggle/set */
#define OUTMOD_6_L                       (0x00c0)
#define OUTMOD_7                         (0x00e0)        /* Reset/set */
#define OUTMOD_7_L                       (0x00e0)
#define CAP                              (0x0100)        /* Capture mode */
#define CAP_H                            (0x0001)
#define CAP_0                            (0x0000)        /* Compare mode */
#define CAP_1                            (0x0100)        /* Capture mode */
#define CAP_1_H                          (0x0001)
#define CAP__COMPARE                     (0x0000)        /* Compare mode */
#define CAP__CAPTURE                     (0x0100)        /* Capture mode */
#define CAP__CAPTURE_H                   (0x0001)
#define SCCI                             (0x0400)        /* Synchronized capture/compare input */
#define SCCI_H                           (0x0004)
#define SCS                              (0x0800)        /* Synchronize capture source */
#define SCS_H                            (0x0008)
#define SCS_0                            (0x0000)        /* Asynchronous capture */
#define SCS_1                            (0x0800)        /* Synchronous capture */
#define SCS_1_H                          (0x0008)
#define SCS__ASYNC                       (0x0000)        /* Asynchronous capture */
#define SCS__SYNC                        (0x0800)        /* Synchronous capture */
#define SCS__SYNC_H                      (0x0008)
#define CCIS                             (0x3000)        /* Capture/compare input select */
#define CCIS_H                           (0x0030)
#define CCIS0                            (0x1000)        /* Capture/compare input select */
#define CCIS0_H                          (0x0010)
#define CCIS1                            (0x2000)        /* Capture/compare input select */
#define CCIS1_H                          (0x0020)
#define CCIS_0                           (0x0000)        /* CCIxA */
#define CCIS_1                           (0x1000)        /* CCIxB */
#define CCIS_1_H                         (0x0010)
#define CCIS_2                           (0x2000)        /* GND */
#define CCIS_2_H                         (0x0020)
#define CCIS_3                           (0x3000)        /* VCC */
#define CCIS_3_H                         (0x0030)
#define CCIS__CCIA                       (0x0000)        /* CCIxA */
#define CCIS__CCIB                       (0x1000)        /* CCIxB */
#define CCIS__CCIB_H                     (0x0010)
#define CCIS__GND                        (0x2000)        /* GND */
#define CCIS__GND_H                      (0x0020)
#define CCIS__VCC                        (0x3000)        /* VCC */
#define CCIS__VCC_H                      (0x0030)
#define CM                               (0xc000)        /* Capture mode */
#define CM_H                             (0x00c0)
#define CM0                              (0x4000)        /* Capture mode */
#define CM0_H                            (0x0040)
#define CM1                              (0x8000)        /* Capture mode */
#define CM1_H                            (0x0080)
#define CM_0                             (0x0000)        /* No capture */
#define CM_1                             (0x4000)        /* Capture on rising edge */
#define CM_1_H                           (0x0040)
#define CM_2                             (0x8000)        /* Capture on falling edge */
#define CM_2_H                           (0x0080)
#define CM_3                             (0xc000)        /* Capture on both rising and falling edges */
#define CM_3_H                           (0x00c0)
#define CM__NONE                         (0x0000)        /* No capture */
#define CM__RISING                       (0x4000)        /* Capture on rising edge */
#define CM__RISING_H                     (0x0040)
#define CM__FALLING                      (0x8000)        /* Capture on falling edge */
#define CM__FALLING_H                    (0x0080)
#define CM__BOTH                         (0xc000)        /* Capture on both rising and falling edges */
#define CM__BOTH_H                       (0x00c0)

/* TA0R Control Bits */
#define TAXR                             (0xffff)        /* Timer_A count register */
#define TAXR_L                           (0x00ff)
#define TAXR_H                           (0x00ff)
#define TAXR0                            (0x0001)        /* Timer_A count register */
#define TAXR0_L                          (0x0001)
#define TAXR1                            (0x0002)        /* Timer_A count register */
#define TAXR1_L                          (0x0002)
#define TAXR2                            (0x0004)        /* Timer_A count register */
#define TAXR2_L                          (0x0004)
#define TAXR3                            (0x0008)        /* Timer_A count register */
#define TAXR3_L                          (0x0008)
#define TAXR4                            (0x0010)        /* Timer_A count register */
#define TAXR4_L                          (0x0010)
#define TAXR5                            (0x0020)        /* Timer_A count register */
#define TAXR5_L                          (0x0020)
#define TAXR6                            (0x0040)        /* Timer_A count register */
#define TAXR6_L                          (0x0040)
#define TAXR7                            (0x0080)        /* Timer_A count register */
#define TAXR7_L                          (0x0080)
#define TAXR8                            (0x0100)        /* Timer_A count register */
#define TAXR8_H                          (0x0001)
#define TAXR9                            (0x0200)        /* Timer_A count register */
#define TAXR9_H                          (0x0002)
#define TAXR10                           (0x0400)        /* Timer_A count register */
#define TAXR10_H                         (0x0004)
#define TAXR11                           (0x0800)        /* Timer_A count register */
#define TAXR11_H                         (0x0008)
#define TAXR12                           (0x1000)        /* Timer_A count register */
#define TAXR12_H                         (0x0010)
#define TAXR13                           (0x2000)        /* Timer_A count register */
#define TAXR13_H                         (0x0020)
#define TAXR14                           (0x4000)        /* Timer_A count register */
#define TAXR14_H                         (0x0040)
#define TAXR15                           (0x8000)        /* Timer_A count register */
#define TAXR15_H                         (0x0080)

/* TA0EX0 Control Bits */
#define TAIDEX                           (0x0007)        /* Input divider expansion */
#define TAIDEX_L                         (0x0007)
#define TAIDEX0                          (0x0001)        /* Input divider expansion */
#define TAIDEX0_L                        (0x0001)
#define TAIDEX1                          (0x0002)        /* Input divider expansion */
#define TAIDEX1_L                        (0x0002)
#define TAIDEX2                          (0x0004)        /* Input divider expansion */
#define TAIDEX2_L                        (0x0004)
#define TAIDEX_0                         (0x0000)        /* Divide by 1 */
#define TAIDEX_1                         (0x0001)        /* Divide by 2 */
#define TAIDEX_1_L                       (0x0001)
#define TAIDEX_2                         (0x0002)        /* Divide by 3 */
#define TAIDEX_2_L                       (0x0002)
#define TAIDEX_3                         (0x0003)        /* Divide by 4 */
#define TAIDEX_3_L                       (0x0003)
#define TAIDEX_4                         (0x0004)        /* Divide by 5 */
#define TAIDEX_4_L                       (0x0004)
#define TAIDEX_5                         (0x0005)        /* Divide by 6 */
#define TAIDEX_5_L                       (0x0005)
#define TAIDEX_6                         (0x0006)        /* Divide by 7 */
#define TAIDEX_6_L                       (0x0006)
#define TAIDEX_7                         (0x0007)        /* Divide by 8 */
#define TAIDEX_7_L                       (0x0007)
#define TAIDEX__1                        (0x0000)        /* Divide by 1 */
#define TAIDEX__2                        (0x0001)        /* Divide by 2 */
#define TAIDEX__2_L                      (0x0001)
#define TAIDEX__3                        (0x0002)        /* Divide by 3 */
#define TAIDEX__3_L                      (0x0002)
#define TAIDEX__4                        (0x0003)        /* Divide by 4 */
#define TAIDEX__4_L                      (0x0003)
#define TAIDEX__5                        (0x0004)        /* Divide by 5 */
#define TAIDEX__5_L                      (0x0004)
#define TAIDEX__6                        (0x0005)        /* Divide by 6 */
#define TAIDEX__6_L                      (0x0005)
#define TAIDEX__7                        (0x0006)        /* Divide by 7 */
#define TAIDEX__7_L                      (0x0006)
#define TAIDEX__8                        (0x0007)        /* Divide by 8 */
#define TAIDEX__8_L                      (0x0007)

/* TA0IV Control Bits */
#define TAIV                             (0xffff)        /* TimerA interrupt vector value */
#define TAIV_L                           (0x00ff)
#define TAIV_H                           (0x00ff)
#define TAIV0                            (0x0001)        /* TimerA interrupt vector value */
#define TAIV0_L                          (0x0001)
#define TAIV1                            (0x0002)        /* TimerA interrupt vector value */
#define TAIV1_L                          (0x0002)
#define TAIV2                            (0x0004)        /* TimerA interrupt vector value */
#define TAIV2_L                          (0x0004)
#define TAIV3                            (0x0008)        /* TimerA interrupt vector value */
#define TAIV3_L                          (0x0008)
#define TAIV4                            (0x0010)        /* TimerA interrupt vector value */
#define TAIV4_L                          (0x0010)
#define TAIV5                            (0x0020)        /* TimerA interrupt vector value */
#define TAIV5_L                          (0x0020)
#define TAIV6                            (0x0040)        /* TimerA interrupt vector value */
#define TAIV6_L                          (0x0040)
#define TAIV7                            (0x0080)        /* TimerA interrupt vector value */
#define TAIV7_L                          (0x0080)
#define TAIV8                            (0x0100)        /* TimerA interrupt vector value */
#define TAIV8_H                          (0x0001)
#define TAIV9                            (0x0200)        /* TimerA interrupt vector value */
#define TAIV9_H                          (0x0002)
#define TAIV10                           (0x0400)        /* TimerA interrupt vector value */
#define TAIV10_H                         (0x0004)
#define TAIV11                           (0x0800)        /* TimerA interrupt vector value */
#define TAIV11_H                         (0x0008)
#define TAIV12                           (0x1000)        /* TimerA interrupt vector value */
#define TAIV12_H                         (0x0010)
#define TAIV13                           (0x2000)        /* TimerA interrupt vector value */
#define TAIV13_H                         (0x0020)
#define TAIV14                           (0x4000)        /* TimerA interrupt vector value */
#define TAIV14_H                         (0x0040)
#define TAIV15                           (0x8000)        /* TimerA interrupt vector value */
#define TAIV15_H                         (0x0080)
#define TAIV_0                           (0x0000)        /* No interrupt pending */
#define TAIV_2                           (0x0002)        /* Interrupt Source: Capture/compare 1; Interrupt Flag: TAxCCR1 
                                                            CCIFG; Interrupt Priority: Highest */
#define TAIV_2_L                         (0x0002)
#define TAIV_4                           (0x0004)        /* Interrupt Source: Capture/compare 2; Interrupt Flag: TAxCCR2 
                                                            CCIFG */
#define TAIV_4_L                         (0x0004)
#define TAIV_6                           (0x0006)        /* Interrupt Source: Capture/compare 3; Interrupt Flag: TAxCCR3 
                                                            CCIFG */
#define TAIV_6_L                         (0x0006)
#define TAIV_8                           (0x0008)        /* Interrupt Source: Capture/compare 4; Interrupt Flag: TAxCCR4 
                                                            CCIFG */
#define TAIV_8_L                         (0x0008)
#define TAIV_10                          (0x000a)        /* Interrupt Source: Capture/compare 5; Interrupt Flag: TAxCCR5 
                                                            CCIFG */
#define TAIV_10_L                        (0x000a)
#define TAIV_12                          (0x000c)        /* Interrupt Source: Capture/compare 6; Interrupt Flag: TAxCCR6 
                                                            CCIFG */
#define TAIV_12_L                        (0x000c)
#define TAIV_14                          (0x000e)        /* Interrupt Source: Timer overflow; Interrupt Flag: TAxCTL TAIFG;
                                                            Interrupt Priority: Lowest */
#define TAIV_14_L                        (0x000e)
#define TAIV__NONE                       (0x0000)        /* No interrupt pending */
#define TAIV__TACCR1                     (0x0002)        /* Interrupt Source: Capture/compare 1; Interrupt Flag: TAxCCR1 
                                                            CCIFG; Interrupt Priority: Highest */
#define TAIV__TACCR1_L                   (0x0002)
#define TAIV__TACCR2                     (0x0004)        /* Interrupt Source: Capture/compare 2; Interrupt Flag: TAxCCR2 
                                                            CCIFG */
#define TAIV__TACCR2_L                   (0x0004)
#define TAIV__TACCR3                     (0x0006)        /* Interrupt Source: Capture/compare 3; Interrupt Flag: TAxCCR3 
                                                            CCIFG */
#define TAIV__TACCR3_L                   (0x0006)
#define TAIV__TACCR4                     (0x0008)        /* Interrupt Source: Capture/compare 4; Interrupt Flag: TAxCCR4 
                                                            CCIFG */
#define TAIV__TACCR4_L                   (0x0008)
#define TAIV__TACCR5                     (0x000a)        /* Interrupt Source: Capture/compare 5; Interrupt Flag: TAxCCR5 
                                                            CCIFG */
#define TAIV__TACCR5_L                   (0x000a)
#define TAIV__TACCR6                     (0x000c)        /* Interrupt Source: Capture/compare 6; Interrupt Flag: TAxCCR6 
                                                            CCIFG */
#define TAIV__TACCR6_L                   (0x000c)
#define TAIV__TAIFG                      (0x000e)        /* Interrupt Source: Timer overflow; Interrupt Flag: TAxCTL TAIFG;
                                                            Interrupt Priority: Lowest */
#define TAIV__TAIFG_L                    (0x000e)

#define __MSP430_BASEADDRESS_TB0__ 0x03C0
#define TB0_BASE               __MSP430_BASEADDRESS_TB0__


/* TB0CTL Control Bits */
#define TBIFG                            (0x0001)        /* TimerB interrupt flag */
#define TBIFG_L                          (0x0001)
#define TBIFG_0                          (0x0000)        /* No interrupt pending */
#define TBIFG_1                          (0x0001)        /* Interrupt pending */
#define TBIFG_1_L                        (0x0001)
#define TBIE                             (0x0002)        /* TimerB interrupt enable */
#define TBIE_L                           (0x0002)
#define TBIE_0                           (0x0000)        /* Interrupt disabled */
#define TBIE_1                           (0x0002)        /* Interrupt enabled */
#define TBIE_1_L                         (0x0002)
#define TBCLR                            (0x0004)        /* TimerB clear */
#define TBCLR_L                          (0x0004)
#define TBSSEL                           (0x0300)        /* TimerB clock source select */
#define TBSSEL_H                         (0x0003)
#define TBSSEL0                          (0x0100)        /* TimerB clock source select */
#define TBSSEL0_H                        (0x0001)
#define TBSSEL1                          (0x0200)        /* TimerB clock source select */
#define TBSSEL1_H                        (0x0002)
#define TBSSEL_0                         (0x0000)        /* TBxCLK */
#define TBSSEL_1                         (0x0100)        /* ACLK */
#define TBSSEL_1_H                       (0x0001)
#define TBSSEL_2                         (0x0200)        /* SMCLK */
#define TBSSEL_2_H                       (0x0002)
#define TBSSEL_3                         (0x0300)        /* INCLK */
#define TBSSEL_3_H                       (0x0003)
#define TBSSEL__TBCLK                    (0x0000)        /* TBxCLK */
#define TBSSEL__ACLK                     (0x0100)        /* ACLK */
#define TBSSEL__ACLK_H                   (0x0001)
#define TBSSEL__SMCLK                    (0x0200)        /* SMCLK */
#define TBSSEL__SMCLK_H                  (0x0002)
#define TBSSEL__INCLK                    (0x0300)        /* INCLK */
#define TBSSEL__INCLK_H                  (0x0003)
#define CNTL                             (0x1800)        /* Counter length */
#define CNTL_H                           (0x0018)
#define CNTL0                            (0x0800)        /* Counter length */
#define CNTL0_H                          (0x0008)
#define CNTL1                            (0x1000)        /* Counter length */
#define CNTL1_H                          (0x0010)
#define CNTL_0                           (0x0000)        /* 16-bit, TBxR(max) = 0FFFFh */
#define CNTL_1                           (0x0800)        /* 12-bit, TBxR(max) = 0FFFh */
#define CNTL_1_H                         (0x0008)
#define CNTL_2                           (0x1000)        /* 10-bit, TBxR(max) = 03FFh */
#define CNTL_2_H                         (0x0010)
#define CNTL_3                           (0x1800)        /* 8-bit, TBxR(max) = 0FFh */
#define CNTL_3_H                         (0x0018)
#define CNTL__16                         (0x0000)        /* 16-bit, TBxR(max) = 0FFFFh */
#define CNTL__12                         (0x0800)        /* 12-bit, TBxR(max) = 0FFFh */
#define CNTL__12_H                       (0x0008)
#define CNTL__10                         (0x1000)        /* 10-bit, TBxR(max) = 03FFh */
#define CNTL__10_H                       (0x0010)
#define CNTL__8                          (0x1800)        /* 8-bit, TBxR(max) = 0FFh */
#define CNTL__8_H                        (0x0018)
#define TBCLGRP                          (0x6000)        /* TBxCLn group */
#define TBCLGRP_H                        (0x0060)
#define TBCLGRP0                         (0x2000)        /* TBxCLn group */
#define TBCLGRP0_H                       (0x0020)
#define TBCLGRP1                         (0x4000)        /* TBxCLn group */
#define TBCLGRP1_H                       (0x0040)
#define TBCLGRP_0                        (0x0000)        /* Each TBxCLn latch loads independently */
#define TBCLGRP_1                        (0x2000)        /* TBxCL1+TBxCL2 (TBxCCR1 CLLD bits control the update); TBxCL3+
                                                            TBxCL4 (TBxCCR3 CLLD bits control the update); TBxCL5+TBxCL6 (
                                                            TBxCCR5 CLLD bits control the update); TBxCL0 independent */
#define TBCLGRP_1_H                      (0x0020)
#define TBCLGRP_2                        (0x4000)        /* TBxCL1+TBxCL2+TBxCL3 (TBxCCR1 CLLD bits control the update); 
                                                            TBxCL4+TBxCL5+TBxCL6 (TBxCCR4 CLLD bits control the update); 
                                                            TBxCL0 independent */
#define TBCLGRP_2_H                      (0x0040)
#define TBCLGRP_3                        (0x6000)        /* TBxCL0+TBxCL1+TBxCL2+TBxCL3+TBxCL4+TBxCL5+TBxCL6 (TBxCCR1 CLLD
                                                            bits control the update) */
#define TBCLGRP_3_H                      (0x0060)

/* TB0CCTL Control Bits */
#define CLLD                             (0x0600)        /* Compare latch load */
#define CLLD_H                           (0x0006)
#define CLLD0                            (0x0200)        /* Compare latch load */
#define CLLD0_H                          (0x0002)
#define CLLD1                            (0x0400)        /* Compare latch load */
#define CLLD1_H                          (0x0004)
#define CLLD_0                           (0x0000)        /* TBxCLn loads on write to TBxCCRn */
#define CLLD_1                           (0x0200)        /* TBxCLn loads when TBxR counts to 0 */
#define CLLD_1_H                         (0x0002)
#define CLLD_2                           (0x0400)        /* TBxCLn loads when TBxR counts to 0 (up or continuous mode). 
                                                            TBxCLn loads when TBxR counts to TBxCL0 or to 0 (up/down mode).
 */
#define CLLD_2_H                         (0x0004)
#define CLLD_3                           (0x0600)        /* TBxCLn loads when TBxR counts to TBxCLn */
#define CLLD_3_H                         (0x0006)

/* TB0R Control Bits */
#define TBXR                             (0xffff)        /* Timer_B count register */
#define TBXR_L                           (0x00ff)
#define TBXR_H                           (0x00ff)
#define TBXR0                            (0x0001)        /* Timer_B count register */
#define TBXR0_L                          (0x0001)
#define TBXR1                            (0x0002)        /* Timer_B count register */
#define TBXR1_L                          (0x0002)
#define TBXR2                            (0x0004)        /* Timer_B count register */
#define TBXR2_L                          (0x0004)
#define TBXR3                            (0x0008)        /* Timer_B count register */
#define TBXR3_L                          (0x0008)
#define TBXR4                            (0x0010)        /* Timer_B count register */
#define TBXR4_L                          (0x0010)
#define TBXR5                            (0x0020)        /* Timer_B count register */
#define TBXR5_L                          (0x0020)
#define TBXR6                            (0x0040)        /* Timer_B count register */
#define TBXR6_L                          (0x0040)
#define TBXR7                            (0x0080)        /* Timer_B count register */
#define TBXR7_L                          (0x0080)
#define TBXR8                            (0x0100)        /* Timer_B count register */
#define TBXR8_H                          (0x0001)
#define TBXR9                            (0x0200)        /* Timer_B count register */
#define TBXR9_H                          (0x0002)
#define TBXR10                           (0x0400)        /* Timer_B count register */
#define TBXR10_H                         (0x0004)
#define TBXR11                           (0x0800)        /* Timer_B count register */
#define TBXR11_H                         (0x0008)
#define TBXR12                           (0x1000)        /* Timer_B count register */
#define TBXR12_H                         (0x0010)
#define TBXR13                           (0x2000)        /* Timer_B count register */
#define TBXR13_H                         (0x0020)
#define TBXR14                           (0x4000)        /* Timer_B count register */
#define TBXR14_H                         (0x0040)
#define TBXR15                           (0x8000)        /* Timer_B count register */
#define TBXR15_H                         (0x0080)

/* TB0CCR Control Bits */
#define TBXCCRN                          (0xffff)        /* Timer_B capture/compare register. */
#define TBXCCRN_L                        (0x00ff)
#define TBXCCRN_H                        (0x00ff)
#define TBXCCRN0                         (0x0001)        /* Timer_B capture/compare register. */
#define TBXCCRN0_L                       (0x0001)
#define TBXCCRN1                         (0x0002)        /* Timer_B capture/compare register. */
#define TBXCCRN1_L                       (0x0002)
#define TBXCCRN2                         (0x0004)        /* Timer_B capture/compare register. */
#define TBXCCRN2_L                       (0x0004)
#define TBXCCRN3                         (0x0008)        /* Timer_B capture/compare register. */
#define TBXCCRN3_L                       (0x0008)
#define TBXCCRN4                         (0x0010)        /* Timer_B capture/compare register. */
#define TBXCCRN4_L                       (0x0010)
#define TBXCCRN5                         (0x0020)        /* Timer_B capture/compare register. */
#define TBXCCRN5_L                       (0x0020)
#define TBXCCRN6                         (0x0040)        /* Timer_B capture/compare register. */
#define TBXCCRN6_L                       (0x0040)
#define TBXCCRN7                         (0x0080)        /* Timer_B capture/compare register. */
#define TBXCCRN7_L                       (0x0080)
#define TBXCCRN8                         (0x0100)        /* Timer_B capture/compare register. */
#define TBXCCRN8_H                       (0x0001)
#define TBXCCRN9                         (0x0200)        /* Timer_B capture/compare register. */
#define TBXCCRN9_H                       (0x0002)
#define TBXCCRN10                        (0x0400)        /* Timer_B capture/compare register. */
#define TBXCCRN10_H                      (0x0004)
#define TBXCCRN11                        (0x0800)        /* Timer_B capture/compare register. */
#define TBXCCRN11_H                      (0x0008)
#define TBXCCRN12                        (0x1000)        /* Timer_B capture/compare register. */
#define TBXCCRN12_H                      (0x0010)
#define TBXCCRN13                        (0x2000)        /* Timer_B capture/compare register. */
#define TBXCCRN13_H                      (0x0020)
#define TBXCCRN14                        (0x4000)        /* Timer_B capture/compare register. */
#define TBXCCRN14_H                      (0x0040)
#define TBXCCRN15                        (0x8000)        /* Timer_B capture/compare register. */
#define TBXCCRN15_H                      (0x0080)

/* TB0EX0 Control Bits */
#define TBIDEX                           (0x0007)        /* Input divider expansion */
#define TBIDEX_L                         (0x0007)
#define TBIDEX0                          (0x0001)        /* Input divider expansion */
#define TBIDEX0_L                        (0x0001)
#define TBIDEX1                          (0x0002)        /* Input divider expansion */
#define TBIDEX1_L                        (0x0002)
#define TBIDEX2                          (0x0004)        /* Input divider expansion */
#define TBIDEX2_L                        (0x0004)
#define TBIDEX_0                         (0x0000)        /* Divide by 1 */
#define TBIDEX_1                         (0x0001)        /* Divide by 2 */
#define TBIDEX_1_L                       (0x0001)
#define TBIDEX_2                         (0x0002)        /* Divide by 3 */
#define TBIDEX_2_L                       (0x0002)
#define TBIDEX_3                         (0x0003)        /* Divide by 4 */
#define TBIDEX_3_L                       (0x0003)
#define TBIDEX_4                         (0x0004)        /* Divide by 5 */
#define TBIDEX_4_L                       (0x0004)
#define TBIDEX_5                         (0x0005)        /* Divide by 6 */
#define TBIDEX_5_L                       (0x0005)
#define TBIDEX_6                         (0x0006)        /* Divide by 7 */
#define TBIDEX_6_L                       (0x0006)
#define TBIDEX_7                         (0x0007)        /* Divide by 8 */
#define TBIDEX_7_L                       (0x0007)
#define TBIDEX__1                        (0x0000)        /* Divide by 1 */
#define TBIDEX__2                        (0x0001)        /* Divide by 2 */
#define TBIDEX__2_L                      (0x0001)
#define TBIDEX__3                        (0x0002)        /* Divide by 3 */
#define TBIDEX__3_L                      (0x0002)
#define TBIDEX__4                        (0x0003)        /* Divide by 4 */
#define TBIDEX__4_L                      (0x0003)
#define TBIDEX__5                        (0x0004)        /* Divide by 5 */
#define TBIDEX__5_L                      (0x0004)
#define TBIDEX__6                        (0x0005)        /* Divide by 6 */
#define TBIDEX__6_L                      (0x0005)
#define TBIDEX__7                        (0x0006)        /* Divide by 7 */
#define TBIDEX__7_L                      (0x0006)
#define TBIDEX__8                        (0x0007)        /* Divide by 8 */
#define TBIDEX__8_L                      (0x0007)

/* TB0IV Control Bits */
#define TBIV                             (0xffff)        /* Timer_B interrupt vector value */
#define TBIV_L                           (0x00ff)
#define TBIV_H                           (0x00ff)
#define TBIV0                            (0x0001)        /* Timer_B interrupt vector value */
#define TBIV0_L                          (0x0001)
#define TBIV1                            (0x0002)        /* Timer_B interrupt vector value */
#define TBIV1_L                          (0x0002)
#define TBIV2                            (0x0004)        /* Timer_B interrupt vector value */
#define TBIV2_L                          (0x0004)
#define TBIV3                            (0x0008)        /* Timer_B interrupt vector value */
#define TBIV3_L                          (0x0008)
#define TBIV4                            (0x0010)        /* Timer_B interrupt vector value */
#define TBIV4_L                          (0x0010)
#define TBIV5                            (0x0020)        /* Timer_B interrupt vector value */
#define TBIV5_L                          (0x0020)
#define TBIV6                            (0x0040)        /* Timer_B interrupt vector value */
#define TBIV6_L                          (0x0040)
#define TBIV7                            (0x0080)        /* Timer_B interrupt vector value */
#define TBIV7_L                          (0x0080)
#define TBIV8                            (0x0100)        /* Timer_B interrupt vector value */
#define TBIV8_H                          (0x0001)
#define TBIV9                            (0x0200)        /* Timer_B interrupt vector value */
#define TBIV9_H                          (0x0002)
#define TBIV10                           (0x0400)        /* Timer_B interrupt vector value */
#define TBIV10_H                         (0x0004)
#define TBIV11                           (0x0800)        /* Timer_B interrupt vector value */
#define TBIV11_H                         (0x0008)
#define TBIV12                           (0x1000)        /* Timer_B interrupt vector value */
#define TBIV12_H                         (0x0010)
#define TBIV13                           (0x2000)        /* Timer_B interrupt vector value */
#define TBIV13_H                         (0x0020)
#define TBIV14                           (0x4000)        /* Timer_B interrupt vector value */
#define TBIV14_H                         (0x0040)
#define TBIV15                           (0x8000)        /* Timer_B interrupt vector value */
#define TBIV15_H                         (0x0080)
#define TBIV_0                           (0x0000)        /* No interrupt pending */
#define TBIV_2                           (0x0002)        /* Interrupt Source: Capture/compare 1; Interrupt Flag: TBxCCR1 
                                                            CCIFG; Interrupt Priority: Highest */
#define TBIV_2_L                         (0x0002)
#define TBIV_4                           (0x0004)        /* Interrupt Source: Capture/compare 2; Interrupt Flag: TBxCCR2 
                                                            CCIFG */
#define TBIV_4_L                         (0x0004)
#define TBIV_6                           (0x0006)        /* Interrupt Source: Capture/compare 3; Interrupt Flag: TBxCCR3 
                                                            CCIFG */
#define TBIV_6_L                         (0x0006)
#define TBIV_8                           (0x0008)        /* Interrupt Source: Capture/compare 4; Interrupt Flag: TBxCCR4 
                                                            CCIFG */
#define TBIV_8_L                         (0x0008)
#define TBIV_10                          (0x000a)        /* Interrupt Source: Capture/compare 5; Interrupt Flag: TBxCCR5 
                                                            CCIFG */
#define TBIV_10_L                        (0x000a)
#define TBIV_12                          (0x000c)        /* Interrupt Source: Capture/compare 6; Interrupt Flag: TBxCCR6 
                                                            CCIFG */
#define TBIV_12_L                        (0x000c)
#define TBIV_14                          (0x000e)        /* Interrupt Source: Timer overflow; Interrupt Flag: TBxCTL TBIFG;
                                                            Interrupt Priority: Lowest */
#define TBIV_14_L                        (0x000e)
#define TBIV__NONE                       (0x0000)        /* No interrupt pending */
#define TBIV__TBCCR1                     (0x0002)        /* Interrupt Source: Capture/compare 1; Interrupt Flag: TBxCCR1 
                                                            CCIFG; Interrupt Priority: Highest */
#define TBIV__TBCCR1_L                   (0x0002)
#define TBIV__TBCCR2                     (0x0004)        /* Interrupt Source: Capture/compare 2; Interrupt Flag: TBxCCR2 
                                                            CCIFG */
#define TBIV__TBCCR2_L                   (0x0004)
#define TBIV__TBCCR3                     (0x0006)        /* Interrupt Source: Capture/compare 3; Interrupt Flag: TBxCCR3 
                                                            CCIFG */
#define TBIV__TBCCR3_L                   (0x0006)
#define TBIV__TBCCR4                     (0x0008)        /* Interrupt Source: Capture/compare 4; Interrupt Flag: TBxCCR4 
                                                            CCIFG */
#define TBIV__TBCCR4_L                   (0x0008)
#define TBIV__TBCCR5                     (0x000a)        /* Interrupt Source: Capture/compare 5; Interrupt Flag: TBxCCR5 
                                                            CCIFG */
#define TBIV__TBCCR5_L                   (0x000a)
#define TBIV__TBCCR6                     (0x000c)        /* Interrupt Source: Capture/compare 6; Interrupt Flag: TBxCCR6 
                                                            CCIFG */
#define TBIV__TBCCR6_L                   (0x000c)
#define TBIV__TBIFG                      (0x000e)        /* Interrupt Source: Timer overflow; Interrupt Flag: TBxCTL TBIFG;
                                                            Interrupt Priority: Lowest */
#define TBIV__TBIFG_L                    (0x000e)


#define OFS_ADC12CTL0                    (0x0000u)
#define OFS_ADC12CTL0_L                  OFS_ADC12CTL0
#define OFS_ADC12CTL0_H                  OFS_ADC12CTL0+1
#define OFS_ADC12CTL1                    (0x0002u)
#define OFS_ADC12CTL1_L                  OFS_ADC12CTL1
#define OFS_ADC12CTL1_H                  OFS_ADC12CTL1+1
#define OFS_ADC12CTL2                    (0x0004u)
#define OFS_ADC12CTL2_L                  OFS_ADC12CTL2
#define OFS_ADC12CTL2_H                  OFS_ADC12CTL2+1
#define OFS_ADC12CTL3                    (0x0006u)
#define OFS_ADC12CTL3_L                  OFS_ADC12CTL3
#define OFS_ADC12CTL3_H                  OFS_ADC12CTL3+1
#define OFS_ADC12LO                      (0x0008u)
#define OFS_ADC12LO_L                    OFS_ADC12LO
#define OFS_ADC12LO_H                    OFS_ADC12LO+1
#define OFS_ADC12HI                      (0x000Au)
#define OFS_ADC12HI_L                    OFS_ADC12HI
#define OFS_ADC12HI_H                    OFS_ADC12HI+1
#define OFS_ADC12IFGR0                   (0x000Cu)
#define OFS_ADC12IFGR0_L                 OFS_ADC12IFGR0
#define OFS_ADC12IFGR0_H                 OFS_ADC12IFGR0+1
#define OFS_ADC12IFGR1                   (0x000Eu)
#define OFS_ADC12IFGR1_L                 OFS_ADC12IFGR1
#define OFS_ADC12IFGR1_H                 OFS_ADC12IFGR1+1
#define OFS_ADC12IFGR2                   (0x0010u)
#define OFS_ADC12IFGR2_L                 OFS_ADC12IFGR2
#define OFS_ADC12IFGR2_H                 OFS_ADC12IFGR2+1
#define OFS_ADC12IER0                    (0x0012u)
#define OFS_ADC12IER0_L                  OFS_ADC12IER0
#define OFS_ADC12IER0_H                  OFS_ADC12IER0+1
#define OFS_ADC12IER1                    (0x0014u)
#define OFS_ADC12IER1_L                  OFS_ADC12IER1
#define OFS_ADC12IER1_H                  OFS_ADC12IER1+1
#define OFS_ADC12IER2                    (0x0016u)
#define OFS_ADC12IER2_L                  OFS_ADC12IER2
#define OFS_ADC12IER2_H                  OFS_ADC12IER2+1
#define OFS_ADC12IV                      (0x0018u)
#define OFS_ADC12IV_L                    OFS_ADC12IV
#define OFS_ADC12IV_H                    OFS_ADC12IV+1
#define OFS_ADC12MCTL0                   (0x0020u)
#define OFS_ADC12MCTL0_L                 OFS_ADC12MCTL0
#define OFS_ADC12MCTL0_H                 OFS_ADC12MCTL0+1
#define OFS_ADC12MCTL1                   (0x0022u)
#define OFS_ADC12MCTL1_L                 OFS_ADC12MCTL1
#define OFS_ADC12MCTL1_H                 OFS_ADC12MCTL1+1
#define OFS_ADC12MCTL2                   (0x0024u)
#define OFS_ADC12MCTL2_L                 OFS_ADC12MCTL2
#define OFS_ADC12MCTL2_H                 OFS_ADC12MCTL2+1
#define OFS_ADC12MCTL3                   (0x0026u)
#define OFS_ADC12MCTL3_L                 OFS_ADC12MCTL3
#define OFS_ADC12MCTL3_H                 OFS_ADC12MCTL3+1
#define OFS_ADC12MCTL4                   (0x0028u)
#define OFS_ADC12MCTL4_L                 OFS_ADC12MCTL4
#define OFS_ADC12MCTL4_H                 OFS_ADC12MCTL4+1
#define OFS_ADC12MCTL5                   (0x002Au)
#define OFS_ADC12MCTL5_L                 OFS_ADC12MCTL5
#define OFS_ADC12MCTL5_H                 OFS_ADC12MCTL5+1
#define OFS_ADC12MCTL6                   (0x002Cu)
#define OFS_ADC12MCTL6_L                 OFS_ADC12MCTL6
#define OFS_ADC12MCTL6_H                 OFS_ADC12MCTL6+1
#define OFS_ADC12MCTL7                   (0x002Eu)
#define OFS_ADC12MCTL7_L                 OFS_ADC12MCTL7
#define OFS_ADC12MCTL7_H                 OFS_ADC12MCTL7+1
#define OFS_ADC12MCTL8                   (0x0030u)
#define OFS_ADC12MCTL8_L                 OFS_ADC12MCTL8
#define OFS_ADC12MCTL8_H                 OFS_ADC12MCTL8+1
#define OFS_ADC12MCTL9                   (0x0032u)
#define OFS_ADC12MCTL9_L                 OFS_ADC12MCTL9
#define OFS_ADC12MCTL9_H                 OFS_ADC12MCTL9+1
#define OFS_ADC12MCTL10                  (0x0034u)
#define OFS_ADC12MCTL10_L                OFS_ADC12MCTL10
#define OFS_ADC12MCTL10_H                OFS_ADC12MCTL10+1
#define OFS_ADC12MCTL11                  (0x0036u)
#define OFS_ADC12MCTL11_L                OFS_ADC12MCTL11
#define OFS_ADC12MCTL11_H                OFS_ADC12MCTL11+1
#define OFS_ADC12MCTL12                  (0x0038u)
#define OFS_ADC12MCTL12_L                OFS_ADC12MCTL12
#define OFS_ADC12MCTL12_H                OFS_ADC12MCTL12+1
#define OFS_ADC12MCTL13                  (0x003Au)
#define OFS_ADC12MCTL13_L                OFS_ADC12MCTL13
#define OFS_ADC12MCTL13_H                OFS_ADC12MCTL13+1
#define OFS_ADC12MCTL14                  (0x003Cu)
#define OFS_ADC12MCTL14_L                OFS_ADC12MCTL14
#define OFS_ADC12MCTL14_H                OFS_ADC12MCTL14+1
#define OFS_ADC12MCTL15                  (0x003Eu)
#define OFS_ADC12MCTL15_L                OFS_ADC12MCTL15
#define OFS_ADC12MCTL15_H                OFS_ADC12MCTL15+1
#define OFS_ADC12MCTL16                  (0x0040u)
#define OFS_ADC12MCTL16_L                OFS_ADC12MCTL16
#define OFS_ADC12MCTL16_H                OFS_ADC12MCTL16+1
#define OFS_ADC12MCTL17                  (0x0042u)
#define OFS_ADC12MCTL17_L                OFS_ADC12MCTL17
#define OFS_ADC12MCTL17_H                OFS_ADC12MCTL17+1
#define OFS_ADC12MCTL18                  (0x0044u)
#define OFS_ADC12MCTL18_L                OFS_ADC12MCTL18
#define OFS_ADC12MCTL18_H                OFS_ADC12MCTL18+1
#define OFS_ADC12MCTL19                  (0x0046u)
#define OFS_ADC12MCTL19_L                OFS_ADC12MCTL19
#define OFS_ADC12MCTL19_H                OFS_ADC12MCTL19+1
#define OFS_ADC12MCTL20                  (0x0048u)
#define OFS_ADC12MCTL20_L                OFS_ADC12MCTL20
#define OFS_ADC12MCTL20_H                OFS_ADC12MCTL20+1
#define OFS_ADC12MCTL21                  (0x004Au)
#define OFS_ADC12MCTL21_L                OFS_ADC12MCTL21
#define OFS_ADC12MCTL21_H                OFS_ADC12MCTL21+1
#define OFS_ADC12MCTL22                  (0x004Cu)
#define OFS_ADC12MCTL22_L                OFS_ADC12MCTL22
#define OFS_ADC12MCTL22_H                OFS_ADC12MCTL22+1
#define OFS_ADC12MCTL23                  (0x004Eu)
#define OFS_ADC12MCTL23_L                OFS_ADC12MCTL23
#define OFS_ADC12MCTL23_H                OFS_ADC12MCTL23+1
#define OFS_ADC12MCTL24                  (0x0050u)
#define OFS_ADC12MCTL24_L                OFS_ADC12MCTL24
#define OFS_ADC12MCTL24_H                OFS_ADC12MCTL24+1
#define OFS_ADC12MCTL25                  (0x0052u)
#define OFS_ADC12MCTL25_L                OFS_ADC12MCTL25
#define OFS_ADC12MCTL25_H                OFS_ADC12MCTL25+1
#define OFS_ADC12MCTL26                  (0x0054u)
#define OFS_ADC12MCTL26_L                OFS_ADC12MCTL26
#define OFS_ADC12MCTL26_H                OFS_ADC12MCTL26+1
#define OFS_ADC12MCTL27                  (0x0056u)
#define OFS_ADC12MCTL27_L                OFS_ADC12MCTL27
#define OFS_ADC12MCTL27_H                OFS_ADC12MCTL27+1
#define OFS_ADC12MCTL28                  (0x0058u)
#define OFS_ADC12MCTL28_L                OFS_ADC12MCTL28
#define OFS_ADC12MCTL28_H                OFS_ADC12MCTL28+1
#define OFS_ADC12MCTL29                  (0x005Au)
#define OFS_ADC12MCTL29_L                OFS_ADC12MCTL29
#define OFS_ADC12MCTL29_H                OFS_ADC12MCTL29+1
#define OFS_ADC12MCTL30                  (0x005Cu)
#define OFS_ADC12MCTL30_L                OFS_ADC12MCTL30
#define OFS_ADC12MCTL30_H                OFS_ADC12MCTL30+1
#define OFS_ADC12MCTL31                  (0x005Eu)
#define OFS_ADC12MCTL31_L                OFS_ADC12MCTL31
#define OFS_ADC12MCTL31_H                OFS_ADC12MCTL31+1
#define OFS_ADC12MEM0                    (0x0060u)
#define OFS_ADC12MEM0_L                  OFS_ADC12MEM0
#define OFS_ADC12MEM0_H                  OFS_ADC12MEM0+1
#define OFS_ADC12MEM1                    (0x0062u)
#define OFS_ADC12MEM1_L                  OFS_ADC12MEM1
#define OFS_ADC12MEM1_H                  OFS_ADC12MEM1+1
#define OFS_ADC12MEM2                    (0x0064u)
#define OFS_ADC12MEM2_L                  OFS_ADC12MEM2
#define OFS_ADC12MEM2_H                  OFS_ADC12MEM2+1
#define OFS_ADC12MEM3                    (0x0066u)
#define OFS_ADC12MEM3_L                  OFS_ADC12MEM3
#define OFS_ADC12MEM3_H                  OFS_ADC12MEM3+1
#define OFS_ADC12MEM4                    (0x0068u)
#define OFS_ADC12MEM4_L                  OFS_ADC12MEM4
#define OFS_ADC12MEM4_H                  OFS_ADC12MEM4+1
#define OFS_ADC12MEM5                    (0x006Au)
#define OFS_ADC12MEM5_L                  OFS_ADC12MEM5
#define OFS_ADC12MEM5_H                  OFS_ADC12MEM5+1
#define OFS_ADC12MEM6                    (0x006Cu)
#define OFS_ADC12MEM6_L                  OFS_ADC12MEM6
#define OFS_ADC12MEM6_H                  OFS_ADC12MEM6+1
#define OFS_ADC12MEM7                    (0x006Eu)
#define OFS_ADC12MEM7_L                  OFS_ADC12MEM7
#define OFS_ADC12MEM7_H                  OFS_ADC12MEM7+1
#define OFS_ADC12MEM8                    (0x0070u)
#define OFS_ADC12MEM8_L                  OFS_ADC12MEM8
#define OFS_ADC12MEM8_H                  OFS_ADC12MEM8+1
#define OFS_ADC12MEM9                    (0x0072u)
#define OFS_ADC12MEM9_L                  OFS_ADC12MEM9
#define OFS_ADC12MEM9_H                  OFS_ADC12MEM9+1
#define OFS_ADC12MEM10                   (0x0074u)
#define OFS_ADC12MEM10_L                 OFS_ADC12MEM10
#define OFS_ADC12MEM10_H                 OFS_ADC12MEM10+1
#define OFS_ADC12MEM11                   (0x0076u)
#define OFS_ADC12MEM11_L                 OFS_ADC12MEM11
#define OFS_ADC12MEM11_H                 OFS_ADC12MEM11+1
#define OFS_ADC12MEM12                   (0x0078u)
#define OFS_ADC12MEM12_L                 OFS_ADC12MEM12
#define OFS_ADC12MEM12_H                 OFS_ADC12MEM12+1
#define OFS_ADC12MEM13                   (0x007Au)
#define OFS_ADC12MEM13_L                 OFS_ADC12MEM13
#define OFS_ADC12MEM13_H                 OFS_ADC12MEM13+1
#define OFS_ADC12MEM14                   (0x007Cu)
#define OFS_ADC12MEM14_L                 OFS_ADC12MEM14
#define OFS_ADC12MEM14_H                 OFS_ADC12MEM14+1
#define OFS_ADC12MEM15                   (0x007Eu)
#define OFS_ADC12MEM15_L                 OFS_ADC12MEM15
#define OFS_ADC12MEM15_H                 OFS_ADC12MEM15+1
#define OFS_ADC12MEM16                   (0x0080u)
#define OFS_ADC12MEM16_L                 OFS_ADC12MEM16
#define OFS_ADC12MEM16_H                 OFS_ADC12MEM16+1
#define OFS_ADC12MEM17                   (0x0082u)
#define OFS_ADC12MEM17_L                 OFS_ADC12MEM17
#define OFS_ADC12MEM17_H                 OFS_ADC12MEM17+1
#define OFS_ADC12MEM18                   (0x0084u)
#define OFS_ADC12MEM18_L                 OFS_ADC12MEM18
#define OFS_ADC12MEM18_H                 OFS_ADC12MEM18+1
#define OFS_ADC12MEM19                   (0x0086u)
#define OFS_ADC12MEM19_L                 OFS_ADC12MEM19
#define OFS_ADC12MEM19_H                 OFS_ADC12MEM19+1
#define OFS_ADC12MEM20                   (0x0088u)
#define OFS_ADC12MEM20_L                 OFS_ADC12MEM20
#define OFS_ADC12MEM20_H                 OFS_ADC12MEM20+1
#define OFS_ADC12MEM21                   (0x008Au)
#define OFS_ADC12MEM21_L                 OFS_ADC12MEM21
#define OFS_ADC12MEM21_H                 OFS_ADC12MEM21+1
#define OFS_ADC12MEM22                   (0x008Cu)
#define OFS_ADC12MEM22_L                 OFS_ADC12MEM22
#define OFS_ADC12MEM22_H                 OFS_ADC12MEM22+1
#define OFS_ADC12MEM23                   (0x008Eu)
#define OFS_ADC12MEM23_L                 OFS_ADC12MEM23
#define OFS_ADC12MEM23_H                 OFS_ADC12MEM23+1
#define OFS_ADC12MEM24                   (0x0090u)
#define OFS_ADC12MEM24_L                 OFS_ADC12MEM24
#define OFS_ADC12MEM24_H                 OFS_ADC12MEM24+1
#define OFS_ADC12MEM25                   (0x0092u)
#define OFS_ADC12MEM25_L                 OFS_ADC12MEM25
#define OFS_ADC12MEM25_H                 OFS_ADC12MEM25+1
#define OFS_ADC12MEM26                   (0x0094u)
#define OFS_ADC12MEM26_L                 OFS_ADC12MEM26
#define OFS_ADC12MEM26_H                 OFS_ADC12MEM26+1
#define OFS_ADC12MEM27                   (0x0096u)
#define OFS_ADC12MEM27_L                 OFS_ADC12MEM27
#define OFS_ADC12MEM27_H                 OFS_ADC12MEM27+1
#define OFS_ADC12MEM28                   (0x0098u)
#define OFS_ADC12MEM28_L                 OFS_ADC12MEM28
#define OFS_ADC12MEM28_H                 OFS_ADC12MEM28+1
#define OFS_ADC12MEM29                   (0x009Au)
#define OFS_ADC12MEM29_L                 OFS_ADC12MEM29
#define OFS_ADC12MEM29_H                 OFS_ADC12MEM29+1
#define OFS_ADC12MEM30                   (0x009Cu)
#define OFS_ADC12MEM30_L                 OFS_ADC12MEM30
#define OFS_ADC12MEM30_H                 OFS_ADC12MEM30+1
#define OFS_ADC12MEM31                   (0x009Eu)
#define OFS_ADC12MEM31_L                 OFS_ADC12MEM31
#define OFS_ADC12MEM31_H                 OFS_ADC12MEM31+1

/* ADC12_B Control Bits */

/* ADC12CTL0 Control Bits */
#define ADC12SC                          (0x0001)        /* start conversion */
#define ADC12SC_L                        (0x0001)
#define ADC12SC_0                        (0x0000)        /* No sample-and-conversion-start */
#define ADC12SC_1                        (0x0001)        /* Start sample-and-conversion */
#define ADC12SC_1_L                      (0x0001)
#define ADC12ENC                         (0x0002)        /* enable conversion */
#define ADC12ENC_L                       (0x0002)
#define ADC12ENC_0                       (0x0000)        /* ADC12_B disabled */
#define ADC12ENC_1                       (0x0002)        /* ADC12_B enabled */
#define ADC12ENC_1_L                     (0x0002)
#define ADC12ON                          (0x0010)        /* ADC on */
#define ADC12ON_L                        (0x0010)
#define ADC12ON_0                        (0x0000)        /* ADC12_B off */
#define ADC12ON_1                        (0x0010)        /* ADC12_B on */
#define ADC12ON_1_L                      (0x0010)
#define ADC12MSC                         (0x0080)        /* sample-and-hold time. */
#define ADC12MSC_L                       (0x0080)
#define ADC12MSC_0                       (0x0000)        /* The sampling timer requires a rising edge of the SHI signal to
                                                            trigger each sample-and-convert. */
#define ADC12MSC_1                       (0x0080)        /* The incidence of a positive(or for devices first rising edge 
                                                            of the) SHI signal triggers the sampling timer, but further 
                                                            sample-and-conversions are performed automatically as soon as 
                                                            the prior conversion is completed. */
#define ADC12MSC_1_L                     (0x0080)
#define ADC12SHT0                        (0x0f00)        /* sample-and-hold time. */
#define ADC12SHT0_H                      (0x000f)
#define ADC12SHT00                       (0x0100)        /* sample-and-hold time. */
#define ADC12SHT00_H                     (0x0001)
#define ADC12SHT01                       (0x0200)        /* sample-and-hold time. */
#define ADC12SHT01_H                     (0x0002)
#define ADC12SHT02                       (0x0400)        /* sample-and-hold time. */
#define ADC12SHT02_H                     (0x0004)
#define ADC12SHT03                       (0x0800)        /* sample-and-hold time. */
#define ADC12SHT03_H                     (0x0008)
#define ADC12SHT0_0                      (0x0000)        /* 4 ADC12CLK cycles */
#define ADC12SHT0_1                      (0x0100)        /* 8 ADC12CLK cycles */
#define ADC12SHT0_1_H                    (0x0001)
#define ADC12SHT0_2                      (0x0200)        /* 16 ADC12CLK cycles */
#define ADC12SHT0_2_H                    (0x0002)
#define ADC12SHT0_3                      (0x0300)        /* 32 ADC12CLK cycles */
#define ADC12SHT0_3_H                    (0x0003)
#define ADC12SHT0_4                      (0x0400)        /* 64 ADC12CLK cycles */
#define ADC12SHT0_4_H                    (0x0004)
#define ADC12SHT0_5                      (0x0500)        /* 96 ADC12CLK cycles */
#define ADC12SHT0_5_H                    (0x0005)
#define ADC12SHT0_6                      (0x0600)        /* 128 ADC12CLK cycles */
#define ADC12SHT0_6_H                    (0x0006)
#define ADC12SHT0_7                      (0x0700)        /* 192 ADC12CLK cycles */
#define ADC12SHT0_7_H                    (0x0007)
#define ADC12SHT0_8                      (0x0800)        /* 256 ADC12CLK cycles */
#define ADC12SHT0_8_H                    (0x0008)
#define ADC12SHT0_9                      (0x0900)        /* 384 ADC12CLK cycles */
#define ADC12SHT0_9_H                    (0x0009)
#define ADC12SHT0_10                     (0x0a00)        /* 512 ADC12CLK cycles */
#define ADC12SHT0_10_H                   (0x000a)
#define ADC12SHT0_11                     (0x0b00)        /* Reserved */
#define ADC12SHT0_11_H                   (0x000b)
#define ADC12SHT0_12                     (0x0c00)        /* Reserved */
#define ADC12SHT0_12_H                   (0x000c)
#define ADC12SHT0_13                     (0x0d00)        /* Reserved */
#define ADC12SHT0_13_H                   (0x000d)
#define ADC12SHT0_14                     (0x0e00)        /* Reserved */
#define ADC12SHT0_14_H                   (0x000e)
#define ADC12SHT0_15                     (0x0f00)        /* Reserved */
#define ADC12SHT0_15_H                   (0x000f)
#define ADC12SHT1                        (0xf000)        /* sample-and-hold time. */
#define ADC12SHT1_H                      (0x00f0)
#define ADC12SHT10                       (0x1000)        /* sample-and-hold time. */
#define ADC12SHT10_H                     (0x0010)
#define ADC12SHT11                       (0x2000)        /* sample-and-hold time. */
#define ADC12SHT11_H                     (0x0020)
#define ADC12SHT12                       (0x4000)        /* sample-and-hold time. */
#define ADC12SHT12_H                     (0x0040)
#define ADC12SHT13                       (0x8000)        /* sample-and-hold time. */
#define ADC12SHT13_H                     (0x0080)
#define ADC12SHT1_0                      (0x0000)        /* 4 ADC12CLK cycles */
#define ADC12SHT1_1                      (0x1000)        /* 8 ADC12CLK cycles */
#define ADC12SHT1_1_H                    (0x0010)
#define ADC12SHT1_2                      (0x2000)        /* 16 ADC12CLK cycles */
#define ADC12SHT1_2_H                    (0x0020)
#define ADC12SHT1_3                      (0x3000)        /* 32 ADC12CLK cycles */
#define ADC12SHT1_3_H                    (0x0030)
#define ADC12SHT1_4                      (0x4000)        /* 64 ADC12CLK cycles */
#define ADC12SHT1_4_H                    (0x0040)
#define ADC12SHT1_5                      (0x5000)        /* 96 ADC12CLK cycles */
#define ADC12SHT1_5_H                    (0x0050)
#define ADC12SHT1_6                      (0x6000)        /* 128 ADC12CLK cycles */
#define ADC12SHT1_6_H                    (0x0060)
#define ADC12SHT1_7                      (0x7000)        /* 192 ADC12CLK cycles */
#define ADC12SHT1_7_H                    (0x0070)
#define ADC12SHT1_8                      (0x8000)        /* 256 ADC12CLK cycles */
#define ADC12SHT1_8_H                    (0x0080)
#define ADC12SHT1_9                      (0x9000)        /* 384 ADC12CLK cycles */
#define ADC12SHT1_9_H                    (0x0090)
#define ADC12SHT1_10                     (0xa000)        /* 512 ADC12CLK cycles */
#define ADC12SHT1_10_H                   (0x00a0)
#define ADC12SHT1_11                     (0xb000)        /* Reserved */
#define ADC12SHT1_11_H                   (0x00b0)
#define ADC12SHT1_12                     (0xc000)        /* Reserved */
#define ADC12SHT1_12_H                   (0x00c0)
#define ADC12SHT1_13                     (0xd000)        /* Reserved */
#define ADC12SHT1_13_H                   (0x00d0)
#define ADC12SHT1_14                     (0xe000)        /* Reserved */
#define ADC12SHT1_14_H                   (0x00e0)
#define ADC12SHT1_15                     (0xf000)        /* Reserved */
#define ADC12SHT1_15_H                   (0x00f0)

/* ADC12CTL1 Control Bits */
#define ADC12BUSY                        (0x0001)        /* ADC busy */
#define ADC12BUSY_L                      (0x0001)
#define ADC12BUSY_0                      (0x0000)        /* No operation is active. */
#define ADC12BUSY_1                      (0x0001)        /* A sequence, sample, or conversion is active. */
#define ADC12BUSY_1_L                    (0x0001)
#define ADC12CONSEQ                      (0x0006)        /* conversion sequence mode select */
#define ADC12CONSEQ_L                    (0x0006)
#define ADC12CONSEQ0                     (0x0002)        /* conversion sequence mode select */
#define ADC12CONSEQ0_L                   (0x0002)
#define ADC12CONSEQ1                     (0x0004)        /* conversion sequence mode select */
#define ADC12CONSEQ1_L                   (0x0004)
#define ADC12CONSEQ_0                    (0x0000)        /* Single-channel, single-conversion */
#define ADC12CONSEQ_1                    (0x0002)        /* Sequence-of-channels */
#define ADC12CONSEQ_1_L                  (0x0002)
#define ADC12CONSEQ_2                    (0x0004)        /* Repeat-single-channel */
#define ADC12CONSEQ_2_L                  (0x0004)
#define ADC12CONSEQ_3                    (0x0006)        /* Repeat-sequence-of-channels */
#define ADC12CONSEQ_3_L                  (0x0006)
#define ADC12SSEL                        (0x0018)        /* clock source select */
#define ADC12SSEL_L                      (0x0018)
#define ADC12SSEL0                       (0x0008)        /* clock source select */
#define ADC12SSEL0_L                     (0x0008)
#define ADC12SSEL1                       (0x0010)        /* clock source select */
#define ADC12SSEL1_L                     (0x0010)
#define ADC12SSEL_0                      (0x0000)        /* ADC12OSC (MODOSC) */
#define ADC12SSEL_1                      (0x0008)        /* ACLK */
#define ADC12SSEL_1_L                    (0x0008)
#define ADC12SSEL_2                      (0x0010)        /* MCLK */
#define ADC12SSEL_2_L                    (0x0010)
#define ADC12SSEL_3                      (0x0018)        /* SMCLK */
#define ADC12SSEL_3_L                    (0x0018)
#define ADC12DIV                         (0x00e0)        /* clock divider */
#define ADC12DIV_L                       (0x00e0)
#define ADC12DIV0                        (0x0020)        /* clock divider */
#define ADC12DIV0_L                      (0x0020)
#define ADC12DIV1                        (0x0040)        /* clock divider */
#define ADC12DIV1_L                      (0x0040)
#define ADC12DIV2                        (0x0080)        /* clock divider */
#define ADC12DIV2_L                      (0x0080)
#define ADC12DIV_0                       (0x0000)        /* /1 */
#define ADC12DIV_1                       (0x0020)        /* /2 */
#define ADC12DIV_1_L                     (0x0020)
#define ADC12DIV_2                       (0x0040)        /* /3 */
#define ADC12DIV_2_L                     (0x0040)
#define ADC12DIV_3                       (0x0060)        /* /4 */
#define ADC12DIV_3_L                     (0x0060)
#define ADC12DIV_4                       (0x0080)        /* /5 */
#define ADC12DIV_4_L                     (0x0080)
#define ADC12DIV_5                       (0x00a0)        /* /6 */
#define ADC12DIV_5_L                     (0x00a0)
#define ADC12DIV_6                       (0x00c0)        /* /7 */
#define ADC12DIV_6_L                     (0x00c0)
#define ADC12DIV_7                       (0x00e0)        /* /8 */
#define ADC12DIV_7_L                     (0x00e0)
#define ADC12ISSH                        (0x0100)        /* invert signal sample-and-hold */
#define ADC12ISSH_H                      (0x0001)
#define ADC12ISSH_0                      (0x0000)        /* The sample-input signal is not inverted. */
#define ADC12ISSH_1                      (0x0100)        /* The sample-input signal is inverted. */
#define ADC12ISSH_1_H                    (0x0001)
#define ADC12SHP                         (0x0200)        /* sample-and-hold pulse-mode select */
#define ADC12SHP_H                       (0x0002)
#define ADC12SHP_0                       (0x0000)        /* SAMPCON signal is sourced from the sample-input signal. */
#define ADC12SHP_1                       (0x0200)        /* SAMPCON signal is sourced from the sampling timer. */
#define ADC12SHP_1_H                     (0x0002)
#define ADC12SHS                         (0x1c00)        /* sample-and-hold source select */
#define ADC12SHS_H                       (0x001c)
#define ADC12SHS0                        (0x0400)        /* sample-and-hold source select */
#define ADC12SHS0_H                      (0x0004)
#define ADC12SHS1                        (0x0800)        /* sample-and-hold source select */
#define ADC12SHS1_H                      (0x0008)
#define ADC12SHS2                        (0x1000)        /* sample-and-hold source select */
#define ADC12SHS2_H                      (0x0010)
#define ADC12SHS_0                       (0x0000)        /* ADC12SC bit */
#define ADC12SHS_1                       (0x0400)        /* see the device-specific data sheet for source */
#define ADC12SHS_1_H                     (0x0004)
#define ADC12SHS_2                       (0x0800)        /* see the device-specific data sheet for source */
#define ADC12SHS_2_H                     (0x0008)
#define ADC12SHS_3                       (0x0c00)        /* see the device-specific data sheet for source */
#define ADC12SHS_3_H                     (0x000c)
#define ADC12SHS_4                       (0x1000)        /* see the device-specific data sheet for source */
#define ADC12SHS_4_H                     (0x0010)
#define ADC12SHS_5                       (0x1400)        /* see the device-specific data sheet for source */
#define ADC12SHS_5_H                     (0x0014)
#define ADC12SHS_6                       (0x1800)        /* see the device-specific data sheet for source */
#define ADC12SHS_6_H                     (0x0018)
#define ADC12SHS_7                       (0x1c00)        /* see the device-specific data sheet for source */
#define ADC12SHS_7_H                     (0x001c)
#define ADC12PDIV                        (0x6000)        /* predivider */
#define ADC12PDIV_H                      (0x0060)
#define ADC12PDIV0                       (0x2000)        /* predivider */
#define ADC12PDIV0_H                     (0x0020)
#define ADC12PDIV1                       (0x4000)        /* predivider */
#define ADC12PDIV1_H                     (0x0040)
#define ADC12PDIV_0                      (0x0000)        /* Predivide by 1 */
#define ADC12PDIV_1                      (0x2000)        /* Predivide by 4 */
#define ADC12PDIV_1_H                    (0x0020)
#define ADC12PDIV_2                      (0x4000)        /* Predivide by 32 */
#define ADC12PDIV_2_H                    (0x0040)
#define ADC12PDIV_3                      (0x6000)        /* Predivide by 64 */
#define ADC12PDIV_3_H                    (0x0060)
#define ADC12PDIV__1                     (0x0000)        /* Predivide by 1 */
#define ADC12PDIV__4                     (0x2000)        /* Predivide by 4 */
#define ADC12PDIV__4_H                   (0x0020)
#define ADC12PDIV__32                    (0x4000)        /* Predivide by 32 */
#define ADC12PDIV__32_H                  (0x0040)
#define ADC12PDIV__64                    (0x6000)        /* Predivide by 64 */
#define ADC12PDIV__64_H                  (0x0060)

/* ADC12CTL2 Control Bits */
#define ADC12PWRMD                       (0x0001)        /* low-power mode */
#define ADC12PWRMD_L                     (0x0001)
#define ADC12PWRMD_0                     (0x0000)        /* Regular power mode where sample rate is not restricted */
#define ADC12PWRMD_1                     (0x0001)        /* Low power mode enable, ADC12CLK can not be greater than 1/4 
                                                            the device-specific data sheet specified maximum for 
                                                            ADC12PWRMD = 0 */
#define ADC12PWRMD_1_L                   (0x0001)
#define ADC12DF                          (0x0008)        /* data read-back format */
#define ADC12DF_L                        (0x0008)
#define ADC12DF_0                        (0x0000)        /* Binary unsigned. Theoretically for ADC12DIF = 0 and 12-bit 
                                                            mode the analog input voltage ? VREF results in 0000h, the 
                                                            analog input voltage + VREF results in 0FFFh. */
#define ADC12DF_1                        (0x0008)        /* Signed binary (2s complement), left aligned. Theoretically, 
                                                            for ADC12DIF = 0 and 12-bit mode, the analog input voltage ? 
                                                            VREF results in 8000h, the analog input voltage + VREF results
                                                            in 7FF0h. */
#define ADC12DF_1_L                      (0x0008)
#define ADC12RES                         (0x0030)        /* resolution */
#define ADC12RES_L                       (0x0030)
#define ADC12RES0                        (0x0010)        /* resolution */
#define ADC12RES0_L                      (0x0010)
#define ADC12RES1                        (0x0020)        /* resolution */
#define ADC12RES1_L                      (0x0020)
#define ADC12RES_0                       (0x0000)        /* 8 bit (10 clock cycle conversion time) */
#define ADC12RES_1                       (0x0010)        /* 10 bit (12 clock cycle conversion time) */
#define ADC12RES_1_L                     (0x0010)
#define ADC12RES_2                       (0x0020)        /* 12 bit (14 clock cycle conversion time) */
#define ADC12RES_2_L                     (0x0020)
#define ADC12RES_3                       (0x0030)        /* Reserved */
#define ADC12RES_3_L                     (0x0030)
#define ADC12RES__8BIT                   (0x0000)        /* 8 bit (10 clock cycle conversion time) */
#define ADC12RES__10BIT                  (0x0010)        /* 10 bit (12 clock cycle conversion time) */
#define ADC12RES__10BIT_L                (0x0010)
#define ADC12RES__12BIT                  (0x0020)        /* 12 bit (14 clock cycle conversion time) */
#define ADC12RES__12BIT_L                (0x0020)

/* ADC12CTL3 Control Bits */
#define ADC12CSTARTADD                   (0x001f)        /* conversion start address */
#define ADC12CSTARTADD_L                 (0x001f)
#define ADC12CSTARTADD0                  (0x0001)        /* conversion start address */
#define ADC12CSTARTADD0_L                (0x0001)
#define ADC12CSTARTADD1                  (0x0002)        /* conversion start address */
#define ADC12CSTARTADD1_L                (0x0002)
#define ADC12CSTARTADD2                  (0x0004)        /* conversion start address */
#define ADC12CSTARTADD2_L                (0x0004)
#define ADC12CSTARTADD3                  (0x0008)        /* conversion start address */
#define ADC12CSTARTADD3_L                (0x0008)
#define ADC12CSTARTADD4                  (0x0010)        /* conversion start address */
#define ADC12CSTARTADD4_L                (0x0010)
#define ADC12CSTARTADD_0                 (0x0000)        /* Conversion start address ADC12MEM0 */
#define ADC12CSTARTADD_1                 (0x0001)        /* Conversion start address ADC12MEM1 */
#define ADC12CSTARTADD_1_L               (0x0001)
#define ADC12CSTARTADD_2                 (0x0002)        /* Conversion start address ADC12MEM2 */
#define ADC12CSTARTADD_2_L               (0x0002)
#define ADC12CSTARTADD_3                 (0x0003)        /* Conversion start address ADC12MEM3 */
#define ADC12CSTARTADD_3_L               (0x0003)
#define ADC12CSTARTADD_4                 (0x0004)        /* Conversion start address ADC12MEM4 */
#define ADC12CSTARTADD_4_L               (0x0004)
#define ADC12CSTARTADD_5                 (0x0005)        /* Conversion start address ADC12MEM5 */
#define ADC12CSTARTADD_5_L               (0x0005)
#define ADC12CSTARTADD_6                 (0x0006)        /* Conversion start address ADC12MEM6 */
#define ADC12CSTARTADD_6_L               (0x0006)
#define ADC12CSTARTADD_7                 (0x0007)        /* Conversion start address ADC12MEM7 */
#define ADC12CSTARTADD_7_L               (0x0007)
#define ADC12CSTARTADD_8                 (0x0008)        /* Conversion start address ADC12MEM8 */
#define ADC12CSTARTADD_8_L               (0x0008)
#define ADC12CSTARTADD_9                 (0x0009)        /* Conversion start address ADC12MEM9 */
#define ADC12CSTARTADD_9_L               (0x0009)
#define ADC12CSTARTADD_10                (0x000a)        /* Conversion start address ADC12MEM10 */
#define ADC12CSTARTADD_10_L              (0x000a)
#define ADC12CSTARTADD_11                (0x000b)        /* Conversion start address ADC12MEM10 */
#define ADC12CSTARTADD_11_L              (0x000b)
#define ADC12CSTARTADD_12                (0x000c)        /* Conversion start address ADC12MEM12 */
#define ADC12CSTARTADD_12_L              (0x000c)
#define ADC12CSTARTADD_13                (0x000d)        /* Conversion start address ADC12MEM13 */
#define ADC12CSTARTADD_13_L              (0x000d)
#define ADC12CSTARTADD_14                (0x000e)        /* Conversion start address ADC12MEM14 */
#define ADC12CSTARTADD_14_L              (0x000e)
#define ADC12CSTARTADD_15                (0x000f)        /* Conversion start address ADC12MEM15 */
#define ADC12CSTARTADD_15_L              (0x000f)
#define ADC12CSTARTADD_16                (0x0010)        /* Conversion start address ADC12MEM16 */
#define ADC12CSTARTADD_16_L              (0x0010)
#define ADC12CSTARTADD_17                (0x0011)        /* Conversion start address ADC12MEM17 */
#define ADC12CSTARTADD_17_L              (0x0011)
#define ADC12CSTARTADD_18                (0x0012)        /* Conversion start address ADC12MEM18 */
#define ADC12CSTARTADD_18_L              (0x0012)
#define ADC12CSTARTADD_19                (0x0013)        /* Conversion start address ADC12MEM19 */
#define ADC12CSTARTADD_19_L              (0x0013)
#define ADC12CSTARTADD_20                (0x0014)        /* Conversion start address ADC12MEM20 */
#define ADC12CSTARTADD_20_L              (0x0014)
#define ADC12CSTARTADD_21                (0x0015)        /* Conversion start address ADC12MEM21 */
#define ADC12CSTARTADD_21_L              (0x0015)
#define ADC12CSTARTADD_22                (0x0016)        /* Conversion start address ADC12MEM22 */
#define ADC12CSTARTADD_22_L              (0x0016)
#define ADC12CSTARTADD_23                (0x0017)        /* Conversion start address ADC12MEM23 */
#define ADC12CSTARTADD_23_L              (0x0017)
#define ADC12CSTARTADD_24                (0x0018)        /* Conversion start address ADC12MEM24 */
#define ADC12CSTARTADD_24_L              (0x0018)
#define ADC12CSTARTADD_25                (0x0019)        /* Conversion start address ADC12MEM25 */
#define ADC12CSTARTADD_25_L              (0x0019)
#define ADC12CSTARTADD_26                (0x001a)        /* Conversion start address ADC12MEM26 */
#define ADC12CSTARTADD_26_L              (0x001a)
#define ADC12CSTARTADD_27                (0x001b)        /* Conversion start address ADC12MEM27 */
#define ADC12CSTARTADD_27_L              (0x001b)
#define ADC12CSTARTADD_28                (0x001c)        /* Conversion start address ADC12MEM28 */
#define ADC12CSTARTADD_28_L              (0x001c)
#define ADC12CSTARTADD_29                (0x001d)        /* Conversion start address ADC12MEM29 */
#define ADC12CSTARTADD_29_L              (0x001d)
#define ADC12CSTARTADD_30                (0x001e)        /* Conversion start address ADC12MEM30 */
#define ADC12CSTARTADD_30_L              (0x001e)
#define ADC12CSTARTADD_31                (0x001f)        /* Conversion start address ADC12MEM31 */
#define ADC12CSTARTADD_31_L              (0x001f)
#define ADC12CSTARTADD__ADC12MEM0        (0x0000)        /* Conversion start address ADC12MEM0 */
#define ADC12CSTARTADD__ADC12MEM1        (0x0001)        /* Conversion start address ADC12MEM1 */
#define ADC12CSTARTADD__ADC12MEM1_L      (0x0001)
#define ADC12CSTARTADD__ADC12MEM2        (0x0002)        /* Conversion start address ADC12MEM2 */
#define ADC12CSTARTADD__ADC12MEM2_L      (0x0002)
#define ADC12CSTARTADD__ADC12MEM3        (0x0003)        /* Conversion start address ADC12MEM3 */
#define ADC12CSTARTADD__ADC12MEM3_L      (0x0003)
#define ADC12CSTARTADD__ADC12MEM4        (0x0004)        /* Conversion start address ADC12MEM4 */
#define ADC12CSTARTADD__ADC12MEM4_L      (0x0004)
#define ADC12CSTARTADD__ADC12MEM5        (0x0005)        /* Conversion start address ADC12MEM5 */
#define ADC12CSTARTADD__ADC12MEM5_L      (0x0005)
#define ADC12CSTARTADD__ADC12MEM6        (0x0006)        /* Conversion start address ADC12MEM6 */
#define ADC12CSTARTADD__ADC12MEM6_L      (0x0006)
#define ADC12CSTARTADD__ADC12MEM7        (0x0007)        /* Conversion start address ADC12MEM7 */
#define ADC12CSTARTADD__ADC12MEM7_L      (0x0007)
#define ADC12CSTARTADD__ADC12MEM8        (0x0008)        /* Conversion start address ADC12MEM8 */
#define ADC12CSTARTADD__ADC12MEM8_L      (0x0008)
#define ADC12CSTARTADD__ADC12MEM9        (0x0009)        /* Conversion start address ADC12MEM9 */
#define ADC12CSTARTADD__ADC12MEM9_L      (0x0009)
#define ADC12CSTARTADD__ADC12MEM10       (0x000a)        /* Conversion start address ADC12MEM10 */
#define ADC12CSTARTADD__ADC12MEM10_L     (0x000a)
#define ADC12CSTARTADD__ADC12MEM11       (0x000b)        /* Conversion start address ADC12MEM10 */
#define ADC12CSTARTADD__ADC12MEM11_L     (0x000b)
#define ADC12CSTARTADD__ADC12MEM12       (0x000c)        /* Conversion start address ADC12MEM12 */
#define ADC12CSTARTADD__ADC12MEM12_L     (0x000c)
#define ADC12CSTARTADD__ADC12MEM13       (0x000d)        /* Conversion start address ADC12MEM13 */
#define ADC12CSTARTADD__ADC12MEM13_L     (0x000d)
#define ADC12CSTARTADD__ADC12MEM14       (0x000e)        /* Conversion start address ADC12MEM14 */
#define ADC12CSTARTADD__ADC12MEM14_L     (0x000e)
#define ADC12CSTARTADD__ADC12MEM15       (0x000f)        /* Conversion start address ADC12MEM15 */
#define ADC12CSTARTADD__ADC12MEM15_L     (0x000f)
#define ADC12CSTARTADD__ADC12MEM16       (0x0010)        /* Conversion start address ADC12MEM16 */
#define ADC12CSTARTADD__ADC12MEM16_L     (0x0010)
#define ADC12CSTARTADD__ADC12MEM17       (0x0011)        /* Conversion start address ADC12MEM17 */
#define ADC12CSTARTADD__ADC12MEM17_L     (0x0011)
#define ADC12CSTARTADD__ADC12MEM18       (0x0012)        /* Conversion start address ADC12MEM18 */
#define ADC12CSTARTADD__ADC12MEM18_L     (0x0012)
#define ADC12CSTARTADD__ADC12MEM19       (0x0013)        /* Conversion start address ADC12MEM19 */
#define ADC12CSTARTADD__ADC12MEM19_L     (0x0013)
#define ADC12CSTARTADD__ADC12MEM20       (0x0014)        /* Conversion start address ADC12MEM20 */
#define ADC12CSTARTADD__ADC12MEM20_L     (0x0014)
#define ADC12CSTARTADD__ADC12MEM21       (0x0015)        /* Conversion start address ADC12MEM21 */
#define ADC12CSTARTADD__ADC12MEM21_L     (0x0015)
#define ADC12CSTARTADD__ADC12MEM22       (0x0016)        /* Conversion start address ADC12MEM22 */
#define ADC12CSTARTADD__ADC12MEM22_L     (0x0016)
#define ADC12CSTARTADD__ADC12MEM23       (0x0017)        /* Conversion start address ADC12MEM23 */
#define ADC12CSTARTADD__ADC12MEM23_L     (0x0017)
#define ADC12CSTARTADD__ADC12MEM24       (0x0018)        /* Conversion start address ADC12MEM24 */
#define ADC12CSTARTADD__ADC12MEM24_L     (0x0018)
#define ADC12CSTARTADD__ADC12MEM25       (0x0019)        /* Conversion start address ADC12MEM25 */
#define ADC12CSTARTADD__ADC12MEM25_L     (0x0019)
#define ADC12CSTARTADD__ADC12MEM26       (0x001a)        /* Conversion start address ADC12MEM26 */
#define ADC12CSTARTADD__ADC12MEM26_L     (0x001a)
#define ADC12CSTARTADD__ADC12MEM27       (0x001b)        /* Conversion start address ADC12MEM27 */
#define ADC12CSTARTADD__ADC12MEM27_L     (0x001b)
#define ADC12CSTARTADD__ADC12MEM28       (0x001c)        /* Conversion start address ADC12MEM28 */
#define ADC12CSTARTADD__ADC12MEM28_L     (0x001c)
#define ADC12CSTARTADD__ADC12MEM29       (0x001d)        /* Conversion start address ADC12MEM29 */
#define ADC12CSTARTADD__ADC12MEM29_L     (0x001d)
#define ADC12CSTARTADD__ADC12MEM30       (0x001e)        /* Conversion start address ADC12MEM30 */
#define ADC12CSTARTADD__ADC12MEM30_L     (0x001e)
#define ADC12CSTARTADD__ADC12MEM31       (0x001f)        /* Conversion start address ADC12MEM31 */
#define ADC12CSTARTADD__ADC12MEM31_L     (0x001f)
#define ADC12BATMAP                      (0x0040)        /* 1/2 AVCC ADC input channel selection */
#define ADC12BATMAP_L                    (0x0040)
#define ADC12BATMAP_0                    (0x0000)        /* external pin is selected for ADC input channel A31 */
#define ADC12BATMAP_1                    (0x0040)        /* ADC internal 1/2 x AVCC channel is selected for ADC input 
                                                            channel A31 */
#define ADC12BATMAP_1_L                  (0x0040)
#define ADC12TCMAP                       (0x0080)        /* temperature sensor ADC input channel selection */
#define ADC12TCMAP_L                     (0x0080)
#define ADC12TCMAP_0                     (0x0000)        /* external pin is selected for ADC input channel A30 */
#define ADC12TCMAP_1                     (0x0080)        /* ADC internal temperature sensor channel is selected for ADC 
                                                            input channel A30 */
#define ADC12TCMAP_1_L                   (0x0080)
#define ADC12ICH0MAP                     (0x0100)        /* int ch 0 sel to ADC in ch A29 */
#define ADC12ICH0MAP_H                   (0x0001)
#define ADC12ICH0MAP_0                   (0x0000)        /* external pin is selected for ADC input channel A29 */
#define ADC12ICH0MAP_1                   (0x0100)        /* ADC input channel internal 0 is selected for ADC input channel
                                                            A29, see device-specific data sheet for availability */
#define ADC12ICH0MAP_1_H                 (0x0001)
#define ADC12ICH1MAP                     (0x0200)        /* int ch 1 sel to ADC in ch A28 */
#define ADC12ICH1MAP_H                   (0x0002)
#define ADC12ICH1MAP_0                   (0x0000)        /* external pin is selected for ADC input channel A28 */
#define ADC12ICH1MAP_1                   (0x0200)        /* ADC input channel internal 1 is selected for ADC input channel
                                                            A28, see device-specific data sheet for availability */
#define ADC12ICH1MAP_1_H                 (0x0002)
#define ADC12ICH2MAP                     (0x0400)        /* int ch 2 sel to ADC in ch A27 */
#define ADC12ICH2MAP_H                   (0x0004)
#define ADC12ICH2MAP_0                   (0x0000)        /* external pin is selected for ADC input channel A27 */
#define ADC12ICH2MAP_1                   (0x0400)        /* ADC input channel internal 2 is selected for ADC input channel
                                                            A27, see device-specific data sheet for availability */
#define ADC12ICH2MAP_1_H                 (0x0004)
#define ADC12ICH3MAP                     (0x0800)        /* int ch 3 sel to ADC in ch A26 */
#define ADC12ICH3MAP_H                   (0x0008)
#define ADC12ICH3MAP_0                   (0x0000)        /* external pin is selected for ADC input channel A26 */
#define ADC12ICH3MAP_1                   (0x0800)        /* ADC input channel internal 3 is selected for ADC input channel
                                                            A26, see device-specific data sheet for availability */
#define ADC12ICH3MAP_1_H                 (0x0008)

/* ADC12LO Control Bits */
#define LOW_THRESHOLD                    (0xffff)        /* Window comparator lo threshold */
#define LOW_THRESHOLD_L                  (0x00ff)
#define LOW_THRESHOLD_H                  (0x00ff)
#define LOW_THRESHOLD0                   (0x0001)        /* Window comparator lo threshold */
#define LOW_THRESHOLD0_L                 (0x0001)
#define LOW_THRESHOLD1                   (0x0002)        /* Window comparator lo threshold */
#define LOW_THRESHOLD1_L                 (0x0002)
#define LOW_THRESHOLD2                   (0x0004)        /* Window comparator lo threshold */
#define LOW_THRESHOLD2_L                 (0x0004)
#define LOW_THRESHOLD3                   (0x0008)        /* Window comparator lo threshold */
#define LOW_THRESHOLD3_L                 (0x0008)
#define LOW_THRESHOLD4                   (0x0010)        /* Window comparator lo threshold */
#define LOW_THRESHOLD4_L                 (0x0010)
#define LOW_THRESHOLD5                   (0x0020)        /* Window comparator lo threshold */
#define LOW_THRESHOLD5_L                 (0x0020)
#define LOW_THRESHOLD6                   (0x0040)        /* Window comparator lo threshold */
#define LOW_THRESHOLD6_L                 (0x0040)
#define LOW_THRESHOLD7                   (0x0080)        /* Window comparator lo threshold */
#define LOW_THRESHOLD7_L                 (0x0080)
#define LOW_THRESHOLD8                   (0x0100)        /* Window comparator lo threshold */
#define LOW_THRESHOLD8_H                 (0x0001)
#define LOW_THRESHOLD9                   (0x0200)        /* Window comparator lo threshold */
#define LOW_THRESHOLD9_H                 (0x0002)
#define LOW_THRESHOLD10                  (0x0400)        /* Window comparator lo threshold */
#define LOW_THRESHOLD10_H                (0x0004)
#define LOW_THRESHOLD11                  (0x0800)        /* Window comparator lo threshold */
#define LOW_THRESHOLD11_H                (0x0008)
#define LOW_THRESHOLD12                  (0x1000)        /* Window comparator lo threshold */
#define LOW_THRESHOLD12_H                (0x0010)
#define LOW_THRESHOLD13                  (0x2000)        /* Window comparator lo threshold */
#define LOW_THRESHOLD13_H                (0x0020)
#define LOW_THRESHOLD14                  (0x4000)        /* Window comparator lo threshold */
#define LOW_THRESHOLD14_H                (0x0040)
#define LOW_THRESHOLD15                  (0x8000)        /* Window comparator lo threshold */
#define LOW_THRESHOLD15_H                (0x0080)

/* ADC12HI Control Bits */
#define HIGH_THRESHOLD                   (0xffff)        /* Window comparator high threshold */
#define HIGH_THRESHOLD_L                 (0x00ff)
#define HIGH_THRESHOLD_H                 (0x00ff)
#define HIGH_THRESHOLD0                  (0x0001)        /* Window comparator high threshold */
#define HIGH_THRESHOLD0_L                (0x0001)
#define HIGH_THRESHOLD1                  (0x0002)        /* Window comparator high threshold */
#define HIGH_THRESHOLD1_L                (0x0002)
#define HIGH_THRESHOLD2                  (0x0004)        /* Window comparator high threshold */
#define HIGH_THRESHOLD2_L                (0x0004)
#define HIGH_THRESHOLD3                  (0x0008)        /* Window comparator high threshold */
#define HIGH_THRESHOLD3_L                (0x0008)
#define HIGH_THRESHOLD4                  (0x0010)        /* Window comparator high threshold */
#define HIGH_THRESHOLD4_L                (0x0010)
#define HIGH_THRESHOLD5                  (0x0020)        /* Window comparator high threshold */
#define HIGH_THRESHOLD5_L                (0x0020)
#define HIGH_THRESHOLD6                  (0x0040)        /* Window comparator high threshold */
#define HIGH_THRESHOLD6_L                (0x0040)
#define HIGH_THRESHOLD7                  (0x0080)        /* Window comparator high threshold */
#define HIGH_THRESHOLD7_L                (0x0080)
#define HIGH_THRESHOLD8                  (0x0100)        /* Window comparator high threshold */
#define HIGH_THRESHOLD8_H                (0x0001)
#define HIGH_THRESHOLD9                  (0x0200)        /* Window comparator high threshold */
#define HIGH_THRESHOLD9_H                (0x0002)
#define HIGH_THRESHOLD10                 (0x0400)        /* Window comparator high threshold */
#define HIGH_THRESHOLD10_H               (0x0004)
#define HIGH_THRESHOLD11                 (0x0800)        /* Window comparator high threshold */
#define HIGH_THRESHOLD11_H               (0x0008)
#define HIGH_THRESHOLD12                 (0x1000)        /* Window comparator high threshold */
#define HIGH_THRESHOLD12_H               (0x0010)
#define HIGH_THRESHOLD13                 (0x2000)        /* Window comparator high threshold */
#define HIGH_THRESHOLD13_H               (0x0020)
#define HIGH_THRESHOLD14                 (0x4000)        /* Window comparator high threshold */
#define HIGH_THRESHOLD14_H               (0x0040)
#define HIGH_THRESHOLD15                 (0x8000)        /* Window comparator high threshold */
#define HIGH_THRESHOLD15_H               (0x0080)

/* ADC12IFGR0 Control Bits */
#define ADC12IFG0                        (0x0001)        /* ADC12MEM0 interrupt flag */
#define ADC12IFG0_L                      (0x0001)
#define ADC12IFG0_0                      (0x0000)        /* No interrupt pending */
#define ADC12IFG0_1                      (0x0001)        /* Interrupt pending */
#define ADC12IFG0_1_L                    (0x0001)
#define ADC12IFG1                        (0x0002)        /* ADC12MEM1 interrupt flag */
#define ADC12IFG1_L                      (0x0002)
#define ADC12IFG1_0                      (0x0000)        /* No interrupt pending */
#define ADC12IFG1_1                      (0x0002)        /* Interrupt pending */
#define ADC12IFG1_1_L                    (0x0002)
#define ADC12IFG2                        (0x0004)        /* ADC12MEM2 interrupt flag */
#define ADC12IFG2_L                      (0x0004)
#define ADC12IFG2_0                      (0x0000)        /* No interrupt pending */
#define ADC12IFG2_1                      (0x0004)        /* Interrupt pending */
#define ADC12IFG2_1_L                    (0x0004)
#define ADC12IFG3                        (0x0008)        /* ADC12MEM3 interrupt flag */
#define ADC12IFG3_L                      (0x0008)
#define ADC12IFG3_0                      (0x0000)        /* No interrupt pending */
#define ADC12IFG3_1                      (0x0008)        /* Interrupt pending */
#define ADC12IFG3_1_L                    (0x0008)
#define ADC12IFG4                        (0x0010)        /* ADC12MEM4 interrupt flag */
#define ADC12IFG4_L                      (0x0010)
#define ADC12IFG4_0                      (0x0000)        /* No interrupt pending */
#define ADC12IFG4_1                      (0x0010)        /* Interrupt pending */
#define ADC12IFG4_1_L                    (0x0010)
#define ADC12IFG5                        (0x0020)        /* ADC12MEM5 interrupt flag */
#define ADC12IFG5_L                      (0x0020)
#define ADC12IFG5_0                      (0x0000)        /* No interrupt pending */
#define ADC12IFG5_1                      (0x0020)        /* Interrupt pending */
#define ADC12IFG5_1_L                    (0x0020)
#define ADC12IFG6                        (0x0040)        /* ADC12MEM6 interrupt flag */
#define ADC12IFG6_L                      (0x0040)
#define ADC12IFG6_0                      (0x0000)        /* No interrupt pending */
#define ADC12IFG6_1                      (0x0040)        /* Interrupt pending */
#define ADC12IFG6_1_L                    (0x0040)
#define ADC12IFG7                        (0x0080)        /* ADC12MEM7 interrupt flag */
#define ADC12IFG7_L                      (0x0080)
#define ADC12IFG7_0                      (0x0000)        /* No interrupt pending */
#define ADC12IFG7_1                      (0x0080)        /* Interrupt pending */
#define ADC12IFG7_1_L                    (0x0080)
#define ADC12IFG8                        (0x0100)        /* ADC12MEM8 interrupt flag */
#define ADC12IFG8_H                      (0x0001)
#define ADC12IFG8_0                      (0x0000)        /* No interrupt pending */
#define ADC12IFG8_1                      (0x0100)        /* Interrupt pending */
#define ADC12IFG8_1_H                    (0x0001)
#define ADC12IFG9                        (0x0200)        /* ADC12MEM9 interrupt flag */
#define ADC12IFG9_H                      (0x0002)
#define ADC12IFG9_0                      (0x0000)        /* No interrupt pending */
#define ADC12IFG9_1                      (0x0200)        /* Interrupt pending */
#define ADC12IFG9_1_H                    (0x0002)
#define ADC12IFG10                       (0x0400)        /* ADC12MEM10 interrupt flag */
#define ADC12IFG10_H                     (0x0004)
#define ADC12IFG10_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG10_1                     (0x0400)        /* Interrupt pending */
#define ADC12IFG10_1_H                   (0x0004)
#define ADC12IFG11                       (0x0800)        /* ADC12MEM11 interrupt flag */
#define ADC12IFG11_H                     (0x0008)
#define ADC12IFG11_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG11_1                     (0x0800)        /* Interrupt pending */
#define ADC12IFG11_1_H                   (0x0008)
#define ADC12IFG12                       (0x1000)        /* ADC12MEM12 interrupt flag */
#define ADC12IFG12_H                     (0x0010)
#define ADC12IFG12_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG12_1                     (0x1000)        /* Interrupt pending */
#define ADC12IFG12_1_H                   (0x0010)
#define ADC12IFG13                       (0x2000)        /* ADC12MEM13 interrupt flag */
#define ADC12IFG13_H                     (0x0020)
#define ADC12IFG13_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG13_1                     (0x2000)        /* Interrupt pending */
#define ADC12IFG13_1_H                   (0x0020)
#define ADC12IFG14                       (0x4000)        /* ADC12MEM14 interrupt flag */
#define ADC12IFG14_H                     (0x0040)
#define ADC12IFG14_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG14_1                     (0x4000)        /* Interrupt pending */
#define ADC12IFG14_1_H                   (0x0040)
#define ADC12IFG15                       (0x8000)        /* ADC12MEM15 interrupt flag */
#define ADC12IFG15_H                     (0x0080)
#define ADC12IFG15_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG15_1                     (0x8000)        /* Interrupt pending */
#define ADC12IFG15_1_H                   (0x0080)

/* ADC12IFGR1 Control Bits */
#define ADC12IFG16                       (0x0001)        /* ADC12MEM16 interrupt flag */
#define ADC12IFG16_L                     (0x0001)
#define ADC12IFG16_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG16_1                     (0x0001)        /* Interrupt pending */
#define ADC12IFG16_1_L                   (0x0001)
#define ADC12IFG17                       (0x0002)        /* ADC12MEM17 interrupt flag */
#define ADC12IFG17_L                     (0x0002)
#define ADC12IFG17_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG17_1                     (0x0002)        /* Interrupt pending */
#define ADC12IFG17_1_L                   (0x0002)
#define ADC12IFG18                       (0x0004)        /* ADC12MEM18 interrupt flag */
#define ADC12IFG18_L                     (0x0004)
#define ADC12IFG18_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG18_1                     (0x0004)        /* Interrupt pending */
#define ADC12IFG18_1_L                   (0x0004)
#define ADC12IFG19                       (0x0008)        /* ADC12MEM19 interrupt flag */
#define ADC12IFG19_L                     (0x0008)
#define ADC12IFG19_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG19_1                     (0x0008)        /* Interrupt pending */
#define ADC12IFG19_1_L                   (0x0008)
#define ADC12IFG20                       (0x0010)        /* ADC12MEM20 interrupt flag */
#define ADC12IFG20_L                     (0x0010)
#define ADC12IFG20_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG20_1                     (0x0010)        /* Interrupt pending */
#define ADC12IFG20_1_L                   (0x0010)
#define ADC12IFG21                       (0x0020)        /* ADC12MEM21 interrupt flag */
#define ADC12IFG21_L                     (0x0020)
#define ADC12IFG21_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG21_1                     (0x0020)        /* Interrupt pending */
#define ADC12IFG21_1_L                   (0x0020)
#define ADC12IFG22                       (0x0040)        /* ADC12MEM22 interrupt flag */
#define ADC12IFG22_L                     (0x0040)
#define ADC12IFG22_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG22_1                     (0x0040)        /* Interrupt pending */
#define ADC12IFG22_1_L                   (0x0040)
#define ADC12IFG23                       (0x0080)        /* ADC12MEM23 interrupt flag */
#define ADC12IFG23_L                     (0x0080)
#define ADC12IFG23_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG23_1                     (0x0080)        /* Interrupt pending */
#define ADC12IFG23_1_L                   (0x0080)
#define ADC12IFG24                       (0x0100)        /* ADC12MEM24 interrupt flag */
#define ADC12IFG24_H                     (0x0001)
#define ADC12IFG24_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG24_1                     (0x0100)        /* Interrupt pending */
#define ADC12IFG24_1_H                   (0x0001)
#define ADC12IFG25                       (0x0200)        /* ADC12MEM25 interrupt flag */
#define ADC12IFG25_H                     (0x0002)
#define ADC12IFG25_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG25_1                     (0x0200)        /* Interrupt pending */
#define ADC12IFG25_1_H                   (0x0002)
#define ADC12IFG26                       (0x0400)        /* ADC12MEM26 interrupt flag */
#define ADC12IFG26_H                     (0x0004)
#define ADC12IFG26_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG26_1                     (0x0400)        /* Interrupt pending */
#define ADC12IFG26_1_H                   (0x0004)
#define ADC12IFG27                       (0x0800)        /* ADC12MEM27 interrupt flag */
#define ADC12IFG27_H                     (0x0008)
#define ADC12IFG27_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG27_1                     (0x0800)        /* Interrupt pending */
#define ADC12IFG27_1_H                   (0x0008)
#define ADC12IFG28                       (0x1000)        /* ADC12MEM28 interrupt flag */
#define ADC12IFG28_H                     (0x0010)
#define ADC12IFG28_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG28_1                     (0x1000)        /* Interrupt pending */
#define ADC12IFG28_1_H                   (0x0010)
#define ADC12IFG29                       (0x2000)        /* ADC12MEM29 interrupt flag */
#define ADC12IFG29_H                     (0x0020)
#define ADC12IFG29_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG29_1                     (0x2000)        /* Interrupt pending */
#define ADC12IFG29_1_H                   (0x0020)
#define ADC12IFG30                       (0x4000)        /* ADC12MEM30 interrupt flag */
#define ADC12IFG30_H                     (0x0040)
#define ADC12IFG30_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG30_1                     (0x4000)        /* Interrupt pending */
#define ADC12IFG30_1_H                   (0x0040)
#define ADC12IFG31                       (0x8000)        /* ADC12MEM31 interrupt flag */
#define ADC12IFG31_H                     (0x0080)
#define ADC12IFG31_0                     (0x0000)        /* No interrupt pending */
#define ADC12IFG31_1                     (0x8000)        /* Interrupt pending */
#define ADC12IFG31_1_H                   (0x0080)

/* ADC12IFGR2 Control Bits */
#define ADC12INIFG                       (0x0002)        /* Interrupt flag for ADC12MEMx between ADC12HI and ADC12LO */
#define ADC12INIFG_L                     (0x0002)
#define ADC12INIFG_0                     (0x0000)        /* No interrupt pending */
#define ADC12INIFG_1                     (0x0002)        /* Interrupt pending */
#define ADC12INIFG_1_L                   (0x0002)
#define ADC12LOIFG                       (0x0004)        /* Interrupt flag for ADC12MEMx <ADC12LO */
#define ADC12LOIFG_L                     (0x0004)
#define ADC12LOIFG_0                     (0x0000)        /* No interrupt pending */
#define ADC12LOIFG_1                     (0x0004)        /* Interrupt pending */
#define ADC12LOIFG_1_L                   (0x0004)
#define ADC12HIIFG                       (0x0008)        /* Interrupt flag for ADC12MEMx >ADC12HI */
#define ADC12HIIFG_L                     (0x0008)
#define ADC12HIIFG_0                     (0x0000)        /* No interrupt pending */
#define ADC12HIIFG_1                     (0x0008)        /* Interrupt pending */
#define ADC12HIIFG_1_L                   (0x0008)
#define ADC12OVIFG                       (0x0010)        /* ADC12MEMx overflow-interrupt flag. */
#define ADC12OVIFG_L                     (0x0010)
#define ADC12OVIFG_0                     (0x0000)        /* No interrupt pending */
#define ADC12OVIFG_1                     (0x0010)        /* Interrupt pending */
#define ADC12OVIFG_1_L                   (0x0010)
#define ADC12TOVIFG                      (0x0020)        /* conversion-time-overflow interrupt flag */
#define ADC12TOVIFG_L                    (0x0020)
#define ADC12TOVIFG_0                    (0x0000)        /* No interrupt pending */
#define ADC12TOVIFG_1                    (0x0020)        /* Interrupt pending */
#define ADC12TOVIFG_1_L                  (0x0020)
#define ADC12RDYIFG                      (0x0040)        /* reference buffer ready interrupt flag */
#define ADC12RDYIFG_L                    (0x0040)
#define ADC12RDYIFG_0                    (0x0000)        /* No interrupt pending */
#define ADC12RDYIFG_1                    (0x0040)        /* Interrupt pending */
#define ADC12RDYIFG_1_L                  (0x0040)

/* ADC12IER0 Control Bits */
#define ADC12IE0                         (0x0001)        /* Interrupt enable 0 */
#define ADC12IE0_L                       (0x0001)
#define ADC12IE0_0                       (0x0000)        /* Interrupt disabled */
#define ADC12IE0_1                       (0x0001)        /* Interrupt enabled */
#define ADC12IE0_1_L                     (0x0001)
#define ADC12IE1                         (0x0002)        /* interrupt enable 1 */
#define ADC12IE1_L                       (0x0002)
#define ADC12IE1_0                       (0x0000)        /* Interrupt disabled */
#define ADC12IE1_1                       (0x0002)        /* Interrupt enabled */
#define ADC12IE1_1_L                     (0x0002)
#define ADC12IE2                         (0x0004)        /* interrupt enable 2 */
#define ADC12IE2_L                       (0x0004)
#define ADC12IE2_0                       (0x0000)        /* Interrupt disabled */
#define ADC12IE2_1                       (0x0004)        /* Interrupt enabled */
#define ADC12IE2_1_L                     (0x0004)
#define ADC12IE3                         (0x0008)        /* interrupt enable 3 */
#define ADC12IE3_L                       (0x0008)
#define ADC12IE3_0                       (0x0000)        /* Interrupt disabled */
#define ADC12IE3_1                       (0x0008)        /* Interrupt enabled */
#define ADC12IE3_1_L                     (0x0008)
#define ADC12IE4                         (0x0010)        /* interrupt enable 4 */
#define ADC12IE4_L                       (0x0010)
#define ADC12IE4_0                       (0x0000)        /* Interrupt disabled */
#define ADC12IE4_1                       (0x0010)        /* Interrupt enabled */
#define ADC12IE4_1_L                     (0x0010)
#define ADC12IE5                         (0x0020)        /* interrupt enable 5 */
#define ADC12IE5_L                       (0x0020)
#define ADC12IE5_0                       (0x0000)        /* Interrupt disabled */
#define ADC12IE5_1                       (0x0020)        /* Interrupt enabled */
#define ADC12IE5_1_L                     (0x0020)
#define ADC12IE6                         (0x0040)        /* interrupt enable 6 */
#define ADC12IE6_L                       (0x0040)
#define ADC12IE6_0                       (0x0000)        /* Interrupt disabled */
#define ADC12IE6_1                       (0x0040)        /* Interrupt enabled */
#define ADC12IE6_1_L                     (0x0040)
#define ADC12IE7                         (0x0080)        /* interrupt enable 7 */
#define ADC12IE7_L                       (0x0080)
#define ADC12IE7_0                       (0x0000)        /* Interrupt disabled */
#define ADC12IE7_1                       (0x0080)        /* Interrupt enabled */
#define ADC12IE7_1_L                     (0x0080)
#define ADC12IE8                         (0x0100)        /* interrupt enable 8 */
#define ADC12IE8_H                       (0x0001)
#define ADC12IE8_0                       (0x0000)        /* Interrupt disabled */
#define ADC12IE8_1                       (0x0100)        /* Interrupt enabled */
#define ADC12IE8_1_H                     (0x0001)
#define ADC12IE9                         (0x0200)        /* interrupt enable 9 */
#define ADC12IE9_H                       (0x0002)
#define ADC12IE9_0                       (0x0000)        /* Interrupt disabled */
#define ADC12IE9_1                       (0x0200)        /* Interrupt enabled */
#define ADC12IE9_1_H                     (0x0002)
#define ADC12IE10                        (0x0400)        /* interrupt enable 10 */
#define ADC12IE10_H                      (0x0004)
#define ADC12IE10_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE10_1                      (0x0400)        /* Interrupt enabled */
#define ADC12IE10_1_H                    (0x0004)
#define ADC12IE11                        (0x0800)        /* interrupt enable  11 */
#define ADC12IE11_H                      (0x0008)
#define ADC12IE11_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE11_1                      (0x0800)        /* Interrupt enabled */
#define ADC12IE11_1_H                    (0x0008)
#define ADC12IE12                        (0x1000)        /* interrupt enable 12 */
#define ADC12IE12_H                      (0x0010)
#define ADC12IE12_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE12_1                      (0x1000)        /* Interrupt enabled */
#define ADC12IE12_1_H                    (0x0010)
#define ADC12IE13                        (0x2000)        /* interrupt enable  13 */
#define ADC12IE13_H                      (0x0020)
#define ADC12IE13_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE13_1                      (0x2000)        /* Interrupt enabled */
#define ADC12IE13_1_H                    (0x0020)
#define ADC12IE14                        (0x4000)        /* interrupt enable 14 */
#define ADC12IE14_H                      (0x0040)
#define ADC12IE14_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE14_1                      (0x4000)        /* Interrupt enabled */
#define ADC12IE14_1_H                    (0x0040)
#define ADC12IE15                        (0x8000)        /* interrupt enable 15 */
#define ADC12IE15_H                      (0x0080)
#define ADC12IE15_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE15_1                      (0x8000)        /* Interrupt enabled */
#define ADC12IE15_1_H                    (0x0080)

/* ADC12IER1 Control Bits */
#define ADC12IE16                        (0x0001)        /* interrupt enable 16 */
#define ADC12IE16_L                      (0x0001)
#define ADC12IE16_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE16_1                      (0x0001)        /* Interrupt enabled */
#define ADC12IE16_1_L                    (0x0001)
#define ADC12IE17                        (0x0002)        /* interrupt enable 17 */
#define ADC12IE17_L                      (0x0002)
#define ADC12IE17_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE17_1                      (0x0002)        /* Interrupt enabled */
#define ADC12IE17_1_L                    (0x0002)
#define ADC12IE18                        (0x0004)        /* interrupt enable 18 */
#define ADC12IE18_L                      (0x0004)
#define ADC12IE18_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE18_1                      (0x0004)        /* Interrupt enabled */
#define ADC12IE18_1_L                    (0x0004)
#define ADC12IE19                        (0x0008)        /* interrupt enable  19 */
#define ADC12IE19_L                      (0x0008)
#define ADC12IE19_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE19_1                      (0x0008)        /* Interrupt enabled */
#define ADC12IE19_1_L                    (0x0008)
#define ADC12IE20                        (0x0010)        /* interrupt enable 19 */
#define ADC12IE20_L                      (0x0010)
#define ADC12IE20_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE20_1                      (0x0010)        /* Interrupt enabled */
#define ADC12IE20_1_L                    (0x0010)
#define ADC12IE21                        (0x0020)        /* interrupt enable 21 */
#define ADC12IE21_L                      (0x0020)
#define ADC12IE21_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE21_1                      (0x0020)        /* Interrupt enabled */
#define ADC12IE21_1_L                    (0x0020)
#define ADC12IE22                        (0x0040)        /* interrupt enable 22 */
#define ADC12IE22_L                      (0x0040)
#define ADC12IE22_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE22_1                      (0x0040)        /* Interrupt enabled */
#define ADC12IE22_1_L                    (0x0040)
#define ADC12IE23                        (0x0080)        /* interrupt enable 23 */
#define ADC12IE23_L                      (0x0080)
#define ADC12IE23_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE23_1                      (0x0080)        /* Interrupt enabled */
#define ADC12IE23_1_L                    (0x0080)
#define ADC12IE24                        (0x0100)        /* interrupt enable 24 */
#define ADC12IE24_H                      (0x0001)
#define ADC12IE24_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE24_1                      (0x0100)        /* Interrupt enabled */
#define ADC12IE24_1_H                    (0x0001)
#define ADC12IE25                        (0x0200)        /* interrupt enable 25 */
#define ADC12IE25_H                      (0x0002)
#define ADC12IE25_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE25_1                      (0x0200)        /* Interrupt enabled */
#define ADC12IE25_1_H                    (0x0002)
#define ADC12IE26                        (0x0400)        /* interrupt enable 26 */
#define ADC12IE26_H                      (0x0004)
#define ADC12IE26_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE26_1                      (0x0400)        /* Interrupt enabled */
#define ADC12IE26_1_H                    (0x0004)
#define ADC12IE27                        (0x0800)        /* interrupt enable 27 */
#define ADC12IE27_H                      (0x0008)
#define ADC12IE27_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE27_1                      (0x0800)        /* Interrupt enabled */
#define ADC12IE27_1_H                    (0x0008)
#define ADC12IE28                        (0x1000)        /* interrupt enable  28 */
#define ADC12IE28_H                      (0x0010)
#define ADC12IE28_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE28_1                      (0x1000)        /* Interrupt enabled */
#define ADC12IE28_1_H                    (0x0010)
#define ADC12IE29                        (0x2000)        /* interrupt enable 29 */
#define ADC12IE29_H                      (0x0020)
#define ADC12IE29_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE29_1                      (0x2000)        /* Interrupt enabled */
#define ADC12IE29_1_H                    (0x0020)
#define ADC12IE30                        (0x4000)        /* interrupt enable 30 */
#define ADC12IE30_H                      (0x0040)
#define ADC12IE30_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE30_1                      (0x4000)        /* Interrupt enabled */
#define ADC12IE30_1_H                    (0x0040)
#define ADC12IE31                        (0x8000)        /* interrupt enable 30 */
#define ADC12IE31_H                      (0x0080)
#define ADC12IE31_0                      (0x0000)        /* Interrupt disabled */
#define ADC12IE31_1                      (0x8000)        /* Interrupt enabled */
#define ADC12IE31_1_H                    (0x0080)

/* ADC12IER2 Control Bits */
#define ADC12INIE                        (0x0002)        /* interrupt enable MEMx between ADC12HI and LO */
#define ADC12INIE_L                      (0x0002)
#define ADC12INIE_0                      (0x0000)        /* Interrupt disabled */
#define ADC12INIE_1                      (0x0002)        /* Interrupt enabled */
#define ADC12INIE_1_L                    (0x0002)
#define ADC12LOIE                        (0x0004)        /* interrupt enable MEMx < ADC12LO */
#define ADC12LOIE_L                      (0x0004)
#define ADC12LOIE_0                      (0x0000)        /* Interrupt disabled */
#define ADC12LOIE_1                      (0x0004)        /* Interrupt enabled */
#define ADC12LOIE_1_L                    (0x0004)
#define ADC12HIIE                        (0x0008)        /* interrupt enable MEMx > ADC12HI */
#define ADC12HIIE_L                      (0x0008)
#define ADC12HIIE_0                      (0x0000)        /* Interrupt disabled */
#define ADC12HIIE_1                      (0x0008)        /* Interrupt enabled */
#define ADC12HIIE_1_L                    (0x0008)
#define ADC12OVIE                        (0x0010)        /* ADC12MEMx overflow-interrupt enable */
#define ADC12OVIE_L                      (0x0010)
#define ADC12OVIE_0                      (0x0000)        /* Interrupt disabled */
#define ADC12OVIE_1                      (0x0010)        /* Interrupt enabled */
#define ADC12OVIE_1_L                    (0x0010)
#define ADC12TOVIE                       (0x0020)        /* conversion-time-overflow interrupt enable */
#define ADC12TOVIE_L                     (0x0020)
#define ADC12TOVIE_0                     (0x0000)        /* Interrupt disabled */
#define ADC12TOVIE_1                     (0x0020)        /* Interrupt enabled */
#define ADC12TOVIE_1_L                   (0x0020)
#define ADC12RDYIE                       (0x0040)        /* interrupt enable ADC ref buffer ready */
#define ADC12RDYIE_L                     (0x0040)
#define ADC12RDYIE_0                     (0x0000)        /* Interrupt disabled */
#define ADC12RDYIE_1                     (0x0040)        /* Interrupt enabled */
#define ADC12RDYIE_1_L                   (0x0040)

/* ADC12IV Control Bits */
#define ADC12RDYIE                       (0x0040)        /* interrupt enable ADC ref buffer ready */
#define ADC12RDYIE_L                     (0x0040)
#define ADC12IV0                         (0x0001)        /* interrupt vector value */
#define ADC12IV0_L                       (0x0001)
#define ADC12IV1                         (0x0002)        /* interrupt vector value */
#define ADC12IV1_L                       (0x0002)
#define ADC12IV2                         (0x0004)        /* interrupt vector value */
#define ADC12IV2_L                       (0x0004)
#define ADC12IV3                         (0x0008)        /* interrupt vector value */
#define ADC12IV3_L                       (0x0008)
#define ADC12IV4                         (0x0010)        /* interrupt vector value */
#define ADC12IV4_L                       (0x0010)
#define ADC12IV5                         (0x0020)        /* interrupt vector value */
#define ADC12IV5_L                       (0x0020)
#define ADC12IV6                         (0x0040)        /* interrupt vector value */
#define ADC12IV6_L                       (0x0040)
#define ADC12IV7                         (0x0080)        /* interrupt vector value */
#define ADC12IV7_L                       (0x0080)
#define ADC12IV8                         (0x0100)        /* interrupt vector value */
#define ADC12IV8_H                       (0x0001)
#define ADC12IV9                         (0x0200)        /* interrupt vector value */
#define ADC12IV9_H                       (0x0002)
#define ADC12IV10                        (0x0400)        /* interrupt vector value */
#define ADC12IV10_H                      (0x0004)
#define ADC12IV11                        (0x0800)        /* interrupt vector value */
#define ADC12IV11_H                      (0x0008)
#define ADC12IV12                        (0x1000)        /* interrupt vector value */
#define ADC12IV12_H                      (0x0010)
#define ADC12IV13                        (0x2000)        /* interrupt vector value */
#define ADC12IV13_H                      (0x0020)
#define ADC12IV14                        (0x4000)        /* interrupt vector value */
#define ADC12IV14_H                      (0x0040)
#define ADC12IV15                        (0x8000)        /* interrupt vector value */
#define ADC12IV15_H                      (0x0080)
#define ADC12IV_0                        (0x0000)        /* Interrupt Source: No interrupt pending, Interrupt Flag: None */
#define ADC12IV_2                        (0x0002)        /* Interrupt Source: ADC12MEMx overflow, Interrupt Flag: 
                                                            ADC12OVIFG, Interrupt Priority: Highest */
#define ADC12IV_2_L                      (0x0002)
#define ADC12IV_4                        (0x0004)        /* Interrupt Source: Conversion time overflow, Interrupt Flag: 
                                                            ADC12TOVIFG */
#define ADC12IV_4_L                      (0x0004)
#define ADC12IV_6                        (0x0006)        /* Interrupt Source: ADC12 window high interrupt flag, Interrupt 
                                                            Flag: ADC12HIIFG */
#define ADC12IV_6_L                      (0x0006)
#define ADC12IV_8                        (0x0008)        /* Interrupt Source: ADC12 window low interrupt flag, Interrupt 
                                                            Flag: ADC12LOIFG */
#define ADC12IV_8_L                      (0x0008)
#define ADC12IV_10                       (0x000a)        /* Interrupt Source: ADC12 in-window interrupt flag, Interrupt 
                                                            Flag: ADC12INIFG */
#define ADC12IV_10_L                     (0x000a)
#define ADC12IV_12                       (0x000c)        /* Interrupt Source: ADC12MEM0 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG0 */
#define ADC12IV_12_L                     (0x000c)
#define ADC12IV_14                       (0x000e)        /* Interrupt Source: ADC12MEM1 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG1 */
#define ADC12IV_14_L                     (0x000e)
#define ADC12IV_16                       (0x0010)        /* Interrupt Source: ADC12MEM2 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG2 */
#define ADC12IV_16_L                     (0x0010)
#define ADC12IV_18                       (0x0012)        /* Interrupt Source: ADC12MEM3 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG3 */
#define ADC12IV_18_L                     (0x0012)
#define ADC12IV_20                       (0x0014)        /* Interrupt Source: ADC12MEM4 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG4 */
#define ADC12IV_20_L                     (0x0014)
#define ADC12IV_22                       (0x0016)        /* Interrupt Source: ADC12MEM5 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG5 */
#define ADC12IV_22_L                     (0x0016)
#define ADC12IV_24                       (0x0018)        /* Interrupt Source: ADC12MEM6 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG6 */
#define ADC12IV_24_L                     (0x0018)
#define ADC12IV_26                       (0x001a)        /* Interrupt Source: ADC12MEM7 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG7 */
#define ADC12IV_26_L                     (0x001a)
#define ADC12IV_28                       (0x001c)        /* Interrupt Source: ADC12MEM8 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG8 */
#define ADC12IV_28_L                     (0x001c)
#define ADC12IV_30                       (0x001e)        /* Interrupt Source: ADC12MEM9 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG9 */
#define ADC12IV_30_L                     (0x001e)
#define ADC12IV_32                       (0x0020)        /* Interrupt Source: ADC12MEM10 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG10 */
#define ADC12IV_32_L                     (0x0020)
#define ADC12IV_34                       (0x0022)        /* Interrupt Source: ADC12MEM11 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG11 */
#define ADC12IV_34_L                     (0x0022)
#define ADC12IV_36                       (0x0024)        /* Interrupt Source: ADC12MEM12 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG12 */
#define ADC12IV_36_L                     (0x0024)
#define ADC12IV_38                       (0x0026)        /* Interrupt Source: ADC12MEM13 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG13 */
#define ADC12IV_38_L                     (0x0026)
#define ADC12IV_40                       (0x0028)        /* Interrupt Source: ADC12MEM14 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG14 */
#define ADC12IV_40_L                     (0x0028)
#define ADC12IV_42                       (0x002a)        /* Interrupt Source: ADC12MEM15 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG15 */
#define ADC12IV_42_L                     (0x002a)
#define ADC12IV_44                       (0x002c)        /* Interrupt Source: ADC12MEM16 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG16 */
#define ADC12IV_44_L                     (0x002c)
#define ADC12IV_46                       (0x002e)        /* Interrupt Source: ADC12MEM17 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG17 */
#define ADC12IV_46_L                     (0x002e)
#define ADC12IV_48                       (0x0030)        /* Interrupt Source: ADC12MEM18 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG18 */
#define ADC12IV_48_L                     (0x0030)
#define ADC12IV_50                       (0x0032)        /* Interrupt Source: ADC12MEM19 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG19 */
#define ADC12IV_50_L                     (0x0032)
#define ADC12IV_52                       (0x0034)        /* Interrupt Source: ADC12MEM20 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG20 */
#define ADC12IV_52_L                     (0x0034)
#define ADC12IV_54                       (0x0036)        /* Interrupt Source: ADC12MEM21 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG21 */
#define ADC12IV_54_L                     (0x0036)
#define ADC12IV_56                       (0x0038)        /* Interrupt Source: ADC12MEM22 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG22 */
#define ADC12IV_56_L                     (0x0038)
#define ADC12IV_58                       (0x003a)        /* Interrupt Source: ADC12MEM23 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG23 */
#define ADC12IV_58_L                     (0x003a)
#define ADC12IV_60                       (0x003c)        /* Interrupt Source: ADC12MEM24 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG24 */
#define ADC12IV_60_L                     (0x003c)
#define ADC12IV_62                       (0x003e)        /* Interrupt Source: ADC12MEM25 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG25 */
#define ADC12IV_62_L                     (0x003e)
#define ADC12IV_64                       (0x0040)        /* Interrupt Source: ADC12MEM26 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG26 */
#define ADC12IV_64_L                     (0x0040)
#define ADC12IV_66                       (0x0042)        /* Interrupt Source: ADC12MEM27 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG27 */
#define ADC12IV_66_L                     (0x0042)
#define ADC12IV_68                       (0x0044)        /* Interrupt Source: ADC12MEM28 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG28 */
#define ADC12IV_68_L                     (0x0044)
#define ADC12IV_70                       (0x0046)        /* Interrupt Source: ADC12MEM29 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG29 */
#define ADC12IV_70_L                     (0x0046)
#define ADC12IV_72                       (0x0048)        /* Interrupt Source: ADC12MEM30 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG30 */
#define ADC12IV_72_L                     (0x0048)
#define ADC12IV_74                       (0x004a)        /* Interrupt Source: ADC12MEM31 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG31 */
#define ADC12IV_74_L                     (0x004a)
#define ADC12IV_76                       (0x004c)        /* Interrupt Source: ADC12RDYIFG interrupt flag, Interrupt Flag: 
                                                            ADC12RDYIFG */
#define ADC12IV_76_L                     (0x004c)
#define ADC12IV__NONE                    (0x0000)        /* Interrupt Source: No interrupt pending, Interrupt Flag: None */
#define ADC12IV__ADC12OVIFG              (0x0002)        /* Interrupt Source: ADC12MEMx overflow, Interrupt Flag: 
                                                            ADC12OVIFG, Interrupt Priority: Highest */
#define ADC12IV__ADC12OVIFG_L            (0x0002)
#define ADC12IV__ADC12TOVIFG             (0x0004)        /* Interrupt Source: Conversion time overflow, Interrupt Flag: 
                                                            ADC12TOVIFG */
#define ADC12IV__ADC12TOVIFG_L           (0x0004)
#define ADC12IV__ADC12HIIFG              (0x0006)        /* Interrupt Source: ADC12 window high interrupt flag, Interrupt 
                                                            Flag: ADC12HIIFG */
#define ADC12IV__ADC12HIIFG_L            (0x0006)
#define ADC12IV__ADC12LOIFG              (0x0008)        /* Interrupt Source: ADC12 window low interrupt flag, Interrupt 
                                                            Flag: ADC12LOIFG */
#define ADC12IV__ADC12LOIFG_L            (0x0008)
#define ADC12IV__ADC12INIFG              (0x000a)        /* Interrupt Source: ADC12 in-window interrupt flag, Interrupt 
                                                            Flag: ADC12INIFG */
#define ADC12IV__ADC12INIFG_L            (0x000a)
#define ADC12IV__ADC12IFG0               (0x000c)        /* Interrupt Source: ADC12MEM0 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG0 */
#define ADC12IV__ADC12IFG0_L             (0x000c)
#define ADC12IV__ADC12IFG1               (0x000e)        /* Interrupt Source: ADC12MEM1 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG1 */
#define ADC12IV__ADC12IFG1_L             (0x000e)
#define ADC12IV__ADC12IFG2               (0x0010)        /* Interrupt Source: ADC12MEM2 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG2 */
#define ADC12IV__ADC12IFG2_L             (0x0010)
#define ADC12IV__ADC12IFG3               (0x0012)        /* Interrupt Source: ADC12MEM3 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG3 */
#define ADC12IV__ADC12IFG3_L             (0x0012)
#define ADC12IV__ADC12IFG4               (0x0014)        /* Interrupt Source: ADC12MEM4 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG4 */
#define ADC12IV__ADC12IFG4_L             (0x0014)
#define ADC12IV__ADC12IFG5               (0x0016)        /* Interrupt Source: ADC12MEM5 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG5 */
#define ADC12IV__ADC12IFG5_L             (0x0016)
#define ADC12IV__ADC12IFG6               (0x0018)        /* Interrupt Source: ADC12MEM6 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG6 */
#define ADC12IV__ADC12IFG6_L             (0x0018)
#define ADC12IV__ADC12IFG7               (0x001a)        /* Interrupt Source: ADC12MEM7 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG7 */
#define ADC12IV__ADC12IFG7_L             (0x001a)
#define ADC12IV__ADC12IFG8               (0x001c)        /* Interrupt Source: ADC12MEM8 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG8 */
#define ADC12IV__ADC12IFG8_L             (0x001c)
#define ADC12IV__ADC12IFG9               (0x001e)        /* Interrupt Source: ADC12MEM9 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG9 */
#define ADC12IV__ADC12IFG9_L             (0x001e)
#define ADC12IV__ADC12IFG10              (0x0020)        /* Interrupt Source: ADC12MEM10 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG10 */
#define ADC12IV__ADC12IFG10_L            (0x0020)
#define ADC12IV__ADC12IFG11              (0x0022)        /* Interrupt Source: ADC12MEM11 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG11 */
#define ADC12IV__ADC12IFG11_L            (0x0022)
#define ADC12IV__ADC12IFG12              (0x0024)        /* Interrupt Source: ADC12MEM12 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG12 */
#define ADC12IV__ADC12IFG12_L            (0x0024)
#define ADC12IV__ADC12IFG13              (0x0026)        /* Interrupt Source: ADC12MEM13 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG13 */
#define ADC12IV__ADC12IFG13_L            (0x0026)
#define ADC12IV__ADC12IFG14              (0x0028)        /* Interrupt Source: ADC12MEM14 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG14 */
#define ADC12IV__ADC12IFG14_L            (0x0028)
#define ADC12IV__ADC12IFG15              (0x002a)        /* Interrupt Source: ADC12MEM15 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG15 */
#define ADC12IV__ADC12IFG15_L            (0x002a)
#define ADC12IV__ADC12IFG16              (0x002c)        /* Interrupt Source: ADC12MEM16 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG16 */
#define ADC12IV__ADC12IFG16_L            (0x002c)
#define ADC12IV__ADC12IFG17              (0x002e)        /* Interrupt Source: ADC12MEM17 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG17 */
#define ADC12IV__ADC12IFG17_L            (0x002e)
#define ADC12IV__ADC12IFG18              (0x0030)        /* Interrupt Source: ADC12MEM18 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG18 */
#define ADC12IV__ADC12IFG18_L            (0x0030)
#define ADC12IV__ADC12IFG19              (0x0032)        /* Interrupt Source: ADC12MEM19 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG19 */
#define ADC12IV__ADC12IFG19_L            (0x0032)
#define ADC12IV__ADC12IFG20              (0x0034)        /* Interrupt Source: ADC12MEM20 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG20 */
#define ADC12IV__ADC12IFG20_L            (0x0034)
#define ADC12IV__ADC12IFG21              (0x0036)        /* Interrupt Source: ADC12MEM21 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG21 */
#define ADC12IV__ADC12IFG21_L            (0x0036)
#define ADC12IV__ADC12IFG22              (0x0038)        /* Interrupt Source: ADC12MEM22 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG22 */
#define ADC12IV__ADC12IFG22_L            (0x0038)
#define ADC12IV__ADC12IFG23              (0x003a)        /* Interrupt Source: ADC12MEM23 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG23 */
#define ADC12IV__ADC12IFG23_L            (0x003a)
#define ADC12IV__ADC12IFG24              (0x003c)        /* Interrupt Source: ADC12MEM24 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG24 */
#define ADC12IV__ADC12IFG24_L            (0x003c)
#define ADC12IV__ADC12IFG25              (0x003e)        /* Interrupt Source: ADC12MEM25 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG25 */
#define ADC12IV__ADC12IFG25_L            (0x003e)
#define ADC12IV__ADC12IFG26              (0x0040)        /* Interrupt Source: ADC12MEM26 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG26 */
#define ADC12IV__ADC12IFG26_L            (0x0040)
#define ADC12IV__ADC12IFG27              (0x0042)        /* Interrupt Source: ADC12MEM27 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG27 */
#define ADC12IV__ADC12IFG27_L            (0x0042)
#define ADC12IV__ADC12IFG28              (0x0044)        /* Interrupt Source: ADC12MEM28 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG28 */
#define ADC12IV__ADC12IFG28_L            (0x0044)
#define ADC12IV__ADC12IFG29              (0x0046)        /* Interrupt Source: ADC12MEM29 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG29 */
#define ADC12IV__ADC12IFG29_L            (0x0046)
#define ADC12IV__ADC12IFG30              (0x0048)        /* Interrupt Source: ADC12MEM30 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG30 */
#define ADC12IV__ADC12IFG30_L            (0x0048)
#define ADC12IV__ADC12IFG31              (0x004a)        /* Interrupt Source: ADC12MEM31 interrupt flag, Interrupt Flag: 
                                                            ADC12IFG31 */
#define ADC12IV__ADC12IFG31_L            (0x004a)
#define ADC12IV__ADC12RDYIFG             (0x004c)        /* Interrupt Source: ADC12RDYIFG interrupt flag, Interrupt Flag: 
                                                            ADC12RDYIFG */
#define ADC12IV__ADC12RDYIFG_L           (0x004c)

/* ADC12MCTL Control Bits */
#define ADC12INCH                        (0x001f)        /* Input channel select */
#define ADC12INCH_L                      (0x001f)
#define ADC12INCH0                       (0x0001)        /* Input channel select */
#define ADC12INCH0_L                     (0x0001)
#define ADC12INCH1                       (0x0002)        /* Input channel select */
#define ADC12INCH1_L                     (0x0002)
#define ADC12INCH2                       (0x0004)        /* Input channel select */
#define ADC12INCH2_L                     (0x0004)
#define ADC12INCH3                       (0x0008)        /* Input channel select */
#define ADC12INCH3_L                     (0x0008)
#define ADC12INCH4                       (0x0010)        /* Input channel select */
#define ADC12INCH4_L                     (0x0010)
#define ADC12INCH_0                      (0x0000)        /* If ADC12DIF = 0: A0; If ADC12DIF = 1: Ain+ = A0, Ain- = A1 */
#define ADC12INCH_1                      (0x0001)        /* If ADC12DIF = 0: A1; If ADC12DIF = 1: Ain+ = A0, Ain- = A1 */
#define ADC12INCH_1_L                    (0x0001)
#define ADC12INCH_2                      (0x0002)        /* If ADC12DIF = 0: A2; If ADC12DIF = 1: Ain+ = A2, Ain- = A3 */
#define ADC12INCH_2_L                    (0x0002)
#define ADC12INCH_3                      (0x0003)        /* If ADC12DIF = 0: A3; If ADC12DIF = 1: Ain+ = A2, Ain- = A3 */
#define ADC12INCH_3_L                    (0x0003)
#define ADC12INCH_4                      (0x0004)        /* If ADC12DIF = 0: A4; If ADC12DIF = 1: Ain+ = A4, Ain- = A5 */
#define ADC12INCH_4_L                    (0x0004)
#define ADC12INCH_5                      (0x0005)        /* If ADC12DIF = 0: A5; If ADC12DIF = 1: Ain+ = A4, Ain- = A5 */
#define ADC12INCH_5_L                    (0x0005)
#define ADC12INCH_6                      (0x0006)        /* If ADC12DIF = 0: A6; If ADC12DIF = 1: Ain+ = A6, Ain- = A7 */
#define ADC12INCH_6_L                    (0x0006)
#define ADC12INCH_7                      (0x0007)        /* If ADC12DIF = 0: A7; If ADC12DIF = 1: Ain+ = A6, Ain- = A7 */
#define ADC12INCH_7_L                    (0x0007)
#define ADC12INCH_8                      (0x0008)        /* If ADC12DIF = 0: A8; If ADC12DIF = 1: Ain+ = A8, Ain- = A9 */
#define ADC12INCH_8_L                    (0x0008)
#define ADC12INCH_9                      (0x0009)        /* If ADC12DIF = 0: A9; If ADC12DIF = 1: Ain+ = A8, Ain- = A9 */
#define ADC12INCH_9_L                    (0x0009)
#define ADC12INCH_10                     (0x000a)        /* If ADC12DIF = 0: A10; If ADC12DIF = 1: Ain+ = A10, Ain- = A11 */
#define ADC12INCH_10_L                   (0x000a)
#define ADC12INCH_11                     (0x000b)        /* If ADC12DIF = 0: A11; If ADC12DIF = 1: Ain+ = A10, Ain- = A11 */
#define ADC12INCH_11_L                   (0x000b)
#define ADC12INCH_12                     (0x000c)        /* If ADC12DIF = 0: A12; If ADC12DIF = 1: Ain+ = A12, Ain- = A13 */
#define ADC12INCH_12_L                   (0x000c)
#define ADC12INCH_13                     (0x000d)        /* If ADC12DIF = 0: A13; If ADC12DIF = 1: Ain+ = A12, Ain- = A13 */
#define ADC12INCH_13_L                   (0x000d)
#define ADC12INCH_14                     (0x000e)        /* If ADC12DIF = 0: A14; If ADC12DIF = 1: Ain+ = A14, Ain- = A15 */
#define ADC12INCH_14_L                   (0x000e)
#define ADC12INCH_15                     (0x000f)        /* If ADC12DIF = 0: A15; If ADC12DIF = 1: Ain+ = A14, Ain- = A15 */
#define ADC12INCH_15_L                   (0x000f)
#define ADC12INCH_16                     (0x0010)        /* If ADC12DIF = 0: A16; If ADC12DIF = 1: Ain+ = A16, Ain- = A17 */
#define ADC12INCH_16_L                   (0x0010)
#define ADC12INCH_17                     (0x0011)        /* If ADC12DIF = 0: A17; If ADC12DIF = 1: Ain+ = A16, Ain- = A17 */
#define ADC12INCH_17_L                   (0x0011)
#define ADC12INCH_18                     (0x0012)        /* If ADC12DIF = 0: A18; If ADC12DIF = 1: Ain+ = A18, Ain- = A19 */
#define ADC12INCH_18_L                   (0x0012)
#define ADC12INCH_19                     (0x0013)        /* If ADC12DIF = 0: A19; If ADC12DIF = 1: Ain+ = A18, Ain- = A19 */
#define ADC12INCH_19_L                   (0x0013)
#define ADC12INCH_20                     (0x0014)        /* If ADC12DIF = 0: A20; If ADC12DIF = 1: Ain+ = A20, Ain- = A21 */
#define ADC12INCH_20_L                   (0x0014)
#define ADC12INCH_21                     (0x0015)        /* If ADC12DIF = 0: A21; If ADC12DIF = 1: Ain+ = A20, Ain- = A21 */
#define ADC12INCH_21_L                   (0x0015)
#define ADC12INCH_22                     (0x0016)        /* If ADC12DIF = 0: A22; If ADC12DIF = 1: Ain+ = A22, Ain- = A23 */
#define ADC12INCH_22_L                   (0x0016)
#define ADC12INCH_23                     (0x0017)        /* If ADC12DIF = 0: A23; If ADC12DIF = 1: Ain+ = A22, Ain- = A23 */
#define ADC12INCH_23_L                   (0x0017)
#define ADC12INCH_24                     (0x0018)        /* If ADC12DIF = 0: A24; If ADC12DIF = 1: Ain+ = A24, Ain- = A25 */
#define ADC12INCH_24_L                   (0x0018)
#define ADC12INCH_25                     (0x0019)        /* If ADC12DIF = 0: A25; If ADC12DIF = 1: Ain+ = A24, Ain- = A25 */
#define ADC12INCH_25_L                   (0x0019)
#define ADC12INCH_26                     (0x001a)        /* If ADC12DIF = 0: A26; If ADC12DIF = 1: Ain+ = A26, Ain- =A27 */
#define ADC12INCH_26_L                   (0x001a)
#define ADC12INCH_27                     (0x001b)        /* If ADC12DIF = 0: A27; If ADC12DIF = 1: Ain+ = A26, Ain- = A27 */
#define ADC12INCH_27_L                   (0x001b)
#define ADC12INCH_28                     (0x001c)        /* If ADC12DIF = 0: A28; If ADC12DIF = 1: Ain+ = A28, Ain- = A29 */
#define ADC12INCH_28_L                   (0x001c)
#define ADC12INCH_29                     (0x001d)        /* If ADC12DIF = 0: A29; If ADC12DIF = 1: Ain+ = A28, Ain- = A29 */
#define ADC12INCH_29_L                   (0x001d)
#define ADC12INCH_30                     (0x001e)        /* If ADC12DIF = 0: A30; If ADC12DIF = 1: Ain+ = A30, Ain- = A31 */
#define ADC12INCH_30_L                   (0x001e)
#define ADC12INCH_31                     (0x001f)        /* If ADC12DIF = 0: A31; If ADC12DIF = 1: Ain+ = A30, Ain- = A31 */
#define ADC12INCH_31_L                   (0x001f)
#define ADC12EOS                         (0x0080)        /* End of sequence */
#define ADC12EOS_L                       (0x0080)
#define ADC12EOS_0                       (0x0000)        /* Not end of sequence */
#define ADC12EOS_1                       (0x0080)        /* End of sequence */
#define ADC12EOS_1_L                     (0x0080)
#define ADC12VRSEL                       (0x0f00)        /* reference selection */
#define ADC12VRSEL_H                     (0x000f)
#define ADC12VRSEL0                      (0x0100)        /* reference selection */
#define ADC12VRSEL0_H                    (0x0001)
#define ADC12VRSEL1                      (0x0200)        /* reference selection */
#define ADC12VRSEL1_H                    (0x0002)
#define ADC12VRSEL2                      (0x0400)        /* reference selection */
#define ADC12VRSEL2_H                    (0x0004)
#define ADC12VRSEL3                      (0x0800)        /* reference selection */
#define ADC12VRSEL3_H                    (0x0008)
#define ADC12VRSEL_0                     (0x0000)        /* VR+ = AVCC, VR- = AVSS */
#define ADC12VRSEL_1                     (0x0100)        /* VR+ = VREF buffered, VR- = AVSS */
#define ADC12VRSEL_1_H                   (0x0001)
#define ADC12VRSEL_2                     (0x0200)        /* VR+ = VeREF-, VR- = AVSS */
#define ADC12VRSEL_2_H                   (0x0002)
#define ADC12VRSEL_3                     (0x0300)        /* VR+ = VeREF+ buffered, VR- = AVSS */
#define ADC12VRSEL_3_H                   (0x0003)
#define ADC12VRSEL_4                     (0x0400)        /* VR+ = VeREF+, VR- = AVSS */
#define ADC12VRSEL_4_H                   (0x0004)
#define ADC12VRSEL_5                     (0x0500)        /* VR+ = AVCC, VR- = VeREF+ buffered */
#define ADC12VRSEL_5_H                   (0x0005)
#define ADC12VRSEL_6                     (0x0600)        /* VR+ = AVCC, VR- = VeREF+ */
#define ADC12VRSEL_6_H                   (0x0006)
#define ADC12VRSEL_7                     (0x0700)        /* VR+ = VREF buffered, VR- = VeREF+ */
#define ADC12VRSEL_7_H                   (0x0007)
#define ADC12VRSEL_8                     (0x0800)        /* Reserved */
#define ADC12VRSEL_8_H                   (0x0008)
#define ADC12VRSEL_9                     (0x0900)        /* VR+ = AVCC, VR- = VREF buffered */
#define ADC12VRSEL_9_H                   (0x0009)
#define ADC12VRSEL_10                    (0x0a00)        /* Reserved */
#define ADC12VRSEL_10_H                  (0x000a)
#define ADC12VRSEL_11                    (0x0b00)        /* VR+ = VeREF+, VR- = VREF buffered */
#define ADC12VRSEL_11_H                  (0x000b)
#define ADC12VRSEL_12                    (0x0c00)        /* VR+ = AVCC, VR- = VeREF- */
#define ADC12VRSEL_12_H                  (0x000c)
#define ADC12VRSEL_13                    (0x0d00)        /* VR+ = VREF buffered, VR- = VeREF- */
#define ADC12VRSEL_13_H                  (0x000d)
#define ADC12VRSEL_14                    (0x0e00)        /* VR+ = VeREF+, VR- = VeREF- */
#define ADC12VRSEL_14_H                  (0x000e)
#define ADC12VRSEL_15                    (0x0f00)        /* VR+ = VeREF+ buffered, VR- = VeREF- */
#define ADC12VRSEL_15_H                  (0x000f)
#define ADC12DIF                         (0x2000)        /* Differential mode. */
#define ADC12DIF_H                       (0x0020)
#define ADC12DIF_0                       (0x0000)        /* Single-ended mode enabled */
#define ADC12DIF_1                       (0x2000)        /* Differential mode enabled */
#define ADC12DIF_1_H                     (0x0020)
#define ADC12WINC                        (0x4000)        /* Comparator window enable */
#define ADC12WINC_H                      (0x0040)
#define ADC12WINC_0                      (0x0000)        /* Comparator window disabled */
#define ADC12WINC_1                      (0x4000)        /* Comparator window enabled */
#define ADC12WINC_1_H                    (0x0040)

/* ADC12MEM Control Bits */
#define CONVERSION_RESULTS               (0xffff)        /* Conversion Results */
#define CONVERSION_RESULTS_L             (0x00ff)
#define CONVERSION_RESULTS_H             (0x00ff)
#define CONVERSION_RESULTS0              (0x0001)        /* Conversion Results */
#define CONVERSION_RESULTS0_L            (0x0001)
#define CONVERSION_RESULTS1              (0x0002)        /* Conversion Results */
#define CONVERSION_RESULTS1_L            (0x0002)
#define CONVERSION_RESULTS2              (0x0004)        /* Conversion Results */
#define CONVERSION_RESULTS2_L            (0x0004)
#define CONVERSION_RESULTS3              (0x0008)        /* Conversion Results */
#define CONVERSION_RESULTS3_L            (0x0008)
#define CONVERSION_RESULTS4              (0x0010)        /* Conversion Results */
#define CONVERSION_RESULTS4_L            (0x0010)
#define CONVERSION_RESULTS5              (0x0020)        /* Conversion Results */
#define CONVERSION_RESULTS5_L            (0x0020)
#define CONVERSION_RESULTS6              (0x0040)        /* Conversion Results */
#define CONVERSION_RESULTS6_L            (0x0040)
#define CONVERSION_RESULTS7              (0x0080)        /* Conversion Results */
#define CONVERSION_RESULTS7_L            (0x0080)
#define CONVERSION_RESULTS8              (0x0100)        /* Conversion Results */
#define CONVERSION_RESULTS8_H            (0x0001)
#define CONVERSION_RESULTS9              (0x0200)        /* Conversion Results */
#define CONVERSION_RESULTS9_H            (0x0002)
#define CONVERSION_RESULTS10             (0x0400)        /* Conversion Results */
#define CONVERSION_RESULTS10_H           (0x0004)
#define CONVERSION_RESULTS11             (0x0800)        /* Conversion Results */
#define CONVERSION_RESULTS11_H           (0x0008)
#define CONVERSION_RESULTS12             (0x1000)        /* Conversion Results */
#define CONVERSION_RESULTS12_H           (0x0010)
#define CONVERSION_RESULTS13             (0x2000)        /* Conversion Results */
#define CONVERSION_RESULTS13_H           (0x0020)
#define CONVERSION_RESULTS14             (0x4000)        /* Conversion Results */
#define CONVERSION_RESULTS14_H           (0x0040)
#define CONVERSION_RESULTS15             (0x8000)        /* Conversion Results */
#define CONVERSION_RESULTS15_H           (0x0080)

#define __MSP430_BASEADDRESS_ADC12_B__ 0x0800
#define ADC12_B_BASE           __MSP430_BASEADDRESS_ADC12_B__

/** UC Ports */
extern uint16_t UCA0BRW;
extern uint16_t UCA0CTLW0;
extern uint16_t UCA0CTLW1;
extern uint16_t UCA0MCTLW;
extern uint16_t UCA0IE;
extern uint16_t UCA0STATW;
extern uint16_t UCA0TXBUF;
extern uint16_t UCA0RXBUF;

extern uint16_t UCA1BRW;
extern uint16_t UCA1CTLW0;
extern uint16_t UCA1CTLW1;
extern uint16_t UCA1MCTLW;
extern uint16_t UCA1IE;
extern uint16_t UCA1STATW;
extern uint16_t UCA1TXBUF;
extern uint16_t UCA1RXBUF;

extern uint16_t UCA2BRW;
extern uint16_t UCA2CTLW0;
extern uint16_t UCA2CTLW1;
extern uint16_t UCA2MCTLW;
extern uint16_t UCA2IE;
extern uint16_t UCA2STATW;
extern uint16_t UCA2TXBUF;
extern uint16_t UCA2RXBUF;

extern uint16_t UCA3BRW;
extern uint16_t UCA3CTLW0;
extern uint16_t UCA3CTLW1;
extern uint16_t UCA3MCTLW;
extern uint16_t UCA3IE;
extern uint16_t UCA3STATW;
extern uint16_t UCA3TXBUF;
extern uint16_t UCA3RXBUF;



/** GPIO Ports and Settings */
extern uint16_t P1OUT;
extern uint16_t P2OUT;
extern uint16_t P3OUT;
extern uint16_t P4OUT;
extern uint16_t P5OUT;
extern uint16_t P6OUT;
extern uint16_t P7OUT;
extern uint16_t P8OUT;

extern uint16_t P1IN;
extern uint16_t P2IN;
extern uint16_t P3IN;
extern uint16_t P4IN;
extern uint16_t P5IN;
extern uint16_t P6IN;
extern uint16_t P7IN;
extern uint16_t P8IN;

extern uint16_t P1DIR;
extern uint16_t P2DIR;
extern uint16_t P3DIR;
extern uint16_t P4DIR;
extern uint16_t P5DIR;
extern uint16_t P6DIR;
extern uint16_t P7DIR;
extern uint16_t P8DIR;

extern uint16_t P1SEL0;
extern uint16_t P2SEL0;
extern uint16_t P3SEL0;
extern uint16_t P4SEL0;
extern uint16_t P5SEL0;
extern uint16_t P6SEL0;
extern uint16_t P7SEL0;
extern uint16_t P8SEL0;

extern uint16_t P1SEL1;
extern uint16_t P2SEL1;
extern uint16_t P3SEL1;
extern uint16_t P4SEL1;
extern uint16_t P5SEL1;
extern uint16_t P6SEL1;
extern uint16_t P7SEL1;
extern uint16_t P8SEL1;

extern uint16_t P1REN;
extern uint16_t P2REN;
extern uint16_t P3REN;
extern uint16_t P4REN;
extern uint16_t P5REN;
extern uint16_t P6REN;
extern uint16_t P7REN;
extern uint16_t P8REN;

extern uint16_t P1IFG;
extern uint16_t P2IFG;
extern uint16_t P3IFG;
extern uint16_t P4IFG;
extern uint16_t P5IFG;
extern uint16_t P6IFG;
extern uint16_t P7IFG;
extern uint16_t P8IFG;

extern uint16_t P1IES;
extern uint16_t P2IES;
extern uint16_t P3IES;
extern uint16_t P4IES;
extern uint16_t P5IES;
extern uint16_t P6IES;
extern uint16_t P7IES;
extern uint16_t P8IES;

extern uint16_t P1IE;
extern uint16_t P2IE;
extern uint16_t P3IE;
extern uint16_t P4IE;
extern uint16_t P5IE;
extern uint16_t P6IE;
extern uint16_t P7IE;
extern uint16_t P8IE;



#define UCASTP_0     0x00
#define UCASTP_1    0x01
#define UCASTP_2    0x02

#endif