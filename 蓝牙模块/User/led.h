#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"
#include "sys.h"
#define led1 PEout(1) 
void LED_GPIO_Config(void);

#endif 
