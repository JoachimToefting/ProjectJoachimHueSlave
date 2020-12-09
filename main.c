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

unsigned char color[9];
unsigned char directColor[3];

int main(void)
{
	Init();
	
	while (1)
	{
		ReciveData();
		OCR1A = directColor[0];		// Red
		OCR1B = directColor[1];		// Green
		OCR0A = directColor[2];		// Blue
	}
}

void Init(void){
	//output på PORTB bit 1,2 og PORTD bit 6
	DDRB |= (1<<PORTB1) | (1<<PORTB2);
	DDRD |= (1<<PORTD6);
	Timer_Init();
	USART_Init();
}
void ReciveData(void){
	while (1)
	{
		unsigned char tmpChar = USART_Receive();
		switch (tmpChar)
		{
			case 'S':
			RecieveColor();
			ColorCalculator();
			return;
			break;
			
			default:
			break;
		}
	}
}
void RecieveColor(void){
	for (char cnt = 0; cnt < 9; cnt++)
	{
		color[cnt] = USART_Receive();
	}
}
void ColorCalculator(void){
	
	for (char cnt = 0; cnt < 3; cnt++)
	{
		directColor[cnt] = ((color[0+cnt*3]-48)*100)+((color[1+cnt*3]-48)*10)+(color[2+cnt*3]-48);
	}
}
