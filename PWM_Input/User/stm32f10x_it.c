#include "stm32f10x_it.h"
__IO uint16_t IC2Value = 0;
__IO uint16_t DutyCycle = 0;
__IO uint32_t Frequency = 0;

void TIM3_IRQHandler(void)
{ 
  TIM_ClearITPendingBit(TIM3, TIM_IT_CC2);
  IC2Value = TIM_GetCapture2(TIM3);
  if (IC2Value != 0)
  {
    DutyCycle = (TIM_GetCapture1(TIM3) * 100) / IC2Value;
    Frequency = SystemCoreClock / IC2Value;
  }
  else
  {
    DutyCycle = 0;
    Frequency = 0;
  }
}
