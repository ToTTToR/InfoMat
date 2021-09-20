#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"

#define In_Floating 0x04 // a completer
#define In_PullDown 0x08 // a completer
#define In_PullUp 0x08 // a completer
#define In_Analog 0x00 // a completer
#define Out_Ppull 0x01 // a completer
#define Out_OD 0x05 // a completer
#define AltOut_Ppull 0x09 // a completer
#define AltOut_OD 0x0D // a completer

void MyGPIO_Init (GPIO_TypeDef * GPIO, char GPIO_Pin, char GPIO_Conf) ;
int MyGPIO_Read(GPIO_TypeDef * GPIO , char GPIO_Pin ) ; // renvoie 0 ou autre chose different de 0
void MyGPIO_Set(GPIO_TypeDef * GPIO , char GPIO_Pin ) ;
void MyGPIO_Reset(GPIO_TypeDef * GPIO , char GPIO_Pin ) ;
void MyGPIO_Toggle(GPIO_TypeDef * GPIO , char GPIO_Pin ) ;

#endif
