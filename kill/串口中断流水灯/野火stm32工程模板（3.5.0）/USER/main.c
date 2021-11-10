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
#include"stm32f10x.h"
void Delay(__IO u32 nCount);
uint8_t aa[]="www.xuebingchuan.com\r\n";
uint8_t i=0;
uint8_t a;
int date;

int main(void)
{
	
	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	GPIO_SetBits(GPIOC,GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
	USART_Init(USART1,&USART_InitStructure);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART1,ENABLE);
	while(1)
	{
		for(i=0;i<sizeof-1;i++)
		{
			USART1->DR=aa[i];
			while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==0);
		}
		while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==1);
		
if(a==49)
{
//	GPIOC->ODR^=1<<1;
GPIO_ResetBits(GPIOC,GPIO_Pin_1);

	a=2;
}
if(a==2)
{
//	GPIOC->ODR^=1<<1;
GPIO_ResetBits(GPIOC,GPIO_Pin_2);

	a=3;
}
if(a==3)
{
//	GPIOC->ODR^=1<<1;
GPIO_ResetBits(GPIOC,GPIO_Pin_3);
Delay(0x0ffffff);
	a=0;
//	GPIO_Write(GPIOC,0XFF);
}
	}	
		
}

void Delay(__IO u32 nCount)
{

for(; nCount==1; nCount--);
}

	//void USART1_IRQHandler(void)
//{
//	
////	uint8_t c;
//	if(USART_GetITStatus(USART1,USART_IT_RXNE)==1)
//	{
////		c=USART1->DR;
//	a=1;
//	}
////		USART_ClearITPending(USART1,USART_IT_RXNE);

