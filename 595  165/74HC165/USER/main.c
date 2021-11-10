/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：LED流水灯，频率可调……         
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "led.h"
#include "usart1.h"

//#define    MI_ERR    (-2)

void Delay(__IO u32 nCount);
u8 HC165ReadData(void);
u8 Data = 0;

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{	
	/* LED 端口初始化 */
	LED_GPIO_Config();
	USART1_Config();
	NVIC_Configuration();
	printf("sdfdsf");

	while (1)
	{
//		GPIO_ResetBits(GPIOA,GPIO_Pin_0);                                                  //置入数据
//		Delay(1000);
		GPIO_SetBits(GPIOC, GPIO_Pin_3 | GPIO_Pin_1 |GPIO_Pin_5 ); 
		GPIO_ResetBits(GPIOC,  GPIO_Pin_1 | GPIO_Pin_7 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_6); 

//		
//		GPIO_SetBits(GPIOA,GPIO_Pin_0);                                                    //串行读取数据
//		Delay(1000);
		
		HC165ReadData();
		printf("%d\r\n",Data);
		Data = 0;
		Delay(0xFFFFF);
	}
}

void Delay(__IO u32 nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
} 

u8 HC165ReadData(void)
{
	unsigned char i;
//	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	PL(0);
////	Delay(0xFFFF);
//	GPIO_SetBits(GPIOA,GPIO_Pin_0);
	PL(1);
//	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	CLK(0);
//	Delay(0xFFFF);
	for(i=0;i<8;i++)
	{
		Data <<= 1;
//		Delay(0xFFFF);
//		GPIO_ResetBits(GPIOA,GPIO_Pin_1);
		CLK(0);
//		Delay(0xFFFF);
		Data|=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2); 
//		GPIO_SetBits(GPIOA,GPIO_Pin_1);
		CLK(1);
//		Delay(0xFFFF);
	}
	return Data;
	
}



/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
