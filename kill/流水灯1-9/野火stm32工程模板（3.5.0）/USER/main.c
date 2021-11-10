#include "stm32f10x.h"
#include "led.h"

 void delay(uint16_t j);
 
int main(void)
{
	    LED_GPIO_Config();
  	  while(1)
			{
      GPIO_ResetBits(GPIOC,GPIO_Pin_3); 
      delay(1000);                     
      GPIO_SetBits(GPIOC,GPIO_Pin_3); 
	  
	    GPIO_ResetBits(GPIOC,GPIO_Pin_1); 
      delay(1000);                     
      GPIO_SetBits(GPIOC,GPIO_Pin_1);  
	  
	    GPIO_ResetBits(GPIOC,GPIO_Pin_2); 
      delay(1000);                     
      GPIO_SetBits(GPIOC,GPIO_Pin_2); 
			
			}
}

void delay(uint16_t j)
{
uint16_t m,n;
for(n=0;n<j;n++)
	{
	for(m=0;m<4000;m++);
	}
}


