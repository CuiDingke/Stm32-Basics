#include "stm32f10x.h"
#include  "in_pwm.h"
#include "bsp_usart1.h"
#include "stdio.h"
#include "tim.h"
extern uint16_t sum;
void delay(__IO u32 j);
extern __IO uint16_t DutyCycle;
extern __IO uint32_t Frequency;
extern __IO uint16_t IC2Value;

int main(void)
{
	USART1_Config();
  NVIC_Configuration();
  GPIO_Configuration();
  In_Pwm_Tim3();
//	tim3_Init();
  while (1)
	{
		sum = 499;
		tim3_Init();
    delay(0x0fFFff);
		printf ("Frequency=%d\r\n",Frequency);
		printf ("DutyCycle=%d\r\n",DutyCycle);
//下面是一个完整的程序
//			for(sum=0;sum<1000;sum=sum+10)
//			{
//		 	  tim3_Init();
//        delay(0x0fFFff);
//				printf ("DutyCycle=%d\r\n",DutyCycle);
//		    delay(0x0fFFf);
//	      printf ("Frequency=%d\r\n",Frequency);
//	      delay(0x0fFFf);
//			  printf ("IC2Value=%d\r\n",IC2Value);
//	      delay(0x0fFff);
//			}
//			if(sum==1000)
//			{
//			  for(sum=1000;sum>0;sum=sum-10)
//			{ 
//		    tim3_Init();
//				delay(0x0fFFff);
//				printf ("DutyCycle=%d\r\n",DutyCycle);
//		    delay(0x0fFff);
//	      printf ("Frequency=%d\r\n",Frequency);
//	      delay(0x0fFff);
//				printf ("IC2Value=%d\r\n",IC2Value);
//	      delay(0x0fFff);
//			}
//			}
    



	}

}



void delay(__IO u32 j)
{
for(; j!=0; j--);
}
