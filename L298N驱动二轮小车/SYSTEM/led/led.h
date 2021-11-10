#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"
#include "sys.h"

#define		ENA1 PAO0=1
#define		ENA0 PAO0=0
#define		ENB1 PAO1=1
#define		ENB0 PAO1=0
#define		INA1 PAO2=1
#define		INA0 PAO2=0
#define		INB1 PAO3=1
#define		INB0 PAO3=0
#define		INC1 PAO4=1
#define		INC0 PAO4=0
#define		IND1 PAO5=1
#define		IND0 PAO5=0  
#define		DATE( x) GPIO_Write(GPIOA,x)		
void LED_GPIO_Config(void);

#endif 
