#include "bsp_adc12.h"

static uint16_t *adc;

ADC12_B_initParam initParam = {
    .sampleHoldSignalSourceSelect = ADC12_B_SAMPLEHOLDSOURCE_SC,
    .clockSourceSelect = ADC12_B_CLOCKSOURCE_ADC12OSC,
    .clockSourceDivider = ADC12_B_CLOCKDIVIDER_1,
    .clockSourcePredivider = ADC12_B_CLOCKPREDIVIDER__1,
    .internalChannelMap = ADC12_B_NOINTCH,
	
        
};

ADC12_B_configureMemoryParam configureMemoryParam = {
    .memoryBufferControlIndex = ADC12_B_MEMORY_0,
    .inputSourceSelect = ADC12_B_INPUT_A2,
    .refVoltageSourceSelect = ADC12_B_VREFPOS_AVCC_VREFNEG_VSS,
    .endOfSequence = ADC12_B_NOTENDOFSEQUENCE,
    .windowComparatorSelect = ADC12_B_WINDOW_COMPARATOR_DISABLE,
    .differentialModeSelect = ADC12_B_DIFFERENTIAL_MODE_DISABLE
};


void BSP_ADC12_Init(uint32_t addr)
{
  /** Init the ADC Module */
  ADC12_B_init(ADC12_B_BASE, &initParam),
  
  /** Enable the ADC12B module */
  ADC12_B_enable(ADC12_B_BASE);
  
  ADC12_B_configureMemory(ADC12_B_BASE, &configureMemoryParam);


  ADC12_B_clearInterrupt(ADC12_B_BASE,
      0,
      ADC12_B_IFG0
      );

  //Enable memory buffer 0 interrupt
  ADC12_B_enableInterrupt(ADC12_B_BASE,
    ADC12_B_IE0,
    0,
    0);
  
  ADC12_B_startConversion(ADC12_B_BASE,
            ADC12_B_MEMORY_0,
            ADC12_B_SINGLECHANNEL);
  
  adc = (uint16_t*) addr; 
    
}


float BSP_ADC12_Read(void)
{
  
//  uint16_t temp = ADC12_B_getResults(ADC12_B_BASE, ADC12_B_MEMORY_0);
//  return (float) temp;
  
  return (float) *adc;
  
}