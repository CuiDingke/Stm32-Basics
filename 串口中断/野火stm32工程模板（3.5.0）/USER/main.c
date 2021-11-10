/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ����3.5.0�汾���Ĺ���ģ�塣         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "led.h"
#include "usart1.h"
#include "misc.h"
#include "delay.h"
#include "sys.h"

extern uint16_t C,A;
uint8_t cc[]="��\r\n";
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
