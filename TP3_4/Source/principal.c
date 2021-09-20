#include "stm32f10x.h"
#include "../Drivers/MyTimer.h"

int main(void)
	{		
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
		
		/*//Parametrage TIM2 tel que Thorloge = 500ms
		TIM2->ARR = 4999;
		TIM2->PSC = 7199;
		
		//Demarrage TIM2
		TIM2->CR1 |= ( 1 << 0);*/
		
		MyTimer_Base_Init(TIM2, 4999, 7199);

		while(1){
			if (TIM2->CNT == 500){
				MyTimer_Base_Stop(TIM2);
			}
		}
	}
