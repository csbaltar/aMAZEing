/*
 * motor.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Catherine.Baltar
 */

#include <msp430.h>
#include "motor.h"

void initMotor()
{
	TACTL &= ~MC1|MC0;            // stop timer A0
	TA1CTL &= ~MC1|MC0;

	TACTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;

	TACTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;

	TACCR0 = 50;                // set signal period to 100 clock cycles (~100 microseconds)
	TACCR1 = 25;

	TA1CCR0 = 50;                // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR1 = 25;

	TA0CCTL1 |= OUTMOD_7;
	TA1CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

	TACTL |= MC0;                // count up
	TA1CTL |= MC0;
}

void forward()
{
	TACCR1 = 20;

	P1DIR |= BIT2|BIT6;			//set pins to output
	P1SEL |= BIT2|BIT6;

	P1SEL &= ~BIT5;
	P1SEL &= ~BIT1;

	__delay_cycles(10000);
}

void smallForward()
{
	TACCR1 = 20;

	P1DIR &= ~BIT1|BIT5;
	P1DIR |= BIT2|BIT6;			//set pins to output
	P1SEL |= BIT2|BIT6;

	P1SEL &= ~BIT5;
	P1SEL &= ~BIT1;

	__delay_cycles(125);
}


void stop()
{
	P1SEL &= ~BIT6;
	P1SEL &= ~BIT2;
	P1SEL &= ~BIT5;
	P1SEL &= ~BIT1;

	__delay_cycles(100000);
}

void backwards()
{
	TACCR1 = 20;
	TA1CCR1 = 20;

	P1DIR &= ~BIT2|BIT6;
	P1DIR |= BIT1|BIT5;			//set pins to output
	P1SEL |= BIT1|BIT5;

	P1SEL &= ~BIT6;
	P1SEL &= ~BIT2;

	__delay_cycles(250);
}

void bigLeft()
{
	TACCR1 = 20;

	P1SEL |= BIT1|BIT2;
	P1SEL &= ~BIT6;
	P1SEL &= ~BIT5;

	__delay_cycles(50000);
}

void smallLeft()
{
	TACCR1 = 20;

	P1SEL |= BIT1|BIT2;
	P1SEL &= ~BIT6;
	P1SEL &= ~BIT5;

	__delay_cycles(9000);
}

void bigRight()
{
	TACCR1 = 20;

	P1SEL |= BIT5|BIT6;
	P1SEL &= ~BIT1;
	P1SEL &= ~BIT2;

	__delay_cycles(450000);
}

void smallRight()
{
	TACCR1 = 20;

	P1SEL |= BIT5|BIT6;
	P1SEL &= ~BIT1;
	P1SEL &= ~BIT2;

	__delay_cycles(20000);
}
