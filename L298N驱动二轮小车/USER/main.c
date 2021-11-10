#include "stm32f10x.h"
#include "led.h"
#include "pwm_output.h"
#include "jzkey.h"
#include "delay.h"
#include "sys.h"
#include "usart1.h"
#include "misc.h"
 extern uint32_t CCR_Val;
 int main(void)
 {	
	 u8 a;
	 delay_init();
   LED_GPIO_Config();
	 TIM2_GPIO_Config();
	 TIM2_Mode_Config();
	 key_Init();
	 GPIO_Key_Init();
	 USART1_Config();
	 
  while(1)
	{
		 a = key_Init();
		 printf ("%d\r\n",a);
		 if(a==1) CCR_Val=CCR_Val+50;
		 if(a==2) CCR_Val=CCR_Val-50;
		 printf ("%d\r\n",CCR_Val);
		 TIM2_Mode_Config();
		 if(a==3)
		 {  
		    INA1;
			  INB0;
			  INC1;
			  IND0;
		 }
		 if(a==4)
		 {  
		    INA1;
			  INB0;
			  INC0;
			  IND1;
		 }
		 if(a==5)
		 {  
		    INA1;
			  INB0;
			  INC1;
			  IND1;
		 }
		 if(a==6)
		 {  
		    INA0;
			  INB1;
			  INC1;
			  IND0;
		 }
		 if(a==7)
		 {  
		    INA1;
			  INB1;
			  INC1;
			  IND0;
		 }
		 if(a==8)
		 {  
		    INA0;
			  INB1;
			  INC0;
			  IND1;
		 }
		 if(a==9)
		 {  
		    INA0;
			  INB0;
			  INC0;
			  IND0;
		 }
	}
 }
