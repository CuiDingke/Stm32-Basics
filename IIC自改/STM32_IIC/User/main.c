/*******************************************************************************
** �ļ���: 		main.c
** �汾��  		1.0
** ��������: 	RealView MDK-ARM 4.20
** ����: 		���ϿƼ�ѧԺ
** ��������: 	2012-02-10
** ����:		ģ������û������������˵�����̵Ĺ��ܣ�
** ����ļ�:	��
** �޸���־��	2012-02-10   �����ĵ�
*******************************************************************************/
/* ����ͷ�ļ� *****************************************************************/
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




					  
