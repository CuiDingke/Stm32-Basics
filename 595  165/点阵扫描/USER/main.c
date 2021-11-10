/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ��LED��ˮ�ƣ�Ƶ�ʿɵ�����         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#define HC595_PORT  GPIOC
#define HC595_DATA  GPIO_Pin_12    // serial data input, pin14
#define HC595_SCLK  GPIO_Pin_10    // shift register clock input, pin11
#define HC595_RCLK  GPIO_Pin_8     // storage register clock input, pin12
//#define HC595_DELAY DelayUs(100);
//void hc595_init ( void ) ;
void hc595_write_byte ( uint8_t byte ) ;
void hc595_latch ( void ) ;
//void hc595_display ( uint8_t data [ ] ) ;


//#define    MI_ERR    (-2)

void delay(__IO u32 nCount);
uint16_t i,j;
uint8_t	table1[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
uint8_t	table2[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{	
	 GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOA, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  GPIO_SetBits(GPIOC, GPIO_Pin_All);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  GPIO_ResetBits(HC595_PORT, HC595_DATA);
  GPIO_ResetBits(HC595_PORT, HC595_SCLK);
  GPIO_ResetBits(HC595_PORT, HC595_RCLK);
 // GPIO_SetBits(GPIOA, GPIO_Pin_All);


	while (1)
	{
		 	uint8_t i,j;
		for(j=0;j<8;j++)
		{
			 for(i=0;i<8;i++)
			 {
				 hc595_write_byte(0Xff);
				 hc595_latch () ;
				 hc595_write_byte(table2[j]);
				 hc595_latch () ;
				 hc595_write_byte(0X00);
				 hc595_latch () ;
				 hc595_write_byte(table1[i]);
				 hc595_latch () ;
				 delay(1000000);
			 }
			 		 for(i=0;i<8;i++)
			 {
				 hc595_write_byte(0Xff);
				 hc595_latch () ;
				 hc595_write_byte(table2[j]);
				 hc595_latch () ;
				 hc595_write_byte(table1[i]);
				 hc595_latch () ;
				 hc595_write_byte(0x00);
				 hc595_latch () ;
				 delay(1000000);
			 }
		 }
		 	for(j=0;j<8;j++)
		{
			 for(i=0;i<8;i++)
			 {
				 hc595_write_byte(table2[j]);
				 hc595_latch () ;
				 hc595_write_byte(0xff);
				 hc595_latch () ;
				 hc595_write_byte(0X00);
				 hc595_latch () ;
				 hc595_write_byte(table1[i]);
				 hc595_latch () ;
				 delay(1000000);
			 }
			 		 for(i=0;i<8;i++)
			 {
				 hc595_write_byte(table2[j]);
				 hc595_latch () ;
				 hc595_write_byte(0Xff);
				 hc595_latch () ;
				 hc595_write_byte(table1[i]);
				 hc595_latch () ;
				 hc595_write_byte(0x00);
				 hc595_latch () ;
				 delay(1000000);
			 }
		 }

	}

		
}

void delay(__IO u32 nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
} 
void hc595_write_byte(uint8_t byte)
{
  uint8_t i, num;
  num = byte;
  for (i=0; i<8; i++)
  {
    GPIO_ResetBits(HC595_PORT, HC595_SCLK);
    if ((num&0x01)==0x01)
      GPIO_SetBits(HC595_PORT, HC595_DATA);
    else
      GPIO_ResetBits(HC595_PORT, HC595_DATA);
    GPIO_SetBits(HC595_PORT, HC595_SCLK);
    num = num>>1;
  }
}
void hc595_latch(void)
{
  GPIO_ResetBits(HC595_PORT, HC595_RCLK);
  GPIO_SetBits(HC595_PORT, HC595_RCLK);
  GPIO_ResetBits(HC595_PORT, HC595_RCLK);
}

