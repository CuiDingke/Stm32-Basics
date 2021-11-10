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
#include "led.h"

/* 
 * 函数名：main
 * 描述  : 主函数
 * 输入  ：无
 * 输出  : 无
 */
int main(void)
{
	LED_GPIO_Config();
//	GPIOC->ODR &=~(1<<0);
  	  while(1)
	  {
		if(YOU_Config( GPIOA,GPIO_Pin_6)==1)
		{
		     GPIOC->ODR |=(1<<0);
		}
		else
		GPIOC->ODR &=~(1<<0);
		
		
		}
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


