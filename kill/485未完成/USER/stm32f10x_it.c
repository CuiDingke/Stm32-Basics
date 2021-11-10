#include "stm32f10x_it.h" 
u8 C;
void USART2_IRQHandler(void)
{
	if(USART_GetITStatus(USART2,USART_IT_RXNE)==1)
	{
	C=USART2->DR;
	USART2->DR=C;
	}
}

