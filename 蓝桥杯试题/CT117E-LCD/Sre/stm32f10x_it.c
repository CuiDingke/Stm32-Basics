#include "stm32f10x_it.h"
#include "usart1.h"
extern u32 TimingDelay;
uint8_t p,X,q;
extern uint8_t k,G;
void USART2_IRQHandler(void)
{
	if(USART_GetITStatus(USART2,USART_IT_RXNE)==1)
	{USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	  X=USART2->DR;
		USART2->DR=X;
		if(X==67)	{p=1;k=0;}
		if(X==83) {q=1;G=0;}
		
	}
}

void SysTick_Handler(void)
{
	TimingDelay--;
}

