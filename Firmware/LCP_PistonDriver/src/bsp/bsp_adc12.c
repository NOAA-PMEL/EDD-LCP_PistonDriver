#include "bsp_adc12.h"


//void ADC12_ISR(void);

static uint16_t *adc;

//static const ADC12_B_initParam initParam = {
//    .sampleHoldSignalSourceSelect = ADC12_B_SAMPLEHOLDSOURCE_SC,
//    .clockSourceSelect = ADC12_B_CLOCKSOURCE_ADC12OSC,
//    .clockSourceDivider = ADC12_B_CLOCKDIVIDER_1,
//    .clockSourcePredivider = ADC12_B_CLOCKPREDIVIDER__1,
//    .internalChannelMap = ADC12_B_NOINTCH,
//	
//        
//};

static const ADC12_B_initParam initParam = {
    .sampleHoldSignalSourceSelect = ADC12_B_SAMPLEHOLDSOURCE_SC,
    .clockSourceSelect = ADC12_B_CLOCKSOURCE_ADC12OSC,
    .clockSourceDivider = ADC12_B_CLOCKDIVIDER_1,
    .clockSourcePredivider = ADC12_B_CLOCKPREDIVIDER__1,
    .internalChannelMap = ADC12_B_NOINTCH,
	
        
};


//static const ADC12_B_configureMemoryParam configureMemoryParam = {
//    .memoryBufferControlIndex = ADC12_B_MEMORY_0,
//    .inputSourceSelect = ADC12_B_INPUT_A2,
//    .refVoltageSourceSelect = ADC12_B_VREFPOS_AVCC_VREFNEG_VSS,
//    .endOfSequence = ADC12_B_NOTENDOFSEQUENCE,
//    .windowComparatorSelect = ADC12_B_WINDOW_COMPARATOR_DISABLE,
//    .differentialModeSelect = ADC12_B_DIFFERENTIAL_MODE_DISABLE
//};

static const ADC12_B_configureMemoryParam configureMemoryParam = {
    .memoryBufferControlIndex = ADC12_B_MEMORY_0,
    .inputSourceSelect = ADC12_B_INPUT_A2,
    .refVoltageSourceSelect = ADC12_B_VREFPOS_INTBUF_VREFNEG_VSS,
    .endOfSequence = ADC12_B_NOTENDOFSEQUENCE,
    .windowComparatorSelect = ADC12_B_WINDOW_COMPARATOR_DISABLE,
    .differentialModeSelect = ADC12_B_DIFFERENTIAL_MODE_DISABLE
};

void BSP_ADC12_Init(uint32_t addr)
{
  
  //If ref generator busy, WAIT
    while (Ref_A_isRefGenBusy(REF_A_BASE)) ;
  
    //Select internal ref = 1.2V
    Ref_A_setReferenceVoltage(REF_A_BASE,
      REF_A_VREF2_5V);
    
    //Turn on Reference Voltage
    Ref_A_enableReferenceVoltage(REF_A_BASE);
    
    ADC12_B_init(ADC12_B_BASE, (ADC12_B_initParam*) &initParam);
    
    //Enable the ADC12B module
    ADC12_B_enable(ADC12_B_BASE);

    /*
     * Base address of ADC12B Module
     * For memory buffers 0-7 sample/hold for 64 clock cycles
     * For memory buffers 8-15 sample/hold for 4 clock cycles (default)
     * Disable Multiple Sampling
     */
    ADC12_B_setupSamplingTimer(ADC12_B_BASE,
        ADC12_B_CYCLEHOLD_1024_CYCLES,
        ADC12_B_CYCLEHOLD_1024_CYCLES,
        ADC12_B_MULTIPLESAMPLESENABLE);
    
    ADC12_B_configureMemory(ADC12_B_BASE, (ADC12_B_configureMemoryParam*) &configureMemoryParam);
    
    ADC12_B_clearInterrupt(ADC12_B_BASE,
    	0,
    	ADC12_B_IFG0
    	);
    
//    Enable memory buffer 0 interrupt
//    ADC12_B_enableInterrupt(ADC12_B_BASE,
//      ADC12_B_IE0,
//      0,
//      0);
//  /** Init the ADC Module */
//  ADC12_B_init(ADC12_B_BASE, (ADC12_B_initParam*) &initParam),
//  
//  /** Enable the ADC12B module */
//  ADC12_B_enable(ADC12_B_BASE);
//  
//  ADC12_B_configureMemory(ADC12_B_BASE, (ADC12_B_configureMemoryParam*) &configureMemoryParam);
//
//
//  ADC12_B_clearInterrupt(ADC12_B_BASE,
//      0,
//      ADC12_B_IFG0
//      );
//
//  //Enable memory buffer 0 interrupt
//  ADC12_B_enableInterrupt(ADC12_B_BASE,
//    ADC12_B_IE0,
//    0,
//    0);
//  
  ADC12_B_startConversion(ADC12_B_BASE,
            ADC12_B_MEMORY_0,
            ADC12_B_REPEATED_SINGLECHANNEL);
  
  adc = (uint16_t*) addr; 
    
}


