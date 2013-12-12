#include <msp430.h> 
#include "motor.h"
#include "sensor.h"
#include "maze.h"


/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    //set up motor

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

    //set up sensors

    ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
    ADC10CTL1 = INCH_4;                       // input A4
    ADC10AE0 |= BIT4;                         // PA.1 ADC option select
    ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
    ADC10CTL1 |= ADC10DIV1|ADC10DIV0|ADC10DIV2;
                                // Set P1.0 to output direction

    while(1)
    {
    	lookLeft();

    	lookRight();

    	lookCenter();

    	checkLeft();

    	leftAndCenter();

    	checkRight();
    }

	
	return 0;
}
