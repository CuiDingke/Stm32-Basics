#include "stm32f10x_it.h"
#include  "led.h"
#include "string.h"

extern unsigned char  usart1_rcv_buf[1024];
extern unsigned int   usart1_rcv_len;
unsigned char  usart1_cmd_buf[256];
unsigned int   usart1_cmd_len=0;
unsigned char  rcv_cmd_start=0;

void USART1_IRQHandler(void)
{
  unsigned int data;
	if(USART_GetITStatus(USART1,USART_IT_RXNE) == 1)
	{		
		data = USART1->DR;
		USART2->DR=data;
		usart1_rcv_buf[usart1_rcv_len++]=data;
		if(data=='{') 
		{
				rcv_cmd_start=1;
		}
		if(rcv_cmd_start==1)
		{
				usart1_cmd_buf[usart1_cmd_len++]=data;
				if((data=='}')||(usart1_cmd_len>=256-1))
				{
						rcv_cmd_start=0;
//								LED_CmdCtl();
						memset(usart1_cmd_buf,0,usart1_cmd_len);
						usart1_cmd_len=0;
				}
			}	  
    }
		else
		{
				;
		}
}