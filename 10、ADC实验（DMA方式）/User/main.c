/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   adc1 �ɼ�ʵ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� iSO STM32 ������ 
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */

//time : pc1-1 0      1us
//       pc1-2 0 0.5us    1.5us
//			 pc1-3 0 0.5us 0.8us

#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "bsp_adc.h"

// ADC1ת���ĵ�ѹֵͨ��MDA��ʽ����SRAM
extern __IO uint16_t ADC_ConvertedValue[2];

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal[2];        

// �����ʱ
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
	/* USART1 config */
	USART1_Config();
	
	/* enable adc1 and config adc1 to dma mode */
	ADC1_Init();
	
	printf("\r\n ----����һ��ADCʵ��(DMA����)----\r\n");
	
	while (1)
	{
		ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3; // ��ȡת����ADֵ
	  ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
		printf("\r\n The current AD value[0] = 0x%04X \r\n", ADC_ConvertedValue[0] ); 
		printf("\r\n The current AD value[1] = 0x%04X \r\n", ADC_ConvertedValue[1] ); 
		printf("\r\n The current AD value[0] = %f V \r\n",ADC_ConvertedValueLocal[0]); 
	  printf("\r\n The current AD value[1] = %f V \r\n",ADC_ConvertedValueLocal[1]); 
		Delay(0xffffee);  
	}
}
/*********************************************END OF FILE**********************/
