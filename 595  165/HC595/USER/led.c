/******************** (C) COPYRIGHT 2011 野火嵌入式开发工作室 ********************
 * 文件名  ：led.c
 * 描述    ：led 应用函数库
 *          
 * 实验平台：野火STM32开发板
 * 硬件连接：-----------------
 *          |   PC3 - LED1     |
 *          |   PC4 - LED2     |
 *          |   PC5 - LED3     |
 *           ----------------- 
 * 库版本  ：ST3.0.0
 *
 * 作者    ：fire  QQ: 313303034																										  
 * 博客    ：firestm32.blog.chinaunix.net 
**********************************************************************************/

#include "led.h"

/*
 * 函数名：LED_GPIO_Config
 * 描述  ：配置LED用到的I/O口
 * 输入  ：无
 * 输出  ：无
 */
void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE); 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 |GPIO_Pin_10 |GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14 | GPIO_Pin_15; 

	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;           

	GPIO_Init(GPIOC, &GPIO_InitStructure); 

	PWR_BackupAccessCmd(ENABLE);

	RCC_LSEConfig(RCC_LSE_OFF);

	BKP_TamperPinCmd(DISABLE);

	PWR_BackupAccessCmd(DISABLE);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);  
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_9;	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_ResetBits(GPIOB,GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_9);
	GPIO_ResetBits(GPIOC, GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 |GPIO_Pin_10 |GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14 | GPIO_Pin_15);	
//	 // turn off all led
}


/******************* (C) COPYRIGHT 2011 野火嵌入式开发工作室 *****END OF FILE****/
