#include "stm32f10x.h"
#include "../Drivers/MyTimer.h"
#include "../Drivers/Driver_GPIO.h"
#include "../Drivers/Driver_ADC.h"

void Callback(){
	MyGPIO_Toggle(GPIOA,5) ;
}

int main(void)
	{	
		/*MyTimer_Base_Init(TIM1, 4999, 7199);
		MyTimer_ActiveIT(TIM1,1,Callback);
		MyTimer_Base_Start (TIM1);
		
		MyTimer_Base_Init(TIM2, 4999, 7199);
		MyTimer_ActiveIT(TIM2,8,Callback);
		MyTimer_Base_Start (TIM2);
		
		MyTimer_Base_Init(TIM3, 4999, 7199);
		MyTimer_ActiveIT(TIM3,3,Callback);
		MyTimer_Base_Start (TIM3);
		
		MyTimer_Base_Init(TIM4, 4999, 7199);
		MyTimer_ActiveIT(TIM4,7,Callback);	
		MyTimer_Base_Start (TIM4);
		
		MyGPIO_Init (GPIOA, 5, Out_Ppull);
		*/
		/*MyTimer_Base_Init(TIM4, 719,0);
		MyTimer_PWM(TIM4,1) ;
		Set_PWM_CycleRate(TIM4,1,20.0);
		MyTimer_Base_Start(TIM4);
		MyGPIO_Init (GPIOA, 5, Out_Ppull);*/
		
		
		while(1){
			
		}
	}
