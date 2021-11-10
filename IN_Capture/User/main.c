#include  "stm32f10x.h"
#include "in_capture.h"
int main(void)
{ 
  GPIO_Configuration();
	NVIC_Configuration();
  IN_Capture_Tim3();
  while (1);
}
