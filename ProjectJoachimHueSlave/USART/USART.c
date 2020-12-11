/*
 * USART.c
 *
 * Created: 08/12/2020 12.55.04
 *  Author: Joachim
 */ 
#include "USART.h"
#include <avr/io.h>
#include <util/setbaud.h>

void USART_Init(void){
	UBRR0H = UBRRH_VALUE;					// set UART0 baud rate with setbaud-library
	UBRR0L = UBRRL_VALUE;

	UCSR0B = (1<<RXEN0) | (1<<TXEN0);		// Enable Receiver and Transmitter (19.10.3)
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);		// Set frame format: 8 bit data, 1 stop bit (19.10.4) og Table 19-7
}

unsigned char USART_Receive(void)
{
	while (	!(UCSR0A & (1<<RXC0)));			// Wait for data to be received (19.10.2)
	return UDR0;							// Get and return received data from buffer
}