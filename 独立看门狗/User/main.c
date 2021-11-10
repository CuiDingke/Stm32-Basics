#include "stm32f10x.h"
#include  "LED.h"
#include "delay.h"
#include "GPIO_Bit.h"
#include "iwdg.h"
#include "key.h" 
int main(void)
{
	 delay_init();
	 Key_GPIO_Config();
   LED_GPIO_Config();
	 delay_ms(150);
	 PCO1=0;
	 IWDG_Init(4,625);
    while (1)
    {
			if(Key_Scan(GPIOA,GPIO_Pin_1)==0)
			{
			
			IWDG_Feed();
			}
    }
}
