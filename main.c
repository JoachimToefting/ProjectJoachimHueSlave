/*
 * ProjectJoachimHueSlave.c
 *
 * Created: 08/12/2020 08.58.49
 * Author : Joachim
 */ 
#include "main.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Timer/timer.h"
#include "USART/USART.h"


int main(void)
{
	Init();
	
    while (1) 
    {
		OCR1A = 127;
		OCR1B = 127;
		OCR2A = 127;
		_delay_ms(1000);
		OCR1A = 255;
		OCR1B = 69;
		OCR2A = 0;
		_delay_ms(1000);
		OCR1A = 0;
		OCR1B = 0;
		OCR2A = 255;
		_delay_ms(1000);
    }
}

void Init(void){
	//output on PORTB bit 1,2,3
	DDRB |= (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3);
	Timer_Init();
}
