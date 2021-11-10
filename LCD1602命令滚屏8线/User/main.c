#include "stm32f10x.h"
#include "lcd1602.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart1.h"
#include "misc.h"

uint8_t i,j,k;

int main(void)
{
	extern  u8 d[50];
	delay_init();
  GPIO_Config();
	LCD1602_Init();
	USART1_Config();
	KEY_Init();
	NVIC_Configuration();
    while (1)
    {
    if(KEY0 == 0)
		{
			j=0;
		  for(i=0;i<=100;i++)	
			{
				if(i==100)i=0;
		    LCD1602_Write_Cmd(0x1c);
		    LCD1602_Show_Str(0, k, d);
				delay_ms(500);
			if(KEY2 == 0) 
			{
				k=!k;
				LCD1602_Show_Str(0, !k, "                                                       ");
			}
			if(KEY1 == 0) i=101;
			}
		}
		
		if(KEY1 == 0)
		{
			i=0;
		  for(j=0;j<=100;j++)	
			{
				if(j==100)j=0;
				LCD1602_Write_Cmd(0x18);
				LCD1602_Show_Str(0, k, d);
				delay_ms(500);
			if(KEY2 == 0) 
			{
				k=!k;
				LCD1602_Show_Str(0, !k, "                                                            ");
			}
			if(KEY0 == 0) j=101;	
			}		  
		}
			
	
	}
}
