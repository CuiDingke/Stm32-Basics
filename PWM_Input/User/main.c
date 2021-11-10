#include "stm32f10x.h"
#include  "in_pwm.h"
int main(void)
{
  NVIC_Configuration();
  GPIO_Configuration();
  In_Pwm_Tim3();
  while (1);
}
