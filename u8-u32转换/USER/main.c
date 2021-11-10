#include "stm32f10x.h"
#include "usart1.h"
#include "misc.h"
#include "sys.h"
 int main(void)
 {	
	 /*uint8_t date[4]={0x00,0x01,0x02,0x03};
	 uint32_t DATE;*/
	 uint8_t date[4];
	 uint32_t DATE=66051;
	 int i;
   USART1_Config();
	 NVIC_Configuration();
		/*for(i=0;i<4;i++)
		{
			DATE=DATE<<8;
			DATE|=date[i];
		  printf ("%d  ,%d\r\n",DATE,i);
		}
		printf ("%d\n",DATE);*/
	 for(i=0;i<4;i++)
	 {
		 date[i]=DATE&0xff;
		 printf ("%d ,%d\r\n",DATE,i);
		 DATE=DATE>>8;
	 }
	 for(i=0;i<4;i++)
	 {
		printf("%d",date[i]);
	 }
	 
 }
