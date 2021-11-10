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
	
/* 类型声明 ------------------------------------------------------------------*/
/* 宏定义 --------------------------------------------------------------------*/

/* 变量 ----------------------------------------------------------------------*/


/* 函数声明 ------------------------------------------------------------------*/
/* 函数功能 ------------------------------------------------------------------*/

/*******************************************************************************
  * @函数名称	main
  * @函数说明   主函数 
  * @输入参数   无
  * @输出参数   无
  * @返回参数   无
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
			for(x=0;x<shuzi_number;x++)//发送数字
			{
				USART1->DR=shuzi[x]; 
				while (USART_GetFlagStatus(USART1, USART_FLAG_TXE)==0);
			}
			USART1->DR=0x0a;//换行
			while (USART_GetFlagStatus(USART1, USART_FLAG_TXE)==0);
			for(y=0;y<zifu_number;y++)//发送字母 字母小写转大写
			{
				USART1->DR=zifu[y]; 
				while (USART_GetFlagStatus(USART1, USART_FLAG_TXE)==0);
			}
			USART1->DR=0x0a;//换行
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
		
		/* 第一步 */
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA| RCC_APB2Periph_GPIOC, ENABLE);
		
		/* USART1 GPIO 配置 */
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
			
		/* USART1结构体配置 */
		USART_InitStructure.USART_BaudRate = 115200;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		USART_InitStructure.USART_StopBits = USART_StopBits_1;
		USART_InitStructure.USART_Parity = USART_Parity_No ;
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
		USART_Init(USART1, &USART_InitStructure); 
		USART_Cmd(USART1, ENABLE); 
		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
		 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);     //先占优先权2，从优先级2位
		 NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;    //开串口中断1
		 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;   //指定抢占优先级别1
		 NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;    //指定相应优先级别0
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


/***********************************文件结束***********************************/
