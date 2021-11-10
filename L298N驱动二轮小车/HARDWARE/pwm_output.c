#include "pwm_output.h"
uint32_t CCR_Val=700;
 void TIM2_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE); 
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
//	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
}

 void TIM2_Mode_Config(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

  TIM_TimeBaseStructure.TIM_Period = 999;       
  TIM_TimeBaseStructure.TIM_Prescaler = 17;	   
  TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;	
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	   
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
  TIM_OCInitStructure.TIM_Pulse = CCR_Val;	   
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  
  TIM_OC1Init(TIM2, &TIM_OCInitStructure);	 
  TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR_Val;	  
  TIM_OC2Init(TIM2, &TIM_OCInitStructure);	
  TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
  TIM_ARRPreloadConfig(TIM2, ENABLE);			
  TIM_Cmd(TIM2, ENABLE);                  
}


void TIM2_PWM_Init(void)
{
	TIM2_GPIO_Config();
	TIM2_Mode_Config();	
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
