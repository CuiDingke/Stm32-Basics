#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"	 
#include "24l01.h" 
#include "adc.h"
#include "pwm_toggle.h"
#include "misc.h" 

extern float T1,T2;
u8 tmp_buf[6]={0x88,'a','b','a','b',0x44};	
extern uint16_t ADC_Conf[20];
u16 R1,R2;
u8 *p1,*p2;
extern __IO uint16_t CCR1_Val,CCR2_Val;
 int main(void)
 {
	u8 key,mode;
	u16 t=0,i=0;			   
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Adc_Init();
	uart_init(115200);
 	LED_Init();
	KEY_Init();
	NRF24L01_Init();
	toggle_Config();
	printf("现在开始...\r\n");
//	 while(1)
//	 {
//			Average_h(ADC_Conf);
//			R1=T1*330/4096;
//			R2=T2*330/4096;
//		  printf("%d",R1);
//	 }
	while(NRF24L01_Check())
	{
		printf("正在检查\r\n");
		delay_ms(200);
	}	
	printf("检查完成\r\n");
	printf("KEY0:RX_Mode,KEY1:TX_Mode\r\n");
 	while(1)
	{	
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)==0)
		{
			while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)==0);
			mode=0;
			break;
		}
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)==0)
		{
			while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)==0);
			mode=1;
			break;
		}
	}
	if(mode==0)//RX模式
	{
		printf("NRF24L01 RX_Mode");
		NRF24L01_RX_Mode();		  
		while(1)
		{	  		    		    				 
			if(NRF24L01_RxPacket(tmp_buf)==0)
			{
				
				if(tmp_buf[0]==0x88&&tmp_buf[5]==0x44)
				{
					R1=*((u16 *)(&tmp_buf[1]));
					if(R1>165)
					{
						delay_ms(500);
						CCR1_Val=1500+(R1-165)*6.06;
					}
					else
					{
						delay_ms(500);
						CCR1_Val=1500-(165-R1)*6.06;
					}
				}
//			tmp_buf[32]=0;//加入字符串结束符
//				for(i=0;i<6;i++)
//				{
//				  printf("%0x",tmp_buf[i]);
//				}
//				printf("\r\n");
			}			    
		}	
	}
	else//TX模式
	{							    
		printf("NRF24L01 TX_Mode");
		NRF24L01_TX_Mode();
		while(1)
		{	  		
			Average_h(ADC_Conf);
			R1=T1*330/4096;
			R2=T2*330/4096;
			p1=(u8 *)&R1;
			p2=(u8 *)&R2;
			tmp_buf[1]=*p1;
			tmp_buf[2]=*(p1+1);
			tmp_buf[3]=*p2;
			tmp_buf[4]=*(p2+1);
			
//			tmp_buf[1]=R1>>8;
//			tmp_buf[2]=R1;
//			tmp_buf[3]=R2>>8;
//			tmp_buf[4]=R2;
//			tmp_buf[1]=R1;
//			tmp_buf[2]=R2;
			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{
				for(i=0;i<6;i++)
				{
				  printf("%d:%d  ",i,tmp_buf[i]);
				}
				printf("\r\n");
			}			    
		}
	} 
}


	

	 
