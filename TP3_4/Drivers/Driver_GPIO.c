#include "stm32f10x.h"
#include "Driver_GPIO.h"

void MyGPIO_Init (GPIO_TypeDef * GPIO, char GPIO_Pin, char GPIO_Conf){
	if(GPIO==GPIOA)
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	else if(GPIO==GPIOB)
		RCC->APB1ENR |= RCC_APB2ENR_IOPBEN;
	else if(GPIO==GPIOC)
		RCC->APB1ENR |= RCC_APB2ENR_IOPCEN;
	else 
		RCC->APB1ENR |= RCC_APB2ENR_IOPDEN;
	if (GPIO_Pin < 8){
		GPIO->CRL &= ~((unsigned int)0xF << (unsigned int)GPIO_Pin*4);
		GPIO->CRL |= ((unsigned int)GPIO_Conf << (unsigned int)GPIO_Pin*4);
	}
	else{
		GPIO->CRH &= ~((unsigned int)0xF << (unsigned int)(GPIO_Pin-8)*4);
		GPIO->CRH |= ((unsigned int)GPIO_Conf << (unsigned int)(GPIO_Pin-8)*4);
	}
}

int MyGPIO_Read(GPIO_TypeDef * GPIO , char GPIO_Pin ){
	return GPIO->IDR & (1<<GPIO_Pin);
}

void MyGPIO_Set(GPIO_TypeDef * GPIO , char GPIO_Pin ){
	GPIO->BSRR = (1<<GPIO_Pin);
}

void MyGPIO_Reset(GPIO_TypeDef * GPIO , char GPIO_Pin ){
	GPIO->BRR = (1<<GPIO_Pin);
}

void MyGPIO_Toggle(GPIO_TypeDef * GPIO , char GPIO_Pin ){
	if (((GPIO->ODR>>GPIO_Pin) & 1) == 0)
		MyGPIO_Set(GPIO,GPIO_Pin);
	else
		MyGPIO_Reset(GPIO , GPIO_Pin);
}
