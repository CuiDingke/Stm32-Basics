#include "stm32f10x.h"
#include "tim.h"

void delay(__IO u32 j);
extern uint32_t i;
// extern uint32_t a,b;
int main(void)
{

    while (1)
    {
			for(i=0;i<1000;i=i+100)//˫ͨ���෴����仯  ��pwm1��2 ģʽ�෴ ͬһ����
			{
			tim3_Init();
				delay(0x0fffff);
			
			}
			for(i=1000;i>0;i=i-100)
			{
			tim3_Init();
				delay(0x0fffff);
			
			}
//			for(i=0;i<10;i++)//˫ͨ�����ñ仡��ͬ����  ��ͬ����
//			{
//			   a=a+100;b=b+50;
//				tim3_Init();
//				delay(0x0fffff);
//			}
//			if(i==10)
//			{
//			  for(i=10;i>0;i--)
//				{
//				 a=a-100;b=b-50;
//				 tim3_Init();
//					delay(0x0fffff);
//				
//				}
			
//			}
    }
}
void delay(__IO u32 j)
{
for(; j!=0; j--);
}



/***********************************�ļ�����***********************************/
