#include "stm32f10x.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "adc.h"
 
uint16_t temp;
float a;
uint16_t aa[2];
float a,b,c,d;
u8 i;
void Delay(__IO uint32_t nCount);

 
 int main(void)
 {	 
	 ADC1_GPIO_Config();
	 ADC1_Mode_Config();
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	LCD_Init();			 	

	POINT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(60,50,200,16,16,"WarShip STM32");	
	LCD_ShowString(60,70,200,16,16,"ADC TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2015/1/14");	
	//��ʾ��ʾ��Ϣ
	POINT_COLOR=BLUE;//��������Ϊ��ɫ
	LCD_ShowString(60,130,200,16,16,"ADC_CH0_VAL:");	      
	LCD_ShowString(60,150,200,16,16,"ADC_CH0_VOL:0.000V");	       
	while(1)
	{
		for(i=0;i<20;i++)
		{
			temp=ADC1->DR;//��ͨ���ɼ�
			a=temp*3.3/4096;
			b+=a;					
			}
			b=b/20;
			LCD_ShowxNum(156,150,b,1,16,0);//��ʾ��ѹֵ

	}
 }

