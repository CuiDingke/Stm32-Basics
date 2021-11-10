#ifndef __LCD1602_H
#define __LCD1602_H
#include "sys.h"
#define RS0 GPIO_ResetBits(GPIOB,GPIO_Pin_15)
#define RS1 GPIO_SetBits(GPIOB,GPIO_Pin_15)

#define RW0 GPIO_ResetBits(GPIOB,GPIO_Pin_14)
#define RW1 GPIO_SetBits(GPIOB,GPIO_Pin_14)

#define EN0 GPIO_ResetBits(GPIOB,GPIO_Pin_13)
#define EN1 GPIO_SetBits(GPIOB,GPIO_Pin_13)

#define DATE(X) GPIO_Write(GPIOC,X)

void GPIO_Config (void);
void LCD1602_Read_Mode (void);
void LCD1602_Write_Cmd (u8 b);
void LCD1602_Write_Date (u8 c);
void LCD1602_Clear (void);
void LCD1602_Set_Cursor(u8 x, u8 y);
void LCD1602_Show_Str(u8 x, u8 y, u8 *d);
void LCD1602_Init (void);


#endif