float BSP_ADC12_Read(void)
{
  
//  uint16_t temp = ADC12_B_getResults(ADC12_B_BASE, ADC12_B_MEMORY_0);
//  return (float) temp;
////  temp = temp + 1;
  return (float) *adc;
  
}

float BSP_ADC12_Read_voltage(void)
{
  float volts = *adc * 2.5f;
  volts = volts / 4096;
  return volts;
  
}


uint32_t BSP_ADC12_Address_for_DMA(void)
{
  return ADC12_B_getMemoryAddressForDMA(ADC12_B_BASE, ADC12_B_MEMORY_0);
}






//#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
//#pragma vector=ADC12_VECTOR
//__interrupt
//#elif defined(__GNUC__)
//__attribute__((interrupt(ADC12_VECTOR)))
//#endif
//void ADC12_ISR(void)
//{
//  switch(__even_in_range(ADC12IV,12))
//  {
//    case  0: break;                         // Vector  0:  No interrupt
//    case  2: break;                         // Vector  2:  ADC12BMEMx Overflow
//    case  4: break;                         // Vector  4:  Conversion time overflow
//    case  6: break;                         // Vector  6:  ADC12BHI
//    case  8: break;                         // Vector  8:  ADC12BLO
//    case 10: break;                         // Vector 10:  ADC12BIN
//    case 12:                                // Vector 12:  ADC12BMEM0 Interrupt
////      *adc = ADC12_B_getResults(ADC12_B_BASE, ADC12_B_MEMORY_0);
//
////      __bic_SR_register_on_exit(LPM0_bits); // Exit active CPU
//      break;                                // Clear CPUOFF bit from 0(SR)
//    case 14: break;                         // Vector 14:  ADC12BMEM1
//    case 16: break;                         // Vector 16:  ADC12BMEM2
//    case 18: break;                         // Vector 18:  ADC12BMEM3
//    case 20: break;                         // Vector 20:  ADC12BMEM4
//    case 22: break;                         // Vector 22:  ADC12BMEM5
//    case 24: break;                         // Vector 24:  ADC12BMEM6
//    case 26: break;                         // Vector 26:  ADC12BMEM7
//    case 28: break;                         // Vector 28:  ADC12BMEM8
//    case 30: break;                         // Vector 30:  ADC12BMEM9
//    case 32: break;                         // Vector 32:  ADC12BMEM10
//    case 34: break;                         // Vector 34:  ADC12BMEM11
//    case 36: break;                         // Vector 36:  ADC12BMEM12
//    case 38: break;                         // Vector 38:  ADC12BMEM13
//    case 40: break;                         // Vector 40:  ADC12BMEM14
//    case 42: break;                         // Vector 42:  ADC12BMEM15
//    case 44: break;                         // Vector 44:  ADC12BMEM16
//    case 46: break;                         // Vector 46:  ADC12BMEM17
//    case 48: break;                         // Vector 48:  ADC12BMEM18
//    case 50: break;                         // Vector 50:  ADC12BMEM19
//    case 52: break;                         // Vector 52:  ADC12BMEM20
//    case 54: break;                         // Vector 54:  ADC12BMEM21
//    case 56: break;                         // Vector 56:  ADC12BMEM22
//    case 58: break;                         // Vector 58:  ADC12BMEM23
//    case 60: break;                         // Vector 60:  ADC12BMEM24
//    case 62: break;                         // Vector 62:  ADC12BMEM25
//    case 64: break;                         // Vector 64:  ADC12BMEM26
//    case 66: break;                         // Vector 66:  ADC12BMEM27
//    case 68: break;                         // Vector 68:  ADC12BMEM28
//    case 70: break;                         // Vector 70:  ADC12BMEM29
//    case 72: break;                         // Vector 72:  ADC12BMEM30
//    case 74: break;                         // Vector 74:  ADC12BMEM31
//    case 76: break;                         // Vector 76:  ADC12BRDY
//    default: break;
//  }
//}
