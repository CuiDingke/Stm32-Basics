#include  "led.h"

void LED_GPIO_Config(void)
{ GPIO_InitTypeDef   GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	PCO0=1; PCO1=1;PCO2=1;
	//GPIO_SetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
 }
