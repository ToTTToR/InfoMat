#include "MyTimer.h"

void MyTimer_Base_Init (TIM_TypeDef* Timer, unsigned shortARR, unsigned shortPSC){
	Timer->ARR = shortARR;
	Timer->PSC = shortPSC;
	Timer->CR1 |= 1;
}

void MyTimer_Base_Start (TIM_TypeDef* Timer){
	Timer->CR1 |= 1;
}

void MyTimer_Base_Stop (TIM_TypeDef* Timer){
	Timer->CR1 &= ~1;
}

void MyTimer_ActiveIT (TIM_TypeDef* Timer ,char Prio ){
	Timer->DIER |= 1;
	//NVIC->ISER
}