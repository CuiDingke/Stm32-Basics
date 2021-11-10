#include "stm32f10x.h"
#include "usart1.h"
#include "misc.h"
#include "esp8266.h"
#include  "led.h"
#include "usart2.h"
#include "delay.h"
#include "key.h"

int main(void)
{
	delay_init();
	USART1_Config();
	USART2_Config();
	LED_GPIO_Config();
	Esp8266_Config();
	while (1)
	{
		if(!(ESP8266_CheckStatus(30)))
		{
			GPIO_SetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
//			GPIO_ResetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
		}
		else
		{
			GPIO_ResetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
		}
	}
}
