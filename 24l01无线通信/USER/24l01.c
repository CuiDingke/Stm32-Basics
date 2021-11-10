#include "24l01.h"
#include "spi.h"
const u8 TX_ADDRESS[TX_ADR_WIDTH]={0x34,0x43,0x10,0x10,0x01};
const u8 RX_ADDRESS[RX_ADR_WIDTH]={0x34,0x43,0x10,0x10,0x01};
void NRF24L01_Init(void)
{ 	
	GPIO_InitTypeDef GPIO_InitStructure;
    SPI_InitTypeDef  SPI_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);
    
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOA,GPIO_Pin_12);		
 	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5;   
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_4|GPIO_Pin_5);			 
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	
  SPI1_Init();    	
	SPI_Cmd(SPI1, DISABLE); 

	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI1, &SPI_InitStructure); 
	SPI_Cmd(SPI1, ENABLE);
			 
	NRF24L01_CE=0;
	NRF24L01_CSN=1;
	 		 	 
}

u8 NRF24L01_Check(void)
{
	u8 buf[5]={0XA5,0XA5,0XA5,0XA5,0XA5};
	u8 i;
	SPI1_SetSpeed(SPI_BaudRatePrescaler_8);
	NRF24L01_Write_Buf(NRF_WRITE_REG+TX_ADDR,buf,5);
	NRF24L01_Read_Buf(TX_ADDR,buf,5); 
	for(i=0;i<5;i++)if(buf[i]!=0XA5)break;	 							   
	if(i!=5)return 1;
	return 0;
}	 

u8 NRF24L01_Write_Reg(u8 reg,u8 value)
{
	u8 status;	
   	NRF24L01_CSN=0;
  	status =SPI1_ReadWriteByte(reg);
  	SPI1_ReadWriteByte(value); 
  	NRF24L01_CSN=1;  
  	return(status); 
} 

u8 NRF24L01_Read_Reg(u8 reg)
{
	u8 reg_val;	    
 	NRF24L01_CSN = 0;   	
  	SPI1_ReadWriteByte(reg);  
  	reg_val=SPI1_ReadWriteByte(0XFF);
  	NRF24L01_CSN = 1;       
  	return(reg_val);
}	

u8 NRF24L01_Read_Buf(u8 reg,u8 *pBuf,u8 len)
{
	u8 status,u8_ctr;	 
  	NRF24L01_CSN = 0;
  	status=SPI1_ReadWriteByte(reg);
 	for(u8_ctr=0;u8_ctr<len;u8_ctr++)pBuf[u8_ctr]=SPI1_ReadWriteByte(0XFF);
  	NRF24L01_CSN=1; 
  	return status; 
}

u8 NRF24L01_Write_Buf(u8 reg, u8 *pBuf, u8 len)
{
	u8 status,u8_ctr;	    
 	NRF24L01_CSN = 0;
  	status = SPI1_ReadWriteByte(reg);
  	for(u8_ctr=0; u8_ctr<len; u8_ctr++)SPI1_ReadWriteByte(*pBuf++);
  	NRF24L01_CSN = 1; 
  	return status;
}		

u8 NRF24L01_TxPacket(u8 *txbuf)
{
	u8 sta;
 	SPI1_SetSpeed(SPI_BaudRatePrescaler_8);
	NRF24L01_CE=0;
  NRF24L01_Write_Buf(WR_TX_PLOAD,txbuf,TX_PLOAD_WIDTH);
 	NRF24L01_CE=1;
	while(NRF24L01_IRQ!=0);
	sta=NRF24L01_Read_Reg(STATUS);
	NRF24L01_Write_Reg(NRF_WRITE_REG+STATUS,sta);
	if(sta&MAX_TX)
	{
		NRF24L01_Write_Reg(FLUSH_TX,0xff);
		return MAX_TX; 
	}
	if(sta&TX_OK)
	{
		return TX_OK;
	}
	return 0xff;
}

u8 NRF24L01_RxPacket(u8 *rxbuf)
{
	u8 sta;		    							   
	SPI1_SetSpeed(SPI_BaudRatePrescaler_8);
	sta=NRF24L01_Read_Reg(STATUS);  
	NRF24L01_Write_Reg(NRF_WRITE_REG+STATUS,sta);
	if(sta&RX_OK)
	{
		NRF24L01_Read_Buf(RD_RX_PLOAD,rxbuf,RX_PLOAD_WIDTH);
		NRF24L01_Write_Reg(FLUSH_RX,0xff);
		return 0; 
	}	   
	return 1;
}	

void NRF24L01_RX_Mode(void)
{
	NRF24L01_CE=0;	  
  	NRF24L01_Write_Buf(NRF_WRITE_REG+RX_ADDR_P0,(u8*)RX_ADDRESS,RX_ADR_WIDTH);  
  	NRF24L01_Write_Reg(NRF_WRITE_REG+EN_AA,0x01); 
  	NRF24L01_Write_Reg(NRF_WRITE_REG+EN_RXADDR,0x01); 
  	NRF24L01_Write_Reg(NRF_WRITE_REG+RF_CH,40);	
  	NRF24L01_Write_Reg(NRF_WRITE_REG+RX_PW_P0,RX_PLOAD_WIDTH);    
  	NRF24L01_Write_Reg(NRF_WRITE_REG+RF_SETUP,0x0f);
  	NRF24L01_Write_Reg(NRF_WRITE_REG+CONFIG, 0x0f);
  	NRF24L01_CE = 1; 
}	

void NRF24L01_TX_Mode(void)
{														 
	NRF24L01_CE=0;	    
  	NRF24L01_Write_Buf(NRF_WRITE_REG+TX_ADDR,(u8*)TX_ADDRESS,TX_ADR_WIDTH);
  	NRF24L01_Write_Buf(NRF_WRITE_REG+RX_ADDR_P0,(u8*)RX_ADDRESS,RX_ADR_WIDTH);	  
  	NRF24L01_Write_Reg(NRF_WRITE_REG+EN_AA,0x01); 
  	NRF24L01_Write_Reg(NRF_WRITE_REG+EN_RXADDR,0x01);
  	NRF24L01_Write_Reg(NRF_WRITE_REG+SETUP_RETR,0x1a);
  	NRF24L01_Write_Reg(NRF_WRITE_REG+RF_CH,40); 
  	NRF24L01_Write_Reg(NRF_WRITE_REG+RF_SETUP,0x0f); 
  	NRF24L01_Write_Reg(NRF_WRITE_REG+CONFIG,0x0e);
	NRF24L01_CE=1;
}

