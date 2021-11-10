#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "bsp_adc.h"
extern __IO uint16_t ADC_ConvertedValue[4];
float ADC_ConvertedValuetel[4];
int main(void)
{
	USART1_Config();
	ADC1_Init();
	ADC1_Cal();
  	  while(1)
			{
			ADC_ConvertedValuetel[0]=ADC_ConvertedValue[0]*3.3/4096;
			ADC_ConvertedValuetel[1]=ADC_ConvertedValue[1]*3.3/4096;
			ADC_ConvertedValuetel[2]=ADC_ConvertedValue[2]*3.3/4096;
			ADC_ConvertedValuetel[3]=ADC_ConvertedValue[3]*3.3/4096;//内部电压
			ADC_ConvertedValuetel[2]=(1.43-ADC_ConvertedValuetel[2])*1000/4.3+25;//内部温度
				printf("通道0，%f v\r\n",ADC_ConvertedValuetel[0]);
				printf("通道1，%f v\r\n",ADC_ConvertedValuetel[1]);
				printf("通道16，%f v\r\n",ADC_ConvertedValuetel[2]);
				printf("通道17，%f v\r\n",ADC_ConvertedValuetel[3]);
			}
}
