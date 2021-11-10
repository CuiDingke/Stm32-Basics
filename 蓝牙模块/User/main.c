#include "stm32f10x.h"
#include "usart1.h"
#include "misc.h"
#include "LED.h"
#include "delay.h"
#include "sys.h"
extern uint8_t A;
int main(void)
{	
	LED_GPIO_Config();
  USART1_Config();
	NVIC_Configuration();
	delay_init();
    while (1)
    {
			
			if(A==97)
			{
				led1 = 1 ;
//GPIOE->ODR^=1<<5;
//				delay_ms(100);
			}
			if(A==98)
			{
				led1 = 0 ;
//GPIOE->ODR^=1<<5;
//				delay_ms(100);
			}
    }
}
