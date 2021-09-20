#include "stm32f10x.h"
#include "../Drivers/Driver_GPIO.h"

int main(void)
	{
		RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
		MyGPIO_Init (GPIOA, 5, Out_Ppull);
		MyGPIO_Init (GPIOC, 13, In_Floating);
		while(1){
			if (MyGPIO_Read(GPIOC , 13))
				MyGPIO_Set(GPIOA , 5);
			else
				MyGPIO_Reset(GPIOA, 5);
		}
	}
