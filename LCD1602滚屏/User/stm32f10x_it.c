#include "stm32f10x_it.h"
extern  uint8_t L;
u8 d[100];
u8 p=0,C;
void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==1)
	d[p++]=USART1->DR;
	C=USART1->DR;
	USART1->DR=C;
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	
}
