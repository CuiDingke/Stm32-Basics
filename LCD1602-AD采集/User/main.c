#include "stm32f10x.h"
#include "lcd1602.h"
#include "delay.h"
#include "sys.h"
#include "bsp_adc.h"
#include "stdio.h"
extern __IO uint16_t ADC_ConvertedValue[1];
float ADC_Converted[1],Information;
char  A[100];
int main(void)
{
//	  u8 d[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	  ADC1_Init();
	  ADC1_Cal();
	  delay_init();
    GPIO_Config();
	  LCD1602_Init();
//	  LCD1602_Show_Str(4, 1, d);
//	  LCD1602_Show_Str(0, 0, "I love SunXiuXiu");
    while (1)
    {
			ADC_Converted[0]=ADC_ConvertedValue[0]*3.3/4069;
			Information=ADC_Converted[0];
			sprintf (A,"ADC   :%.2fV",Information);
  	  LCD1602_Show_Str(1, 1, A);
    }
}
