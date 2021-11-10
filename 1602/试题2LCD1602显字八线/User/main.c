#include "stm32f10x.h"
#include "i2c.h"
#include "delay.h"
#include "sys.h"
#include "lcd1602.h"
#include "bsp_usart1.h"
#include "key.h" 
extern uint32_t temp;
uint8_t aa[]="xuebingchuan  ";
uint8_t i=0,j=0;
uint8_t bb[]="August 27th  ";

int main(void)
{
	delay_init();
	GPIO_Config();
	LCD1602_Init();
    i2c_init();
	  USART1_Config();
	  Key_GPIO_Config();
    while (1)
    {
			LCD1602_Show_Str(2, 1, "I love STM32");
			for(i=0;i<12;i++)
			{
	        IIC_WriteOneData(i,aa[i]);
	        delay_ms(10);	 	
			}		
			for(j=0;j<11;j++)
			{
				i=j+13;
	        IIC_WriteOneData(i,bb[j]);
	        delay_ms(10);	 	
			}		
		if(Key_Scan(GPIOA,GPIO_Pin_0)==0)
			{
				i=0;
				for(i=0;i<12;i++)
				{
			     IIC_ReadOneData(i);
			     printf("%c",temp);
					 LCD1602_Show_Str(2, 0, aa);
			  }
//				LCD1602_Show_Str(1, 0, aa);
//      	LCD1602_Show_Str(2, 1, "I love STM32");
				 printf("\r\n");
		  }
			if(Key_Scan(GPIOA,GPIO_Pin_1)==0)
			{
				j=0;
				for(j=0;j<11;j++)
				{
					 i=j+13;
			     IIC_ReadOneData(i);
			     printf("%c",temp);
					LCD1602_Show_Str(2, 0, bb);
			  }
				 printf("\r\n");
		  }
			
    }
}
