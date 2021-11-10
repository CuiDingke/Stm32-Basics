/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：用3.5.0版本建的工程模板。         
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "adc.h"
#include "bsp_usart1.h"
#include "stdio.h"
#include "delay.h"

/* 
 * 函数名：main
 * 描述  : 主函数
 * 输入  ：无
 * 输出  : 无
 */

extern uint16_t ADCConvertedValue[2];

float ADC_ConvertedValue[2];



int main(void)
{	   

		  delay_init();
      ADC_Config();
      USART1_Config();
  	  while(1)
	  {
	  ADC_ConvertedValue[0]=ADCConvertedValue[0]*3.3/4096;
	  printf("C1:%.2f V \r\n",ADC_ConvertedValue[0]);

	  ADC_ConvertedValue[1]=ADCConvertedValue[1]*3.3/4096;
	  printf("C2:%.2f V \r\n",ADC_ConvertedValue[1]);
	  	delay_ms(100);
	  
	  }

}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


