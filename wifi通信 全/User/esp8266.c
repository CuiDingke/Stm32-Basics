#include "esp8266.h"
#include "usart1.h"
#include "delay.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
unsigned int   usart1_rcv_len=0;
unsigned char  usart1_rcv_buf[1024];
void Esp8266_Config(void)
{
	SendCmd(AT,"OK",1000);
	SendCmd(RST,"OK",2000);
	SendCmd(CIPMODE,"OK",1000);
	SendCmd(CIPMUX,"OK",1000);
	SendCmd(CWJAP,"OK",3000);
	SendCmd(CIPSTART,"OK",3000);
	SendCmd(CIPSEND,"OK",2000);
}

void SendCmd(char* cmd, char* result, int timeOut)
{
	static int i = 0;
	while(1)
	{
		memset(usart1_rcv_buf,0,sizeof(usart1_rcv_buf));
		usart1_rcv_len=0;
		usart1_write(USART1, (unsigned char *)cmd, strlen((const char *)cmd));
		delay_ms(timeOut);
	 
		if((NULL != strstr((const char *)usart1_rcv_buf, result)))
		{
			break;
		}
		else
		{
			delay_ms(100);
			i++;
			if(i == 50)
			{
				i = 0;
				Esp8266_Config();
			}
		}
	}
}


int ESP8266_CheckStatus(int timeOut)
{
	int res=0;
	int count=0;
	memset(usart1_rcv_buf,0,sizeof(usart1_rcv_buf));
	usart1_rcv_len=0;
//	usart1_write(USART1,CIPSTATUS,strlen(CIPSTATUS));
	for(count=0;count<timeOut;count++)
	{
		delay_ms(100);
		if((NULL != strstr((const char *)usart1_rcv_buf,"STATUS:4")))
		{
			res=-4;
			break;
		}
		else if((NULL != strstr((const char *)usart1_rcv_buf,"STATUS:3")))
		{
			res=0;	
			break;
		}
		else if((NULL != strstr((const char *)usart1_rcv_buf,"STATUS:2")))
		{
			res=-2;
			break;				
		}
		else if((NULL != strstr((const char *)usart1_rcv_buf,"STATUS:5")))
		{
			res=-5;
			break;
		}
		else if((NULL != strstr((const char *)usart1_rcv_buf,"ERROR")))   
		{
			res=-1;
			break;
		}
		else
		{
				;
		}
	}	
	return res;	
}

