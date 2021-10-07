#include "Driver_ADC.h"

void ADC_Init(ADC_TypeDef * ADC, char voie){
	if(ADC==ADC1){
		RCC->APB2ENR |= (1<<9);
	}else {
		RCC->APB2ENR |= (1<<10);
	}
	ADC->CR2 |= 1;
	ADC->SQR1 |= (1<<20);
	ADC->SQR3 |= voie;
	ADC->CR2 |= (1<<2);
	while(ADC->CR2 & (1<<2)){//Recalibration
	}
}

int Start_Conv(ADC_TypeDef * ADC){
	ADC->CR2 |= 1;
	while(!(ADC->SR & 1<<1)){
		
	}
	return ADC->DR & 16;
}
