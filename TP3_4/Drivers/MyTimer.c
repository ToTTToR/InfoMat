#include "MyTimer.h"
#include "Driver_GPIO.h"

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

void MyTimer_PWM(TIM_TypeDef*Timer ,char Channel){
	
	//Configuration des pins correspondant aux channels en mode alternate push-pull
	if(Timer==TIM1){
		Timer->BDTR |= (1<<15);
		if (Channel==1){
			MyGPIO_Init (GPIOA, 8, AltOut_Ppull);
		} else if(Channel==2){
			MyGPIO_Init (GPIOA, 9, AltOut_Ppull);
		} else if(Channel==3){
			MyGPIO_Init (GPIOA, 10, AltOut_Ppull);
		} else {
			MyGPIO_Init (GPIOA, 11, AltOut_Ppull);
		}
	} else if(Timer==TIM2){
		if (Channel==1){
			MyGPIO_Init (GPIOA, 0, AltOut_Ppull);
		} else if(Channel==2){
			MyGPIO_Init (GPIOA, 1, AltOut_Ppull);
		} else if(Channel==3){
			MyGPIO_Init (GPIOA, 2, AltOut_Ppull);
		} else {
			MyGPIO_Init (GPIOA, 3, AltOut_Ppull);
		}
	} else if(Timer==TIM3){
		if (Channel==1){
			MyGPIO_Init (GPIOA, 6, AltOut_Ppull);
		} else if(Channel==2){
			MyGPIO_Init (GPIOA, 7, AltOut_Ppull);
		} else if(Channel==3){
			MyGPIO_Init (GPIOB, 0, AltOut_Ppull);
		} else {
			MyGPIO_Init (GPIOB, 1, AltOut_Ppull);
		}
	} else {
		if (Channel==1){
			MyGPIO_Init (GPIOB, 6, AltOut_Ppull);
		} else if(Channel==2){
			MyGPIO_Init (GPIOB, 7, AltOut_Ppull);
		} else if(Channel==3){
			MyGPIO_Init (GPIOB, 8, AltOut_Ppull);
		} else {
			MyGPIO_Init (GPIOB, 9, AltOut_Ppull);
		}
	}
	
	// Configuration Channel en mode PWM
	if(Channel==1){
		Timer->CCMR1 &= ~(7<<4); 
		Timer->CCMR1 |= (6<<4);
		Timer->CCER |= 1;
	} else if(Channel==2){
		Timer->CCMR1 &= ~(7<<12);
		Timer->CCMR1 |= (6<<12);
		Timer->CCER |= (1<<4);
	} else if(Channel==3){
		Timer->CCMR2 &= ~(7<<4); 
		Timer->CCMR2 |= (6<<4);
		Timer->CCER |= (1<<8);
	} else {
		Timer->CCMR2 &= ~(7<<12); 
		Timer->CCMR2 |= (6<<12);
		Timer->CCER |= (1<<12);
	}
}

void Set_PWM_CycleRate(TIM_TypeDef*Timer ,char Channel,float rate){
	int ccr_value = (int)((rate/100.0)*Timer->ARR);
	if(Channel==1){
		Timer->CCR1 = ccr_value;
	} else if(Channel==2){
		Timer->CCR2 = ccr_value;
	} else if(Channel==3){
		Timer->CCR3 = ccr_value;
	} else {
		Timer->CCR4 = ccr_value;
	}
}
