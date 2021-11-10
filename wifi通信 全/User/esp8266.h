#ifndef __ESP8266_H
#define	__ESP8266_H

#include "stm32f10x.h"

#define   AT          "AT\r\n"	
#define   CWMODE      "AT+CWMODE=1\r\n"
#define   RST         "AT+RST\r\n"
//#define   CIFSR       "AT+CIFSR\r\n"
#define   CWJAP       "AT+CWJAP=\"xinhao406\",\"xinhao@@2\"\r\n"
#define   CIPSTART    "AT+CIPSTART=\"TCP\",\"122.114.122.174\",40204\r\n"
#define   CIPMODE     "AT+CIPMODE=1\r\n"
#define   CIPMUX  "AT+CIPMUX=0\r\n"
#define   CIPSEND     "AT+CIPSEND\r\n"
#define   CIPSTATUS   "AT+CIPSTATUS\r\n"

void Esp8266_Config(void);
void SendCmd(char* cmd, char* result, int timeOut);
int ESP8266_CheckStatus(int timeOut);
#endif 
