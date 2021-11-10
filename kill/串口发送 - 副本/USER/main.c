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
   delay_init();
  while(1)
	{
	}
}