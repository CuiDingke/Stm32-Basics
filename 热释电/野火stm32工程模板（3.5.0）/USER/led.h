#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"


u8 YOU_Config(GPIO_TypeDef* GPIOx,u16 GPIO_Pin);

void LED_GPIO_Config(void);

#endif 
