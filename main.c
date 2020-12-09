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

unsigned char *color;

int main(void)
{
	Init();
	
	while (1)
	{
		//ReciveData();
		//OCR1A = color[0];
		//OCR1B = color[1];
		//OCR2A = color[2];
		//PINB |= (1<<PORTB1);
		OCR1A = 0;
		OCR1B = 0;
		OCR0A = 255;
		_delay_ms(1000);
		//PINB |= (1<<PORTB2);
		OCR1A = 255;
		OCR1B = 0;
		OCR0A = 0;
		_delay_ms(1000);
		//PINB |= (1<<PORTB3);
		OCR1A = 0;
		OCR1B = 255;
		OCR0A = 0;
		_delay_ms(1000);
	}
}

void Init(void){
	//output på PORTB bit 1,2,3
	DDRB |= (1<<PORTB1) | (1<<PORTB2) ;//| (1<<PORTB3);
	DDRD |= (1<<PORTD6);
	Timer_Init();
	USART_Init();
}
void ReciveData(void){
	while (1)
	{
		unsigned char tmpChar = USART_Receive();
		if (tmpChar == 'S')
		{
			color = ColorCalculator(RecieveColor());
			return;
		}
	}
}
unsigned char* RecieveColor(void){
	unsigned char Readcolor[9];
	
	for (char cnt = 0; cnt < 9; cnt++)
	{
		Readcolor[cnt] = USART_Receive();
	}
	return color;
}
unsigned char* ColorCalculator(char *p_readColor){
	unsigned char calculatedColor[3];
	for (char cnt = 0; cnt < 3; cnt++)
	{
		calculatedColor[(cnt)] = (((*p_readColor+cnt*3)-48) * 100) + (((*(p_readColor+1+cnt*3))-48) * 10) + ((*(p_readColor+2+cnt*3))-48);	//tal værdien for en farve ascii char til int
	}
}
