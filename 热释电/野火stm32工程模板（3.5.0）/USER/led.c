/******************** (C) COPYRIGHT 2012 WildFire Team ***************************
 * �ļ���  ��led.c
 * ����    ��led Ӧ�ú�����         
 * ʵ��ƽ̨��Ұ��STM32������
 * Ӳ�����ӣ�-----------------
 *          |   PC3 - LED1     |
 *          |   PC4 - LED2     |
 *          |   PC5 - LED3     |
 *           ----------------- 
 * ��汾  ��ST3.5.0
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "led.h"

/*
 * ��������LED_GPIO_Config
 * ����  ������LED�õ���I/O��
 * ����  ����
 * ���  ����
 */
 void Delay(__IO u32 nCount)
{
  for(; nCount != 0; nCount--);
} 

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE);
	
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_2;	
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;       
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOA, &GPIO_InitStructure);

//	  GPIO_SetBits(GPIOA, GPIO_Pin_6|GPIO_Pin_2 );	 // turn off all led
	
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_SetBits(GPIOC, GPIO_Pin_0 );	
}

u8 YOU_Config(GPIO_TypeDef* GPIOx,u16 GPIO_Pin)
{			

   	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 1) 
	  {	   
	 	 
	  	Delay(10);		
	   		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 1 )  
					{	 
					
						while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 1);
							return 1;	 
					}
			else
					return 0;
		}
	else
		return 0;
}


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
