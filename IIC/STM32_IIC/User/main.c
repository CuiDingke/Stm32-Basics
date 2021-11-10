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




					  