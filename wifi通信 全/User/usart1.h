#ifndef __USART1_H
#define	__USART1_H

#include "stm32f10x.h"
#include <stdio.h>



void USART1_Config(void);
int fputc(int ch, FILE *f);
void USART_SendBit(u8 p[],int sum);
void usart1_write(USART_TypeDef* USARTx, uint8_t *Data,uint32_t len);

#endif 
