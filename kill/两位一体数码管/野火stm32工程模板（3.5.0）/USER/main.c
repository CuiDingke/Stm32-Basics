/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ����3.5.0�汾���Ĺ���ģ�塣         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"

#include "led.h"
void Delay(__IO u32 nCount);
uint16_t aa[]={0x01BF,0x0186,0x01DB,0x01CF,0x01E6,0x01ED,0x01FD,0x0187,0x01FF,0x01EF};
uint16_t i;
uint16_t bb[]={0x02BF,0x0286,0x02DB,0x02CF,0x02E6,0x02ED,0x02FD,0x0287,0x02FF,0x02EF};
uint16_t j;

//void display(uint8_t num);
//uint8_t shi,ge;
//uint8_t n=0;
/* 
 * ��������main
 * ����  : ������
 * ����  ����
 * ���  : ��
 */
int main(void)
{
	LED_GPIO_Config();
	

  	  while(1)
			{
//				  display(n);
//				  n++;
//	        if(n>99)n=0;

//					GPIO_Write(GPIOA,aa[shi]);
//					Delay(0x5ffff);
//		
//					GPIO_Write(GPIOA,bb[ge]);
//			    Delay(0x5ffff);
//					
					
////			
//				if(i<9)
//				{
//				GPIO_Write(GPIOA,aa[i]);i++;
//					Delay(0x5ffff);
//				}
//				else i=0;
//				if(i==9)j++;GPIO_Write(GPIOA,bb[j]);
//				Delay(0x5ffff);
//    }
				for(j=0;j<10;j++)
			{
//					GPIO_Write(GPIOA,bb[j]);
//					Delay(0x3fffff);
					for(i=0;i<10;i++)
					{	
						GPIO_Write(GPIOA,bb[j]);
					Delay(0x3ffff);
					GPIO_Write(GPIOA,aa[i]);
			    Delay(0x3ffff);
					}
			
    }
//				
				
//			for(j=0;j<10;j++)
//				{
//				if(j==9) 	i++;
//				GPIO_Write(GPIOA,bb[j]);
//					Delay(0x3fffff);
//				GPIO_Write(GPIOA,aa[i]);
//				Delay(0x3ffff);
				
				
//				}
			}
				
		}
		

	
//void display(uint8_t num)
//{


//	shi=num/10;
//	ge=num%10;

//}
//		
		
		
		
		
		
		
		
		
void Delay(__IO u32 nCount)
{
for(; nCount!=0;nCount--);
}
