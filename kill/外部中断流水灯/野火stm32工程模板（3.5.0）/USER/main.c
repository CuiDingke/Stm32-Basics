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
#include "exti.h"
#include "led.h"
void Delay(__IO u32 nCount);
uint8_t a=0;

/* 
 * 函数名：main
 * 描述  : 主函数
 * 输入  ：无
 * 输出  : 无
 */
 
int main(void)
{ 
	LED_GPIO_Config();
	EXTI_PB0_Config();
  	  while(1)
	{

//		GPIOC->ODR^=1<<3;
//		Delay(0X0FFFFF);
		GPIOC->ODR^=1<<0;	
		Delay(0X0FFFFF);	
		GPIOC->ODR^=1<<1;	
		Delay(0X0FFFFF);
		if(a==1)
		{
		GPIO_ResetBits( GPIOC, GPIO_Pin_3);
		Delay(0X0FFFFF);
		GPIO_SetBits( GPIOC, GPIO_Pin_3);
			a=0;
		}	
		if(a==2)
		{
		GPIO_ResetBits( GPIOC, GPIO_Pin_2);
		Delay(0X0FFFFF);
		GPIO_SetBits( GPIOC, GPIO_Pin_2);
			a=0;
		}	
	
	}
	
}
void Delay(__IO u32 nCount)
{for(; nCount != 0; nCount--);}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


