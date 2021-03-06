 /**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   华邦 8M串行flash测试，并将测试信息通过串口1在电脑的超级终端中打印出来
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 iSO STM32 开发板 
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */ 
#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "bsp_spi_flash.h"


typedef enum { FAILED = 0, PASSED = !FAILED} TestStatus;


/* 获取缓冲区的长度 */
#define TxBufferSize1   (countof(TxBuffer1) - 1)
#define RxBufferSize1   (countof(TxBuffer1) - 1)
#define countof(a)      (sizeof(a) / sizeof(*(a)))
#define  BufferSize (countof(Tx_Buffer)-1)

#define  FLASH_WriteAddress     0x00000
#define  FLASH_ReadAddress      FLASH_WriteAddress
#define  FLASH_SectorToErase    FLASH_WriteAddress
//#define  sFLASH_ID              0xEF3015     //W25X16
//#define  sFLASH_ID              0xEF4015	 //W25Q16
#define  sFLASH_ID              0XEF4017    //W25Q64
     

/* 发送缓冲区初始化 */
uint8_t Tx_Buffer[] = " 感谢您选用野火stm32开发板\r\n                http://firestm32.taobao.com";
uint8_t Rx_Buffer[BufferSize];

__IO uint32_t DeviceID = 0;
__IO uint32_t FlashID = 0;
__IO TestStatus TransferStatus1 = FAILED;

// 函数原型声明
void Delay(__IO uint32_t nCount);
TestStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength);

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
 
 
 void LED_Iint(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
}
int main(void)
{ 	
	/* 配置串口1为：115200 8-N-1 */
	USARTx_Config();
	printf("\r\n 这是一个8Mbyte串行flash(W25Q64)实验 \r\n");
	LED_Iint();
	/* 8M串行flash W25Q64初始化 */
	SPI_FLASH_Init();
//	while(1)
//	{
////		 printf("\r\n 这是一个8Mbyte串行flash(W25Q64)实验 \r\n");
//		 SPI_FLASH_ReadDeviceID();
//	}
	while(1)
	{
		 SPI_FLASH_WriteEnable();
		 Delay(0X2FFFFF);
		 SPI_FLASH_WriteEnable1();
		 Delay(0X2FFFFF);		
//		 SPI_FLASH_SendByte(0x21);
//		 Delay(0X1FFFF);		
//		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);
//		 Delay(0X1FFFFF);
//		 GPIO_SetBits(GPIOB,GPIO_Pin_5);		 
	}
	
//	/* Get SPI Flash Device ID */
//	DeviceID = SPI_FLASH_ReadDeviceID();
//	
//	Delay( 200 );
//	
//	/* Get SPI Flash ID */
//	FlashID = SPI_FLASH_ReadID();
//	
//	printf("\r\n FlashID is 0x%X,  Manufacturer Device ID is 0x%X\r\n", FlashID, DeviceID);
//	
//	/* Check the SPI Flash ID */
//	if (FlashID == sFLASH_ID)  /* #define  sFLASH_ID  0XEF4017 */
//	{	
//		printf("\r\n 检测到华邦串行flash W25Q64 !\r\n");
//		
//		/* Erase SPI FLASH Sector to write on */
//		SPI_FLASH_SectorErase(FLASH_SectorToErase);	 	 
//		
//		/* 将发送缓冲区的数据写到flash中 */ 	
//		SPI_FLASH_BufferWrite(Tx_Buffer, FLASH_WriteAddress, BufferSize);
//		SPI_FLASH_BufferWrite(Tx_Buffer, 252, BufferSize);
//		printf("\r\n 写入的数据为：%s \r\t", Tx_Buffer);
//		
//		/* 将刚刚写入的数据读出来放到接收缓冲区中 */
//		SPI_FLASH_BufferRead(Rx_Buffer, FLASH_ReadAddress, BufferSize);
//		printf("\r\n 读出的数据为：%s \r\n", Rx_Buffer);
//		
//		/* 检查写入的数据与读出的数据是否相等 */
//		TransferStatus1 = Buffercmp(Tx_Buffer, Rx_Buffer, BufferSize);
//		
//		if( PASSED == TransferStatus1 )
//		{    
//			printf("\r\n 8M串行flash(W25Q64)测试成功!\n\r");
//		}
//		else
//		{        
//			printf("\r\n 8M串行flash(W25Q64)测试失败!\n\r");
//		}
//	}// if (FlashID == sFLASH_ID)
//	else
//	{    
//		printf("\r\n 获取不到 W25Q64 ID!\n\r");
//	}
//	
//	SPI_Flash_PowerDown();  
//	while(1);  
}

/*
 * 函数名：Buffercmp
 * 描述  ：比较两个缓冲区中的数据是否相等
 * 输入  ：-pBuffer1     src缓冲区指针
 *         -pBuffer2     dst缓冲区指针
 *         -BufferLength 缓冲区长度
 * 输出  ：无
 * 返回  ：-PASSED pBuffer1 等于   pBuffer2
 *         -FAILED pBuffer1 不同于 pBuffer2
 */
TestStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength)
{
  while(BufferLength--)
  {
    if(*pBuffer1 != *pBuffer2)
    {
      return FAILED;
    }

    pBuffer1++;
    pBuffer2++;
  }
  return PASSED;
}

void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
