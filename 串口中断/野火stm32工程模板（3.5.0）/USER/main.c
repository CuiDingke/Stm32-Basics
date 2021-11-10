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
#include "usart1.h"
#include "misc.h"
#include "delay.h"
#include "sys.h"

extern uint16_t C,A;
uint8_t cc[]="孙\r\n";
uint8_t i;

int main(void)
{
	LED_GPIO_Config();
	USART1_Config();
	NVIC_Configuration();
delay_init();
  	  while(1)
			{
			   if(A==49)
			   {
			       for(i=0;i<sizeof(cc)-1;i++)
			      {
			         USART1->DR=cc[i];
							delay_ms(100);
//						printf("\r\n");
			      }	
			  }
			   if(A==50)
			   {
			GPIOC->ODR^=1<<3;
					 	delay_ms(1000);
			
			
			    }
			}
	 
}
