
#include "stm32f10x.h"
#include "usart1.h"
#include "adc.h"
#include <stdio.h>
// ADC1转换的电压值通过MDA方式传到SRAM
uint16_t temp;
float a;
uint16_t aa[2];
float a,b,c,d;
// 软件延时
void Delay(__IO uint32_t nCount);

int main(void)
{	
	
	USART1_Config();
	ADC1_GPIO_Config();
	ADC1_Mode_Config();
	while (1)
	{

		
	temp=ADC1->DR;//单通道采集
	a=temp*3.3/4096;
	printf("%.2f \r\n",a);	
  Delay(0xffee);

//   aa[0]=ADC1->DR;
//		a=aa[0];
//		b=a*3.3/4096;
//		printf("C1,%.2f \r\n",a);
//		
//		 aa[1]=ADC1->DR;
//		c=aa[1];
//		d=c*3.3/4096;
//		printf("C2,%.2f \r\n",d);
		
		
	
}
	}
	
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
