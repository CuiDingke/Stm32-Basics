#include "stm32f10x.h"
#include "tim.h"

void delay(__IO u32 j);
extern uint32_t i;
// extern uint32_t a,b;
int main(void)
{

    while (1)
    {
			for(i=0;i<1000;i=i+100)//双通道相反方向变化  将pwm1，2 模式相反 同一变量
			{
			tim3_Init();
				delay(0x0fffff);
			
			}
			for(i=1000;i>0;i=i-100)
			{
			tim3_Init();
				delay(0x0fffff);
			
			}
//			for(i=0;i<10;i++)//双通道不用变弧同方向  不同变量
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



/***********************************文件结束***********************************/
