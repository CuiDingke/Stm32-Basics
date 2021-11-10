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
//#include "bsp_usart1.h"
uint16_t receive[20]={0};
uint16_t shuzi[20]={0};
uint8_t  zifu[20]={0};
uint8_t  shuzi_number=0;
uint8_t  zifu_number=0;
uint8_t number=0;
uint8_t c=0;
void paixu(void);
void USART1_Cofig(void);
void delay(uint16_t q);
	
/* �������� ------------------------------------------------------------------*/
/* �궨�� --------------------------------------------------------------------*/

/* ���� ----------------------------------------------------------------------*/


/* �������� ------------------------------------------------------------------*/
/* �������� ------------------------------------------------------------------*/

/*******************************************************************************
  * @��������	main
  * @����˵��   ������ 
  * @�������   ��
  * @�������   ��
  * @���ز���   ��
  *****************************************************************************/
int main(void)
{
	uint8_t x=0,y=0;
   //USART1_Config();
	USART1_Cofig();
	//printf("please enter the number");
	
	while(1)
	{
    while (c)
    {
			delay(10);
			paixu();
			for(x=0;x<shuzi_number;x++)//��������
			{
				USART1->DR=shuzi[x]; 
				while (USART_GetFlagStatus(USART1, USART_FLAG_TXE)==0);
			}
			USART1->DR=0x0a;//����
			while (USART_GetFlagStatus(USART1, USART_FLAG_TXE)==0);
			for(y=0;y<zifu_number;y++)//������ĸ ��ĸСдת��д
			{
				USART1->DR=zifu[y]; 
				while (USART_GetFlagStatus(USART1, USART_FLAG_TXE)==0);
			}
			USART1->DR=0x0a;//����
//			for(x=0;x<=shuzi_number;x++ )
//			{
//			printf("%c",shuzi[x]);	
//			}
//			for(y=0;y<=zifu_number;y++)
//			{
//			printf("%c",zifu[y]);
//			}
//			printf("\n");
				c=0;
			shuzi_number=0;
			zifu_number=0;
			number=0;
		}	
	
			
    }
}

void USART1_IRQHandler(void)
{
    if(USART_GetITStatus(USART1,USART_IT_RXNE)==1)
   {
	     receive[number]=USART_ReceiveData(USART1);
		   number++;
	
   }
	 c=1;

}



void USART1_Cofig(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;
		USART_InitTypeDef USART_InitStructure;
				 NVIC_InitTypeDef NVIC_InitStructure;
		
		/* ��һ�� */
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA| RCC_APB2Periph_GPIOC, ENABLE);
		
		/* USART1 GPIO ���� */
		/* Configure USART1 Tx (PA.09) as alternate function push-pull */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);	
		 
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
			
		/* USART1�ṹ������ */
		USART_InitStructure.USART_BaudRate = 115200;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		USART_InitStructure.USART_StopBits = USART_StopBits_1;
		USART_InitStructure.USART_Parity = USART_Parity_No ;
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
		USART_Init(USART1, &USART_InitStructure); 
		USART_Cmd(USART1, ENABLE); 
		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
		 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);     //��ռ����Ȩ2�������ȼ�2λ
		 NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;    //�������ж�1
		 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;   //ָ����ռ���ȼ���1
		 NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;    //ָ����Ӧ���ȼ���0
		 NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		 NVIC_Init(&NVIC_InitStructure);	
}

void paixu(void)
{
	uint8_t m,n,temp;
    for(n=0;n<=number;n++)
	  {
	      if(47<receive[n]&receive[n]<58)
				{
				  shuzi[shuzi_number]=receive[n];
				  shuzi_number++;
				}	
				if(64<receive[n]&receive[n]<91)
				{
				  zifu[zifu_number]=receive[n];
					zifu_number++;
				}	
				if(96<receive[n]&receive[n]<123)
				{
				  zifu[zifu_number]=receive[n];
					zifu_number++;
				
				}
		}
		for(m=shuzi_number;m>0;m--)
		     {
					for(n=0;n<m;n++)
		       if(shuzi[n]<shuzi[n+1])
			     {
				      temp=shuzi[n];
			        shuzi[n]=shuzi[n+1];
			        shuzi[n+1]=temp;
			     }
				 } 
		for(m=zifu_number;m>0;m--)
				 {
				  for(n=0;n<m;n++)
					 if(zifu[n]<zifu[n+1])
					 {
					    temp=zifu[n];
						  zifu[n]=zifu[n+1];
						  zifu[n+1]=temp;
					 }
				 
				 }

}

void delay(uint16_t q)
{
uint16_t w;
	for(;q>0;q--)
	{
	for(w=0;w<12000;w++);
	}

}


/***********************************�ļ�����***********************************/
