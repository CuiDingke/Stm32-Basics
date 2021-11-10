#include "stm32f10x_it.h" 

int i,m;
extern u32 TimingDelay;
uint16_t capture1 = 0,capture2 = 0;
extern __IO uint16_t CCR1_Val,CCR2_Val;
void TIM4_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM4, TIM_IT_CC3) != RESET)
  {
    TIM_ClearITPendingBit(TIM4, TIM_IT_CC3 );
    capture1 = TIM_GetCapture3(TIM4);
		if(i==0)
		{
			i++;
	    TIM_SetCompare3(TIM4, capture1 + 20000-CCR1_Val );	
		}
		else
		{
			i=0;
	    TIM_SetCompare3(TIM4, capture1 + CCR1_Val );
		}
  }
	
	if (TIM_GetITStatus(TIM4, TIM_IT_CC4) != RESET)
  {
    TIM_ClearITPendingBit(TIM4, TIM_IT_CC4 );
    capture2 = TIM_GetCapture4(TIM4);
		if(m==0)
		{
			m++;
	    TIM_SetCompare4(TIM4, capture2 + CCR2_Val/2 );	
		}
		else
		{
			m=0;
	    TIM_SetCompare4(TIM4, capture2 + CCR2_Val/2 );
		}
  }
}
 
void SysTick_Handler(void)
{
}


