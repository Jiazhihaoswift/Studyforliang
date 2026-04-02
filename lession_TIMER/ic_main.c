#include "stm32f4xx.h"
#include "delay.h"
#include "myiic.h"
#include "oled.h"
#include "IC.h"
#include "PWM.h"

volatile uint16_t Num = 0;

uint16_t i;
uint8_t Fre;

int main(void)
{
		delay_init(168);
 
		PWM_Init();
		IIC_Init();
		OLED_Init();
	
	
		OLED_ShowString(1,1,(uint8_t*) "Freq:00000Hz",16);
	
		PWM_SetPrescaler(840-1);  //Frea = 84M / (PSC + 1) / 100
		PWM_SetComparel(50);			//Duty = CCR / 100
			
    while(1)
		{
		
			OLED_ShowNum(1,6,IC_GetFreq(),5,16);
			OLED_Refresh();
			
		}
}
