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

/* 
 * ��������main
 * ����  : ������
 * ����  ����
 * ���  : ��
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


