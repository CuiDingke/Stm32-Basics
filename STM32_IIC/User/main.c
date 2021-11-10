/*******************************************************************************
** 文件名: 		main.c
** 版本：  		1.0
** 工作环境: 	RealView MDK-ARM 4.20
** 作者: 		河南科技学院
** 生成日期: 	2012-02-10
** 功能:		模版程序（用户可以在这里简单说明工程的功能）
** 相关文件:	无
** 修改日志：	2012-02-10   创建文档
*******************************************************************************/
/* 包含头文件 *****************************************************************/
#include "stm32f10x.h"
#include "usart1.h" 
#include "i2c.h"
#include "delay.h"
#include "misc.h"
#include <stdio.h>


extern uint32_t temp;	
int main(void)
{	
     USART1_Config();
	 i2c_init();
	 delay_init();				   
	 

 while (1)
    {
	 IIC_WriteOneData(12,'f');
	 delay_ms(100);
	 IIC_ReadOneData(12);	
	 printf("%c\r\n",temp);					
    }
}




					  
