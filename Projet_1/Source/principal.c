#include "stm32f10x.h"
#include "../Drivers/MyTimer.h"

int main(void)
	{
		//TP1
		
		/*int led_allumee; // = 1 si la led doit s'allumer, 0 sinon
		RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
		//Configuration PA5 (LED) mode output push pull
		GPIOA->CRL &= ~(0xF << 20);
		GPIOA->CRL |= (1 << 20);
		//Configuration PA5 (LED) mode output open drain
		//GPIOA->CRL |= (1 << 22);
		//Configuration PC13 (Push button) mode floating input
		GPIOC->CRH &= ~(0xF << 20);
		GPIOC->CRH |= (1 << 22);
		
		while(1){
			led_allumee = 0;
			led_allumee |= (1 << 13);
			led_allumee &= GPIOC->IDR;
			if (led_allumee>>13){
				GPIOA->ODR |= (1<<5);
			}
			else{
				GPIOA->ODR &= ~(1<<5);
			}
		}*/
		
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
