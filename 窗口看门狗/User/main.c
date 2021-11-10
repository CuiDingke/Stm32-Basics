#include "stm32f10x.h"
#include "wdg.h"
#include "led.h"
#include "sys.h"
#include "delay.h"
extern uint8_t a;
int main(void)
{
   LED_GPIO_Config();
	 delay_init();
	 
	 LED1(1);
	 delay_ms(100);
	 WWDG_Init(0X7F,0X5F,WWDG_Prescaler_8);
    while (1)
    {
			LED1(1);
    }
}
