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
 extern uint16_t ADCConvertedValue;
 float ADC_ConvertedValue;
/* 
 * 函数名：main
 * 描述  : 主函数
 * 输入  ：无
 * 输出  : 无
 */
int main(void)
{
	ADC_config();
	
  	  while(1)
			{
			ADC_ConvertedValue=ADCConvertedValue*3.3/4096;
			printf("c1 :%2f v",ADC_ConvertedValue);
			
			
			
			
			}
	  // add your code here ^_^。
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


