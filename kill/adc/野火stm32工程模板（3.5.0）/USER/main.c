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
 extern uint16_t ADCConvertedValue;
 float ADC_ConvertedValue;
/* 
 * ��������main
 * ����  : ������
 * ����  ����
 * ���  : ��
 */
int main(void)
{
	ADC_config();
	
  	  while(1)
			{
			ADC_ConvertedValue=ADCConvertedValue*3.3/4096;
			printf("c1 :%2f v",ADC_ConvertedValue);
			
			
			
			
			}
	  // add your code here ^_^��
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


