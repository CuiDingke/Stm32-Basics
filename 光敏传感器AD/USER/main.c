#include "stm32f10x.h"
#include "adc.h"
#include "usart1.h"
#include "misc.h"
#include "delay.h"
 int main(void)
 {	
	u16 temp,i,b;
	delay_init();
	USART1_Config();
  ADC1_Config();
  while(1)
	{
		  for(i=0;i<10;i++)
	    {
				temp=ADC3->DR;
				b=b+temp;
			}
			b/=10;
			if(b>4000)b=4000;
				b=(100-(b/40));
				printf ("%d\r\n",b);
				delay_ms(500);
	}
 }
