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
uint8_t aa[]={0x61,0x62,0x63,0x64,0x65,0x66};
uint8_t i;
extern uint32_t temp;	
int main(void)
{	
     USART1_Config();
	 i2c_init();
	 delay_init();				   
	 

 while (1)
    {
			for(i=0;i<2;i++)
			{
	 IIC_WriteOneData(12,aa[i]);
	 delay_ms(100);	 
	 IIC_ReadOneData(12);	
	 printf("%c",temp);	
			}		
			 printf("\r\n");
		if(i==2)
		{			
	IIC_WriteOneData(12,aa[i]);
	 delay_ms(100);	 
	 IIC_ReadOneData(12);	
	 printf("%c\r\n",temp);	
			i++;
		}
				for(i=3;i<6;i++)
			{
	 IIC_WriteOneData(12,aa[i]);
	 delay_ms(100);	 
	 IIC_ReadOneData(12);	
	 printf("%c",temp);	
			}		
			 printf("\r\n");
			i=0;
    } 
} 




					  
