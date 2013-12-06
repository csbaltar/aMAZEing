#include <msp430.h> 
#include "motor.h"


/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer


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


       while(1){
		  forward();

		  stop();

		  backwards();

		  stop();

		 //forward();

		  smallLeft();

		  stop();

		 // forward();

		  smallRight();

		  stop();

		 // forward();

		  bigLeft();

		  stop();

		 // forward();

		  bigRight();

		  stop();
}
	
	return 0;
}
