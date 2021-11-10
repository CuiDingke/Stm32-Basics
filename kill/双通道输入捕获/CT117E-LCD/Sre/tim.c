#include "tim.h"




__IO uint16_t IC2Value = 0;
__IO uint16_t DutyCycle = 0;
__IO uint32_t Frequency = 0;
uint8_t i=0;


void tim2_init(uint16_t num)
{

  GPIO_InitTypeDef GPIO_InitStructure;

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);


  TIM_TimeBaseStructure.TIM_Period =1000;
  TIM_TimeBaseStructure.TIM_Prescaler =num;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);


  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;

  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 500;

  TIM_OC2Init(TIM2, &TIM_OCInitStructure);

  TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);



  TIM_ARRPreloadConfig(TIM2, ENABLE);

  TIM_Cmd(TIM2, ENABLE);




}

void tim3_init(uint16_t channela)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	TIM_ICInitTypeDef  TIM_ICInitStructure; 
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	

  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
  
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  TIM_TimeBaseStructure.TIM_Period =1000;
  TIM_TimeBaseStructure.TIM_Prescaler =71;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
if(channela==2)
{
	i=2;
  TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
  TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
  TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
  TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
  TIM_ICInitStructure.TIM_ICFilter = 0x0;

  TIM_PWMIConfig(TIM3, &TIM_ICInitStructure);

  TIM_SelectInputTrigger(TIM3, TIM_TS_TI2FP2);

  TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);

  TIM_SelectMasterSlaveMode(TIM3, TIM_MasterSlaveMode_Enable);

  TIM_Cmd(TIM3, ENABLE);

  TIM_ITConfig(TIM3, TIM_IT_CC2, ENABLE);

}


if(channela==1)
{
	i=1;
  TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
  TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
  TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
  TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
  TIM_ICInitStructure.TIM_ICFilter = 0x0;

  TIM_PWMIConfig(TIM3, &TIM_ICInitStructure);

  TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);

  TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);

  TIM_SelectMasterSlaveMode(TIM3, TIM_MasterSlaveMode_Enable);

  TIM_Cmd(TIM3, ENABLE);

  TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);

}

}

void TIM3_IRQHandler(void)
{
if(i==2)
{
  TIM_ClearITPendingBit(TIM3, TIM_IT_CC2);

  /* Get the Input Capture value */
  IC2Value = TIM_GetCapture2(TIM3);

  if (IC2Value != 0)
  {
    /* Duty cycle computation */
    DutyCycle = (TIM_GetCapture1(TIM3) * 100) / IC2Value;

    /* Frequency computation */
    Frequency = 72000000/ IC2Value;
  }
  else
  {
    DutyCycle = 0;
    Frequency = 0;
  }
}
if(i==1)
{
  TIM_ClearITPendingBit(TIM3, TIM_IT_CC1);

  /* Get the Input Capture value */
  IC2Value = TIM_GetCapture1(TIM3);

  if (IC2Value != 0)
  {
    /* Duty cycle computation */
    DutyCycle =  ( TIM_GetCapture2(TIM3)* 100) /IC2Value;

    /* Frequency computation */
    Frequency = 72000000/ IC2Value;
  }
  else
  {
    DutyCycle = 0;
    Frequency = 0;
  }
}

}

















