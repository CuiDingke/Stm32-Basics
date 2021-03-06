#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "bsp_adc.h"

// ADC1转换的电压值通过MDA方式传到SRAM
extern __IO uint16_t ADC_ConvertedValue[4];

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal[4]; 
float temp;
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
	USART1_Config();
	ADC1_Init();
	printf("\r\n ----这是一个ADC实验(DMA传输)----\r\n");
	while (1)
	{
		ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3; // 读取转换的AD值
	  ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
		ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
		ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
ADC_ConvertedValueLocal[3]=(1.43-ADC_ConvertedValueLocal[3])*1000/4.3+25;
		printf("\r\n The current AD value[0] = 0x%04X \r\n", ADC_ConvertedValue[0] ); 
		printf("\r\n The current AD value[1] = 0x%04X \r\n", ADC_ConvertedValue[1] ); 
		printf("\r\n The current AD value[2] = 0x%04X \r\n", ADC_ConvertedValue[2] ); 
		printf("\r\n The current AD value[3] = 0x%04X \r\n", ADC_ConvertedValue[3] ); 
		printf("\r\n 按键K3 电压值  %f V \r\n",ADC_ConvertedValueLocal[0]); 
	  printf("\r\n 按键K1 电压  %f V \r\n",ADC_ConvertedValueLocal[1]); 
	  printf("\r\n 内部参考电压1.2V是%f V \r\n",ADC_ConvertedValueLocal[2]); 
		 printf("\r\n 当前温度 = %f V \r\n",ADC_ConvertedValueLocal[3]); 
		Delay(0xffffee);  
		
	}
}
/*********************************************END OF FILE**********************/
