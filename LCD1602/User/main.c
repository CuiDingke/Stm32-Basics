#include "stm32f10x.h"
#include "lcd1602.h"
#include "delay.h"
#include "sys.h"
int main(void)
{
	u8 d[] = "ATOM@ALIENTEK";
	delay_init();
   GPIO_Config();
	LCD1602_Init();
	LCD1602_Show_Str(1, 0, d);
 	LCD1602_Show_Str(2, 1, "I love STM32");
    while (1)
    {
    }
}
