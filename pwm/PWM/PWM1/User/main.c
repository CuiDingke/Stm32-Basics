
#include "stm32f10x.h"
#include "pwm_output.h"

int main(void)
{

//TIM3_PWM_Init();
TIM3_GPIO_Config();
TIM3_Mode_Config();	
	while (1)
	{}
}


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
