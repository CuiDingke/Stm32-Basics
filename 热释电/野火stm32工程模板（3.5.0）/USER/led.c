/******************** (C) COPYRIGHT 2012 WildFire Team ***************************
 * 文件名  ：led.c
 * 描述    ：led 应用函数库         
 * 实验平台：野火STM32开发板
 * 硬件连接：-----------------
 *          |   PC3 - LED1     |
 *          |   PC4 - LED2     |
 *          |   PC5 - LED3     |
 *           ----------------- 
 * 库版本  ：ST3.5.0
 * 作者    ：wildfire team 
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/
#include "led.h"

/*
 * 函数名：LED_GPIO_Config
 * 描述  ：配置LED用到的I/O口
 * 输入  ：无
 * 输出  ：无
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
