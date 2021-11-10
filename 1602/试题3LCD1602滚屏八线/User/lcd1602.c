#include"stm32f10x.h"
#include "lcd1602.h"
#include "delay.h"
#include "sys.h"

void GPIO_Config (void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC,ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void LCD1602_Read_Mode (void)//读状态
{
	u8 a;
	DATE(0xff);
	RS0;
	RW1;
	do
	{
		EN1;
		delay_ms(5);
		EN0;
		a=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7);
	}
	while
	(
		a&0x80
	);
}

void LCD1602_Write_Cmd (u8 b)//写命令
{
	LCD1602_Read_Mode();
	RS0;
	RW0;
	DATE(b);
	EN1;
	EN0;
}

void LCD1602_Write_Date (u8 c)//写数据
{
	LCD1602_Read_Mode();
	RS1;
	RW0;
	DATE(c);
	EN1;
	EN0;
}

void LCD1602_Clear (void)//清屏
{
	LCD1602_Write_Cmd(0x01);
}

void LCD1602_Set_Cursor(u8 x, u8 y)/* 设置显示RAM起始地址，亦即光标位置，(x,y)-对应屏幕上的字符坐标 */
{
	u8 addr;
	
	if (y == 0)
		addr = 0x00 + x;
	else
		addr = 0x40 + x;
	LCD1602_Write_Cmd(addr | 0x80);
}

void LCD1602_Show_Str(u8 x, u8 y, u8 *d)/* 在液晶上显示字符串，(x,y)-对应屏幕上的起始坐标，str-字符串指针 */
{
	LCD1602_Set_Cursor(x, y);
	while(*d != '\0')
	{
		LCD1602_Write_Date(*d++);
	}
}

void LCD1602_Init (void)
{
	LCD1602_Write_Cmd(0x38);//16*2显示，5*7点阵，8位数据口
	LCD1602_Write_Cmd(0x0c);//开显示，光标关闭
	LCD1602_Write_Cmd(0x06);//文字不动，地址自动+1
	LCD1602_Write_Cmd(0x01);//清屏
	LCD1602_Write_Cmd(0x10);
}
