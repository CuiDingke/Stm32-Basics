#include "stm32f10x.h"
#include "lcd.h"
#include "tim.h"
#include "stdio.h"
u32 TimingDelay = 0;


extern uint16_t IC2Value;
extern uint16_t DutyCycle;
extern uint32_t Frequency;

char A[50];

void Delay_Ms(u32 nTime);


int main(void)
{
	SysTick_Config(SystemCoreClock/1000);

	Delay_Ms(200);
	
	STM3210B_LCD_Init(); 
	tim2_init(71);
	tim3_init(2);

	LCD_Clear(Blue);
	LCD_SetBackColor(Blue);
	LCD_SetTextColor(White);
	 
	sprintf(A,"    %d ",Frequency);
	LCD_DisplayStringLine(Line4,(unsigned char *)A);	
	sprintf(A,"    %d ",DutyCycle);
	LCD_DisplayStringLine(Line5,(unsigned char *)A);
		
	tim2_init(35);
	tim3_init(1);
  sprintf(A,"    %d ",Frequency);
	LCD_DisplayStringLine(Line6,(unsigned char *)A);	
  sprintf(A,"    %d ",DutyCycle);
	LCD_DisplayStringLine(Line7,(unsigned char *)A);
	
	while(1)
	{
	

	
	}
}

//
void Delay_Ms(u32 nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);	
}
