#include "stm32f10x.h"
#include "jzkey.h"
#include "delay.h"
#include "sys.h"
#include "usart1.h"
#include "misc.h"
 int main(void)
 {	
	 u8 a=0;
	 delay_init();
	 GPIO_Key_Init();
   key_Init();
	 USART1_Config();
  while(1)
	{
	  a = key_Init();
//		if(a) printf ("  %d  ",a);
			
	  printf ("  %d  ",a);
		delay_ms(50);
	}
 }
