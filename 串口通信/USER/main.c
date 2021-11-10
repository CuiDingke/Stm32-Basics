#include "stm32f10x.h"
#include "usart1.h"
#include "misc.h"
#include "delay.h"
#include "led.h"
extern u8 C;
 int main(void)
 {	
	 u8 aa[]="abfhuidsh";
	 u8 i;
   USART1_Config();
	 NVIC_Configuration();
   delay_init();
	 LED_GPIO_Config();
  while(1)
	{
	    if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==0)
			{
			 delay_ms(200);
			 if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==0)
			 {
				 if(i>=9)  i=0;			
			   USART1->DR=aa[0];	
				 i=i+1;
			 }
			}
			 if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0)
			{
			 delay_ms(200);
			 if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0)
			 {
				 if(i>=9)  i=0;			
			   USART1->DR=aa[1];	
				 i=i+1;
			 }
			}
			
		  if (C==97)
			{
			   GPIO_ResetBits(GPIOE,GPIO_Pin_5);
				 delay_ms(500);
			}
			if(C==98)
			{
			    GPIO_SetBits(GPIOE,GPIO_Pin_5);
				  delay_ms(500);
			}
			
			
	}
 }
