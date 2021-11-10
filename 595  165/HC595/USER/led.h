#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"

/* the macro definition to trigger the led on or off 
 * 1 - off
 - 0 - on
 */
#define ON  0
#define OFF 1

#define CS1 0x01
#define CS2 0x02
#define CS3 0x04
#define CS4 0x08
#define CS5 0x10
#define CS6 0x20
#define CS7 0x40
#define CS8 0x80


#define S_CLK(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_0);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_0)

#define MOSIO(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_1);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_1)

#define R_CLK(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_2);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_2)
					
					
					
#define CLK_IN_1(a)	if (a)	\
					GPIO_SetBits(GPIOB,GPIO_Pin_9);\
					else		\
					GPIO_ResetBits(GPIOB,GPIO_Pin_9)              //  1

#define MOSIO_DATA_1(a)	if (a)	\
					GPIO_SetBits(GPIOB,GPIO_Pin_5);\
					else		\
					GPIO_ResetBits(GPIOB,GPIO_Pin_5)

#define CLK_OUT_1(a)	if (a)	\
					GPIO_SetBits(GPIOB,GPIO_Pin_8);\
					else		\
					GPIO_ResetBits(GPIOB,GPIO_Pin_8)					

					
#define CLK_IN_2(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_12);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_12)              //  1

#define MOSIO_DATA_2(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_10);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_10)

#define CLK_OUT_2(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_11);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_11)				


#define CLK_IN_3(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_15);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_15)              //  1

#define MOSIO_DATA_3(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_13);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_13)

#define CLK_OUT_3(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_14);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_14)		
					
					
					

#define CLK_IN_4(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_6);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_6)              //  1

#define MOSIO_DATA_4(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_8);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_8)

#define CLK_OUT_4(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_7);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_7)								

void LED_GPIO_Config(void);

#endif /* __LED_H */
