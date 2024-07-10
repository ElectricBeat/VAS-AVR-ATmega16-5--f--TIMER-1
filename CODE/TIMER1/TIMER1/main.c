/*
 * TIMER1.c
 *
 * Created: 09-07-2024 17:06:27
 * Author : SRIDHAR
 */ 

#include <avr/io.h>

void T1delay();

int main(void)
{
	DDRB	=	0xFF;				/* PORTB as output */
	PORTB	=	0x00;

	while(1)  						/* Repeat forever */
	{
		PORTB	=	~PORTB;
		T1delay();
	}
}

void T1delay()
{
//	TCCR1A = 0X00;					/* Timer1, normal mode,  */
	TCCR1B = (1<<CS12) | (1<<CS10);	/* 1024 prescalar */
	OCR1A = 10;
	TCNT1 = 0;						/* Load TCNT1, count for 10ms */
	while((TIFR & 0x10)==0);		/* Wait for OCF1A to roll over */
//	TCCR1A = 0;
	TCNT1 = 0;						/* Load TCNT1, count for 10ms */
	TIFR |= 0x04;					/* Clear OCF1A flag */
}