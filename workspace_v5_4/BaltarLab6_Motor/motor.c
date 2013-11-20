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
	TACCR1 = 50;
	__delay_cycles(100);
}

void stop()
{
	P1SEL |= BIT6|BIT2;
	TACCTL1 &= ~OUTMOD_7;
	TACCTL1 |= OUTMOD_5;
	__delay_cycles(100);
}

void backwards()
{
	TACCR1 = 50;
	P1OUT &= ~BIT0|BIT2;
	P1OUT |= BIT1|BIT3;
}

