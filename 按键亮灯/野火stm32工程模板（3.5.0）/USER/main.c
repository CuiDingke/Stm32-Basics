/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ����3.5.0�汾���Ĺ���ģ�塣         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "led.h"
uint8_t i=0;
void Delay(__IO u32 j);
int main(void)
{
	LED_GPIO_Config();
  	  while(1)
			{
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1) == 0)
		{ Delay(0X0FFFF);
     if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1) == 0)
     {
    if(i<16) i++;
     else i=1;
     } 
	 }

     if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0)
		 {Delay(0X0FFFF);
     if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0)
     {
    if(i>0) i--;
     else i=15;
     } 
	 }
     if(i==5)
     {
    GPIO_ResetBits(GPIOC,GPIO_Pin_1);
    Delay(0X0FFFFF);
     GPIO_SetBits(GPIOC,GPIO_Pin_1);
			     Delay(0X0FFFFF);
    }
		 
		if(i==10)
     {
    GPIO_ResetBits(GPIOC,GPIO_Pin_2);
     Delay(0X0FFFFF);
     GPIO_SetBits(GPIOC,GPIO_Pin_2);
			     Delay(0X0FFFFF);
    }
		 
		if(i==15)
     {
    GPIO_ResetBits(GPIOC,GPIO_Pin_3);
     Delay(0X0FFFFF);
     GPIO_SetBits(GPIOC,GPIO_Pin_3);
			     Delay(0X0FFFFF);
    }
    }
}

void Delay(__IO u32 j)
{
for(;j!=0;j--);
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


