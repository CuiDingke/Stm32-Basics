#include "adc.h"
//#define ADC1_DR_Address    ((uint32_t)0x4001244C)
//uint16_t ADCConvertedValue[2];

 void ADC1_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3 | RCC_APB2Periph_GPIOF, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_Init(GPIOF, &GPIO_InitStructure);				// PC1,输入时不用设置速率
	
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfChannel = 1;
  ADC_Init(ADC3, &ADC_InitStructure);

  ADC_ITConfig(ADC3, ADC_IT_EOC, ENABLE);
  ADC_RegularChannelConfig(ADC3, ADC_Channel_6, 1, ADC_SampleTime_239Cycles5);
  ADC_Cmd(ADC3, ENABLE);

  ADC_ResetCalibration(ADC3);

  while(ADC_GetResetCalibrationStatus(ADC3));
  ADC_StartCalibration(ADC3);
  while(ADC_GetCalibrationStatus(ADC3));  
  ADC_SoftwareStartConvCmd(ADC3, ENABLE);
}

/******************* (C) COPYRIGHT 2011 野火嵌入式开发工作室 *****END OF FILE****/

