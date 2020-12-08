/*
 * USART.h
 *
 * Created: 08/12/2020 12.57.14
 *  Author: Joachim
 */ 


#ifndef USART_H_
#define USART_H_

#define F_CPU 16000000UL
#define BAUD 9600
#define BAUD_TOL 2

void USART_Init(void);

#endif /* USART_H_ */