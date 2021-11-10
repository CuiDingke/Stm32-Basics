#include "stm32f10x.h"
#include "x_usart1.h"
#include "x_adc.h"
#include "x_exti.h"
#include "delay.h"

#include "x_tim.h"


extern __IO uint16_t ADC_ConvertedValue[1];
extern uint16_t a;
uint8_t b,c;
float ADC_ConvertedValuetel[1],bc,ab;
extern uint32_t i;
int main(void)
{
	USART1_Config();
	EXTI_PA1_Config();
	delay_init();
	ADC1_Init();
	ADC1_Cal();
  	  while(1)
			{

    if(a==1)
		{
			ADC_ConvertedValuetel[0]=ADC_ConvertedValue[0]*3.3/4096;
    	ADC_ConvertedValuetel[0]=(1.43-ADC_ConvertedValuetel[0])*1000/4.3+25;

			printf("通道16当前温度：%.2f\r\n",ADC_ConvertedValuetel[0]);
      delay_ms(100);
			bc=ADC_ConvertedValuetel[0];
			if(bc<30)          i=0;
			else if(bc<100&&bc>=30)
			{
			   ab=(uint16_t)ADC_ConvertedValuetel[0]%30*50;
			   i=ab+400;
				 if(i>950)       i=950;
			}		
		tim3_Init();
	delay_ms(100);
		}
		
      
	
	}
}