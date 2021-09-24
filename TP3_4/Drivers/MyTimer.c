#include "MyTimer.h"

void MyTimer_Base_Init (TIM_TypeDef* Timer, unsigned shortARR, unsigned shortPSC){
	if(Timer==TIM1)
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	else if(Timer==TIM2)
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	else if(Timer==TIM3)
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	else 
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	Timer->ARR = shortARR;
	Timer->PSC = shortPSC;
}

void MyTimer_Base_Start (TIM_TypeDef* Timer){
	Timer->CR1 |= 1;
}

void MyTimer_Base_Stop (TIM_TypeDef* Timer){
	Timer->CR1 &= ~1;
}

void (*pFnc1) (void);
void (*pFnc2) (void);
void (*pFnc3) (void);
void (*pFnc4) (void);

void MyTimer_ActiveIT (TIM_TypeDef* Timer ,char Prio,void (*IT_function )(void)){
	int num;
	Timer->DIER |= 1;
	if(Timer==TIM1){
		num=25;
		pFnc1 = IT_function;
	}
	else if(Timer==TIM2){
		num=28;
		pFnc2 = IT_function;
	}
	else if(Timer==TIM3){
		num=29;
		pFnc3 = IT_function;
	}
	else{
		num=30;
		pFnc4 = IT_function;
	}
	NVIC->ISER[0] |=  (1<<num);
	NVIC->IP[num] |= (Prio<<4);
}

void TIM1_UP_IRQHandler(){
	TIM1->SR &= ~(1);
	(*pFnc1)();
}

void TIM2_IRQHandler(){
	TIM2->SR &= ~(1);
	(*pFnc2)();
}

void TIM3_IRQHandler(){
	TIM3->SR &= ~(1);
	(*pFnc3)();
}

void TIM4_IRQHandler(){
	TIM4->SR &= ~(1);
	(*pFnc4)();
}
