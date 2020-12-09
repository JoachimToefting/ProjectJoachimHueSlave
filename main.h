/*
 * main.h
 *
 * Created: 08/12/2020 12.27.18
 *  Author: Joachim
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL

unsigned char* ColorCalculator(char *p_fullcolor);
unsigned char* RecieveColor(void);
void ReciveData(void);
void Init(void);

#endif /* MAIN_H_ */