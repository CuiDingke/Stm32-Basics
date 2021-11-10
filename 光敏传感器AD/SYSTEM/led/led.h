#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"
#include "sys.h"
/* the macro definition to trigger the led on or off 
 * 1 - off
 - 0 - on
 */
#define ON  0
#define OFF 1

#define LED1(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_0);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_0)

#define LED2(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_1);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_1)

#define LED3(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_2);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_2)

#define		LCD1 PCout(1)			

#define		LCD2 PCout(2)	
					
void LED_GPIO_Config(void);

#endif /* __LED_H */
