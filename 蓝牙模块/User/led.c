#include "LED.h"

void LED_GPIO_Config(void)
{ 
	GPIO_InitTypeDef   GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
//	PCO0=1; PCO1=1;PCO2=1;
	GPIO_SetBits(GPIOE,GPIO_Pin_1);
 }
