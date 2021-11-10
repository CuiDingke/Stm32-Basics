/******************** (C) COPYRIGHT 2011 Ұ��Ƕ��ʽ���������� ********************
 * �ļ���  ��main.c
 * ����    �����ص�LED1��LED2��LED3���Թ̶���Ƶ��������˸��Ƶ�ʿɵ�����         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.0.0
 *
 * ����    ��fire  QQ: 313303034 
 * ����    ��firestm32.blog.chinaunix.net
**********************************************************************************/	

#include "stm32f10x.h"
#include "led.h"

u16 k;

void Delay(__IO u32 nCount);
void HC595SendData(unsigned char SendVal);
void HC595SendData_1(unsigned char SendVal_1);
void HC595SendData_2(unsigned char SendVal_2);
void HC595SendData_3(unsigned char SendVal_3);
void HC595SendData_4(unsigned char SendVal_4);

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{
	/* ����ϵͳʱ��Ϊ72M */      
  SystemInit();	
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();
	
  while (1)
  { 	
//		HC595SendData(0xff);
//		Delay(0xffffff);
//		HC595SendData(0x00);
//		Delay(0xffffff);
//		HC595SendData(CS1);
//		Delay(0xfffff);
//		HC595SendData(CS2);
//		Delay(0xfffff);
//		HC595SendData(CS3);
//		Delay(0xfffff);
//		HC595SendData(CS4);
//		Delay(0xfffff);
//		HC595SendData(CS5);
//		Delay(0xfffff);
//		HC595SendData(CS6);
//		Delay(0xfffff);
//		HC595SendData(CS7);
//		Delay(0xfffff);
//		HC595SendData(CS8);
//		Delay(0xfffff);
//		HC595SendData(0xfe);
//		Delay(0xfffff);
//		HC595SendData(0xfd);
//		Delay(0xfffff);
//		HC595SendData(0xfb);
//		Delay(0xfffff);
//		HC595SendData(0xf7);
//		Delay(0xfffff);
//		HC595SendData(0xef);
//		Delay(0xfffff);
//		HC595SendData(0xdf);
//		Delay(0xfffff);
//		HC595SendData(0xbf);
//		Delay(0xfffff);
//		HC595SendData(0x7f);
//		Delay(0xfffff);
//		HC595SendData_1(0xff);
//		Delay(0x3fffff);
//		HC595SendData_1(0x00);
//		Delay(0x3fffff);


		HC595SendData_1(0xff);                    // 1  OK!!!
		Delay(0x3fffff);
		HC595SendData_1(0x00);
		Delay(0x3fffff);
		HC595SendData_1(CS1);
		Delay(0x3fffff);
		HC595SendData_1(CS2);
		Delay(0x3fffff);
		HC595SendData_1(CS3);
		Delay(0x3fffff);
		HC595SendData_1(CS4);
		Delay(0x3fffff);
		HC595SendData_1(CS5);
		Delay(0x3fffff);
		HC595SendData_1(CS6);
		Delay(0x3fffff);
		HC595SendData_1(CS7);
		Delay(0x3fffff);
		HC595SendData_1(CS8);
		Delay(0x3fffff);
		
		
				HC595SendData_2(0xff);                    // 2
		HC595SendData_2(0x00);
		Delay(0x3fffff);
		HC595SendData_2(CS1);
		Delay(0x3fffff);
		HC595SendData_2(CS2);
		Delay(0x3fffff);
		HC595SendData_2(CS3);
		Delay(0x3fffff);
		HC595SendData_2(CS4);
		Delay(0x3fffff);
		HC595SendData_2(CS5);
		Delay(0x3fffff);
		HC595SendData_2(CS6);
		Delay(0x3fffff);
		HC595SendData_2(CS7);
		Delay(0x3fffff);
		HC595SendData_2(CS8);
		Delay(0x3fffff);


//		HC595SendData_3(0xff);                    // 1  OK!!!
//		Delay(0x3fffff);
//		HC595SendData_3(0x00);
//		Delay(0x3fffff);
//		HC595SendData_3(CS1);
//		Delay(0x3fffff);
//		HC595SendData_3(CS2);
//		Delay(0x3fffff);
//		HC595SendData_3(CS3);
//		Delay(0x3fffff);
//		HC595SendData_3(CS4);
//		Delay(0x3fffff);
//		HC595SendData_3(CS5);
//		Delay(0x3fffff);
//		HC595SendData_3(CS6);
//		Delay(0x3fffff);
//		HC595SendData_3(CS7);
//		Delay(0x3fffff);
//		HC595SendData_3(CS8);
//		Delay(0x3fffff);
//		S_CLK_1(0);
//		Delay(0xfffff);
//		S_CLK_1(1);
//		Delay(0xfffff);
//		
//		MOSIO_1(0);
//		Delay(0xfffff);
//		MOSIO_1(1);
//		Delay(0xfffff);
//		
//		R_CLK_1(0);
//		Delay(0xfffff);
//		R_CLK_1(1);
//		Delay(0xfffff);

  }
}

void Delay(__IO u32 nCount)
{
  for(; nCount != 0; nCount--);
} 

void HC595SendData(unsigned char SendVal)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if((SendVal<<i)&0x80)MOSIO(1);
		else MOSIO(0);
		S_CLK(0);
		S_CLK(1);
	}
	R_CLK(0);
	R_CLK(1);
}

void HC595SendData_1(unsigned char SendVal_1)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if((SendVal_1<<i)&0x80)MOSIO_DATA_1(1);
		else MOSIO_DATA_1(0);
		CLK_IN_1(0);
		CLK_IN_1(1);
	}
	CLK_OUT_1(0);
	CLK_OUT_1(1);
}

void HC595SendData_2(unsigned char SendVal_2)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if((SendVal_2<<i)&0x80)MOSIO_DATA_2(1);
		else MOSIO_DATA_2(0);
		CLK_IN_2(0);
//		for(k=0;k<1000;k++);
		CLK_IN_2(1);
	}
	CLK_OUT_2(0);
//	for(k=0;k<1000;k++);
	CLK_OUT_2(1);
}

void HC595SendData_3(unsigned char SendVal_3)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if((SendVal_3<<i)&0x80)MOSIO_DATA_3(1);
		else MOSIO_DATA_3(0);
		CLK_IN_3(0);
//		for(k=0;k<1000;k++);
		CLK_IN_3(1);
	}
	CLK_OUT_3(0);
//	for(k=0;k<1000;k++);
  CLK_OUT_3(1);
}


void HC595SendData_4(unsigned char SendVal_4)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if((SendVal_4<<i)&0x80)MOSIO_DATA_4(1);
		else MOSIO_DATA_4(0);
		CLK_IN_4(0);
//		for(k=0;k<1000;k++);
		CLK_IN_4(1);
	}
	CLK_OUT_4(0);
//	for(k=0;k<1000;k++);
  CLK_OUT_4(0);
}


/******************* (C) COPYRIGHT 2011 Ұ��Ƕ��ʽ���������� *****END OF FILE****/
