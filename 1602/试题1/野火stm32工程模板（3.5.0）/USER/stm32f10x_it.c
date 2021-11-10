#include "stm32f10x_it.h"
//#include "delay.h"
//#include "sys.h"

uint16_t a=0;

void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line1)==1)
		{
//			while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)==0);			
	a=!a;
			EXTI_ClearITPendingBit(EXTI_Line1);  
    } 
 
}
