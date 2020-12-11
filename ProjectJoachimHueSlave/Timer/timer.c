/*
* timer.c
*
* Created: 08/12/2020 12.29.06
*  Author: Joachim
*/
#include <avr/io.h>

void Timer_Init(void){
	
	//Timer1
	//Waveform Generation mode bit (Table 15-5) set to: Fast PWM, 8-bit top 0x00FF
	TCCR1A |= (1<<WGM10);
	TCCR1B |= (1<<WGM12);
	
	//Compare Output Mode (Table 15-3) set to: non-inverting mode
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1);
	
	//Clock Select Bit (Table 15-6) set to: clk_io/64 prescaler
	TCCR1B |= (1<<CS11) | (1<<CS10);
	
	
	
	//Timer0
	//Waveform Generation mode bit (Table 14-8) set to: Fast PWM with top 0xFF
	TCCR0A |= (1<<WGM00) | (1<<WGM01);
	
	//Compare Output Mode (Table 14-3) set to: non-inverting mode
	TCCR0A |= (1<<COM0A1);
	
	//Clock Select Bit (Table 14-9) set to: clk_io/64 prescaler
	TCCR0B |= (1<<CS11) | (1<<CS10);
}