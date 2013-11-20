#include <msp430.h> 
#include "motor.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

       P1DIR |= BIT6|BIT2;			//set pins to output
       P1SEL |= BIT6|BIT2;           // TA0CCR1 on pin 2 and p

       TACTL &= ~MC1|MC0;            // stop timer A0

       TACTL |= TACLR;                // clear timer A0

       TACTL |= TASSEL1;           // configure for SMCLK

       TACCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
       TACCR1 = 60;



       TACCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

       TACTL |= MC0;                // count up


       while(1){
	//	  forward();

		//  stop();

		 // __delay_cycles(1000000);
		 // backwards();
}
	
	return 0;
}
