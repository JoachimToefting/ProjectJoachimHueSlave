/*
* timer.c
*
* Created: 08/12/2020 12.29.06
*  Author: Joachim
*/
#include <avr/io.h>

void Timer_Init(void){
	
	//Timer1
	//Waveform Generation mode bit (Table 15-5) set to: Fast PWM, 8-bit
	TCCR1A |= (1<<WGM10);
	TCCR1B |= (1<<WGM12);
	
	//Compare Output Mode (Table 15-3) set to: non-inverting mode
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1);
	
	//Clock Select Bit (Table 15-6) set to: clk_io/64 prescaler
	TCCR1B |= (1<<CS11) | (1<<CS10);
	
	
	
	//Timer2
	//Waveform Generation mode bit (Table 17-8) set to: Fast PWM, 8-bit
	TCCR2A |= (1<<WGM20);
	TCCR2B |= (1<<WGM22);
	
	//Compare Output Mode (Table 17-3) set to: non-inverting mode
	TCCR2A |= (1<<COM2A1);
	
	//Clock Select Bit (Table 17-9) set to: clk_io/64 prescaler
	TCCR2B |= (1<<CS21) | (1<<CS20);
}