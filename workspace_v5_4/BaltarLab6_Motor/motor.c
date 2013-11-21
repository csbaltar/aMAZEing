/*
 * motor.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Catherine.Baltar
 */

#include <msp430.h>
#include "motor.h"



void forward()
{
	TACCR1 = 20;

	P1DIR |= BIT2|BIT6;			//set pins to output
	P1SEL |= BIT2|BIT6;

	P1SEL &= ~BIT5;
	P1SEL &= ~BIT1;

	__delay_cycles(1000000);
}

void shortforward()
{
	TACCR1 = 20;

	P1DIR |= BIT2|BIT6;			//set pins to output
	P1SEL |= BIT2|BIT6;

	P1SEL &= ~BIT5;
	P1SEL &= ~BIT1;

	__delay_cycles(500000);
}

void backwards()
{
	TACCR1 = 20;
	TA1CCR1 = 20;

	P1DIR |= BIT1|BIT5;			//set pins to output
	P1SEL |= BIT1|BIT5;

	P1SEL &= ~BIT6;
	P1SEL &= ~BIT2;

	__delay_cycles(1500000);
}

void bigLeft()
{
	TACCR1 = 20;

	P1SEL |= BIT1|BIT2;
	P1SEL &= ~BIT6;
	P1SEL &= ~BIT5;

	__delay_cycles(250000);
}

void smallLeft()
{
	TACCR1 = 20;

	P1SEL |= BIT1|BIT2;
	P1SEL &= ~BIT6;
	P1SEL &= ~BIT5;

	__delay_cycles(100000);
}

void bigRight()
{
	TACCR1 = 20;

	P1SEL |= BIT5|BIT6;
	P1SEL &= ~BIT1;
	P1SEL &= ~BIT2;

	__delay_cycles(250000);
}

void smallRight()
{
	TACCR1 = 20;

	P1SEL |= BIT5|BIT6;
	P1SEL &= ~BIT1;
	P1SEL &= ~BIT2;

	__delay_cycles(150000);
}
