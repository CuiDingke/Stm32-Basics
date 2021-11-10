#include "stm32f10x.h"
#include "lcd1602.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart1.h"
#include "misc.h"

uint8_t i,j,k=1,L,m,t;

int main(void)
{
	extern  u8 d[50];
  u8 f[200];
  extern u8 p;
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
			for(i=0;i<=16;i++)
			{
				 if(i==16) i=0;
				LCD1602_Write_Cmd(0x01);
			  	p=0;
				  t=i;
					for(j=0;j<2;j++)
					{
							for(m=0;m<=i;m++)
							{
								f[t--]=d[16-m];
							}
						LCD1602_Show_Str(0, k, f);
						LCD1602_Show_Str(i, k, d);
						delay_ms(100);
						if(KEY0==0) i=0;
						if(KEY1==0)
						{
							k=!k;
							LCD1602_Write_Cmd(0x01);
						}
					}
				  delay_ms(150);
					 
				 }
			
		}
	}
}
