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
	P1OUT |= BIT0|BIT2;
	P1OUT &= ~BIT1|BIT3;
}

void backwards()
{
	TACCR1 = 50;
	P1OUT &= ~BIT0|BIT2;
	P1OUT |= BIT1|BIT3;
}

