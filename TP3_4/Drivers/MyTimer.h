#ifndef MYTIMER_H
#define MYTIMER_H
#include "stm32f10x.h"


	
	/*
	*****************************************************************************************
				*@brief
				*			@param-> Param�tre  sous forme d�une  structure  (son  adresse)  contenant  les informations de base
				*			@Note-> Fonction � lancer  syst�matiquement avant d�aller plus en d�tail dans les conf plus fines (PWM, codeur  inc . . . )
	*************************************************************************************************
	*/
	
void MyTimer_Base_Init (TIM_TypeDef* Timer, unsigned shortARR, unsigned shortPSC) ;
	
void MyTimer_Base_Start (TIM_TypeDef* Timer);
void MyTimer_Base_Stop (TIM_TypeDef* Timer);

/*
***************************************************************************************************
		*@brief
		*		@param : - TIM_TypeDef* Timer : Timer concerne
		- char Prio : de 0 a 15
		*@Note :   La  fonction   MyTimer_Base_Init  doit  avoir  ete  lancee au prealable
***************************************************************************************************
*/
void MyTimer_ActiveIT (TIM_TypeDef* Timer ,char Prio,void (*IT_function )(void)) ;
void TIM1_UP_IRQHandler(void);
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
	
#endif
