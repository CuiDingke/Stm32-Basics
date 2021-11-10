#include "jzkey.h"
#include "delay.h"
#include "sys.h"
void GPIO_Key_Init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(GPIOC,&GPIO_InitStructure);
	 GPIO_SetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
	 
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(GPIOC,&GPIO_InitStructure);
   GPIO_ResetBits(GPIOC,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);

}

u8 key_Init (void)
{
	 u8 key_num;
	 GPIO_SetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
	 GPIO_ResetBits(GPIOC,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
   if((GPIO_ReadInputData(GPIOC)&0xff)!=0x0f)
	 {
	    delay_ms(100);
		 if((GPIO_ReadInputData(GPIOC)&0xff)!=0x0f)
		 {
		    GPIO_SetBits(GPIOC,GPIO_Pin_0);
			  GPIO_ResetBits(GPIOC,GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
		    switch(GPIO_ReadInputData(GPIOC)&0xff)
				{
					 case 0x11:key_num = 1 ;break;
					 case 0x21:key_num = 2 ;break;
					 case 0x41:key_num = 3 ;break;
				   case 0x81:key_num = 4 ;break;
				}	
				
				GPIO_SetBits(GPIOC,GPIO_Pin_1);
			  GPIO_ResetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3);
		    switch(GPIO_ReadInputData(GPIOC)&0xff)
				{
					 case 0x12:key_num = 5 ;break;
					 case 0x22:key_num = 6 ;break;
					 case 0x42:key_num = 7 ;break;
				   case 0x82:key_num = 8 ;break;
				}				
				
				GPIO_SetBits(GPIOC,GPIO_Pin_2);
			  GPIO_ResetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_3);
		    switch(GPIO_ReadInputData(GPIOC)&0xff)
				{
					 case 0x14:key_num = 9 ;break;
					 case 0x24:key_num = 10 ;break;
					 case 0x44:key_num = 11 ;break;
				   case 0x84:key_num = 12 ;break;
				}		
				
				GPIO_SetBits(GPIOC,GPIO_Pin_3);
			  GPIO_ResetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
		    switch(GPIO_ReadInputData(GPIOC)&0xff)
				{
					 case 0x18:key_num = 13 ;break;
					 case 0x28:key_num = 14 ;break;
					 case 0x48:key_num = 15 ;break;
				   case 0x88:key_num = 16 ;break;
				}			
				
				GPIO_SetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
				GPIO_ResetBits(GPIOC,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
			  delay_ms(40);
		 return key_num;				
		 } 
	 } 
	 return 0;
}



