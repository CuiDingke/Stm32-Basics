#include "stm32f10x.h"
#include "lcd.h"
#include "bsp_adc.h"
#include "stdio.h"
#include "key.h" 
int a=30,b=50,c=70;
u32 TimingDelay = 0;
extern __IO uint16_t ADC_ConvertedValue[1];
void Delay_Ms(u32 nTime);
float Information,informa;
char A[50],B[50];

uint8_t  i=0,j=0;
int main(void)
{
	SysTick_Config(SystemCoreClock/1000);
	Delay_Ms(200);
	ADC1_Init();
	Key_GPIO_Config();
	STM3210B_LCD_Init();
	LCD_Clear(Blue);
	LCD_SetBackColor(Blue);
	LCD_SetTextColor(Black);
	while(1)
	{
		if(i==0||i==2)
		{
			j=1;
		  LCD_SetTextColor(Black);
	  	sprintf (A,"     Liquid Level   "    );
      LCD_DisplayStringLine(Line1,(unsigned char* )A);
		
      Information=ADC_ConvertedValue[0]*3.3/4096;
		  sprintf (A,"   ADC    :%.2fV   ",Information);
      LCD_DisplayStringLine(Line5,(unsigned char* )A);

		  informa=ADC_ConvertedValue[0]*101/4096;
		  sprintf (A,"   Height :%.0fcm    ",informa);
      LCD_DisplayStringLine(Line3,(unsigned char* )A);
      i=0;
    if(informa<=10)
    {
      sprintf (A,"   Level  :0");
	    LCD_SetBackColor(White);	
      LCD_DisplayStringLine(Line7,(unsigned char* )A);
      Delay_Ms(1000);
    }
    if(informa>10&&informa<=20)
    {
      sprintf (A,"   Level  :1");
      LCD_DisplayStringLine(Line7,(unsigned char* )A);
      Delay_Ms	(1000);
	  }
    if(informa>20&&informa<=30)
    {
      sprintf (A,"   Level  :2");	
      LCD_DisplayStringLine(Line7,(unsigned char* )A);
      Delay_Ms	(1000);
	  }
	
	  if(informa>30&&informa<=100)
   {
    sprintf (A,"   Level  :3       ");
    LCD_DisplayStringLine(Line7,(unsigned char* )A);
    Delay_Ms	(1000);
	 }
   }
if (Key_Scan(GPIOA,GPIO_Pin_0)==0)
{
	  j=0; i++;
	  LCD_SetTextColor(Black);
	  sprintf (B,"   Parameter Setup ");	
    LCD_DisplayStringLine(Line1,(unsigned char* )B);

	  sprintf (B," Threshold1 : %dcm",a);
    LCD_DisplayStringLine(Line3,(unsigned char* )B);

    sprintf (B," Threshold2 : %dcm",b);	
    LCD_DisplayStringLine(Line5,(unsigned char* )B);
	
	  sprintf (B," Threshold3 : %dcm",c);
    LCD_DisplayStringLine(Line7,(unsigned char* )B);
	 
}
if(j==0&&Key_Scan(GPIOA,GPIO_Pin_8)==0)
{
 j=j+1;
while  (j==1)
	  {
			  if(Key_Scan(GPIOB,GPIO_Pin_1)==0)
        {
            if(a>=5&&a<=95) a=a+5;
	          if(a<=5)a=5;
	          if(a>=95)a=95;
         }
        if(Key_Scan(GPIOB,GPIO_Pin_2)==0)
        {
             if(a>=5&&a<=95) a=a-5;
	           if(a<=5)a=5;
	           if(a>=95)a=95;
         }
		
	  sprintf (B,"   Parameter Setup ");
		LCD_SetTextColor(Black);
    LCD_DisplayStringLine(Line1,(unsigned char* )B);

    sprintf (B," Threshold2 : %dcm ",b);
		LCD_SetTextColor(Black);
    LCD_DisplayStringLine(Line5,(unsigned char* )B);
	
	  sprintf (B," Threshold3 : %dcm ",c);
		LCD_SetTextColor(Black);
    LCD_DisplayStringLine(Line7,(unsigned char* )B);
		
		sprintf (B," Threshold1 : %dcm ",a);
		LCD_SetTextColor(Red);
    LCD_DisplayStringLine(Line3,(unsigned char* )B);
    if(Key_Scan(GPIOA,GPIO_Pin_8)==0)j++;
				 if (Key_Scan(GPIOA,GPIO_Pin_0)==0)
				 {
				 j=j+5;i=2;
				 }
		
	 }
	
	
 while(j==2)
	  {
		  if(Key_Scan(GPIOB,GPIO_Pin_1)==0)
      {
        if(b>=5&&b<=95) b=b+5;
	      if(b<=5)b=5;
	      if(b>=95)b=95;
       }
      if(Key_Scan(GPIOB,GPIO_Pin_2)==0)
      {
        if(b>=5&&b<=95) b=b-5;
	      if(b<=5)b=5;
	      if(b>=95)b=95;
      }
		
	  sprintf (B,"   Parameter Setup ");
		LCD_SetTextColor(Black);
    LCD_DisplayStringLine(Line1,(unsigned char* )B);
		
    sprintf (B," Threshold1 : %dcm ",a);
		LCD_SetTextColor(Black);
    LCD_DisplayStringLine(Line3,(unsigned char* )B);
    
	  sprintf (B," Threshold3 : %dcm ",c);
		LCD_SetTextColor(Black);
    LCD_DisplayStringLine(Line7,(unsigned char* )B);
		
		sprintf (B," Threshold2 : %dcm ",b);
				LCD_SetTextColor(Red);
    LCD_DisplayStringLine(Line5,(unsigned char* )B);
if(Key_Scan(GPIOA,GPIO_Pin_8)==0)j++;
			if (Key_Scan(GPIOA,GPIO_Pin_0)==0)
				 {
				 j=j+5;i=2;
				 }
}


 while(j==3)
	  {
		  if(Key_Scan(GPIOB,GPIO_Pin_1)==0)
      {
        if(c>=5&&c<=95) c=c+5;
	      if(c<=5)c=5;
	      if(c>=95)c=95;
       }
      if(Key_Scan(GPIOB,GPIO_Pin_2)==0)
      {
        if(c>=5&&a<=95) c=c-5;
	      if(c<=5)c=5;
	      if(c>=95)c=95;
       }
		
	  sprintf (B,"   Parameter Setup ");
		LCD_SetTextColor(Black);
    LCD_DisplayStringLine(Line1,(unsigned char* )B);
		
    sprintf (B," Threshold1 : %dcm ",a);
		LCD_SetTextColor(Black);
    LCD_DisplayStringLine(Line3,(unsigned char* )B);
    
		sprintf (B," Threshold2 : %dcm ",b);
		LCD_SetTextColor(Black);
    LCD_DisplayStringLine(Line5,(unsigned char* )B);
		
		 sprintf (B," Threshold3 : %dcm ",c);
			LCD_SetTextColor(Red);
    LCD_DisplayStringLine(Line7,(unsigned char* )B);
   if(Key_Scan(GPIOA,GPIO_Pin_8)==0)j++;
			 if(j==4)  j=0;
			 if (Key_Scan(GPIOA,GPIO_Pin_0)==0)
				 {
				 j=j+5;i=2;
				 }
    }
	
}
}
}
void Delay_Ms(u32 nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);	
}

