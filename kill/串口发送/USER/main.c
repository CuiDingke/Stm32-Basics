#include "stm32f10x.h"
#include "usart1.h"
#include "misc.h"
#include "delay.h"
#include "led.h"
extern u8 C,b;
int main(void)
 {	
//	 u8 aa[]="abfhuidsh\n";
//	 u8 i=1;
   USART1_Config();
   NVIC_Configuration();
   delay_init();
	 LED_GPIO_Config();
  while(1)
	{
		  GPIO_ResetBits(GPIOC,GPIO_Pin_3);  
      delay_ms(800);                     
      GPIO_SetBits(GPIOC,GPIO_Pin_3); 
	  
	    GPIO_ResetBits(GPIOC,GPIO_Pin_2);  
      delay_ms(800);                      
      GPIO_SetBits(GPIOC,GPIO_Pin_2);  
	  
	    GPIO_ResetBits(GPIOC,GPIO_Pin_1); 
      delay_ms(800);                     
      GPIO_SetBits(GPIOC,GPIO_Pin_1);  

	}
}