#include "stm32f10x.h"
#include "Driver_GPIO.h"

void MyGPIO_Init (GPIO_TypeDef * GPIO, char GPIO_Pin, char GPIO_Conf){
	if (GPIO_Pin < 8){
		GPIO->CRL &= ~((unsigned int)0xF << (unsigned int)GPIO_Pin*4);
		if (GPIO_Conf == In_PullDown){
			GPIO->CRL |= (((unsigned int)GPIO_Conf + 1)<< ((unsigned int)GPIO_Pin*4));
			GPIO->ODR &= ~(0x1 << (unsigned int)GPIO_Pin);
		}
		else if (GPIO_Conf == In_PullUp){
			GPIO->CRL |= ((unsigned int)GPIO_Conf << ((unsigned int)GPIO_Pin*4));
			GPIO->ODR |= (0x1 << (unsigned int)GPIO_Pin);
		}
		else{
			GPIO->CRL |= ((unsigned int)GPIO_Conf << ((unsigned int)GPIO_Pin*4));
		}
	}
	else{
		GPIO->CRH &= ~((unsigned int)0xF << (unsigned int)GPIO_Pin*4);
		if (GPIO_Conf == In_PullDown){
			GPIO->CRH |= (((unsigned int)GPIO_Conf + 1)<< ((unsigned int)GPIO_Pin*4));
			GPIO->ODR &= ~(0x1 << (unsigned int)GPIO_Pin);
		}
		else if (GPIO_Conf == In_PullUp){
			GPIO->CRH |= ((unsigned int)GPIO_Conf << ((unsigned int)GPIO_Pin*4));
			GPIO->ODR |= (0x1 << (unsigned int)GPIO_Pin);
		}
		else{
			GPIO->CRH |= ((unsigned int)GPIO_Conf << ((unsigned int)GPIO_Pin*4));
		}
	}
}
