#include"stm32f10x.h"

int main(void)
	{
		//int led_allumee;
		RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
		GPIOA->CRL &= ~(0xF << 20);
		GPIOA->CRL |= (1 << 20);
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
		}
	}
