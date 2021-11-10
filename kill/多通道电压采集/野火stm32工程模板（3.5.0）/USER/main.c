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
#include "adc.h"
#include "bsp_usart1.h"
#include "stdio.h"
#include "delay.h"

/* 
 * ��������main
 * ����  : ������
 * ����  ����
 * ���  : ��
 */

extern uint16_t ADCConvertedValue[2];

float ADC_ConvertedValue[2];



int main(void)
{	   

		  delay_init();
      ADC_Config();
      USART1_Config();
  	  while(1)
	  {
	  ADC_ConvertedValue[0]=ADCConvertedValue[0]*3.3/4096;
	  printf("C1:%.2f V \r\n",ADC_ConvertedValue[0]);

	  ADC_ConvertedValue[1]=ADCConvertedValue[1]*3.3/4096;
	  printf("C2:%.2f V \r\n",ADC_ConvertedValue[1]);
	  	delay_ms(100);
	  
	  }

}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


