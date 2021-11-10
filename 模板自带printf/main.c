#include "stm32f10x.h"
#include "stdio.h"
#include "EventRecorder.h"
void Delay(__IO u32 nCount); 

int main(void)
{	
	EventRecorderInitialize(EventRecordAll, 1U);
  EventRecorderStart();
	while (1)
	{
		printf("All lights has working!!\r\n");
	}

}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}

/*********************************************END OF FILE**********************/
