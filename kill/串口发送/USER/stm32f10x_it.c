#include "stm32f10x_it.h" 
u8 C,b;
void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==1)
	{
	C=USART1->DR;
 USART1->DR=C;
	GPIOC->ODR^=1<<0;
	}
}

