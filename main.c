/*
 * ProjectJoachimHueSlave.c
 *
 * Created: 08/12/2020 08.58.49
 * Author : Joachim
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	
	DDRB |= (1<<PORTB5);
	
	
	
    while (1) 
    {
		PINB |= (1<<PORTB5);
		_delay_ms(1000);
    }
}

