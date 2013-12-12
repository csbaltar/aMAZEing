/*
 * sensor.c
 *
 *  Created on: Dec 3, 2013
 *      Author: C15Catherine.Baltar
 */


#include <msp430.h>
#include "sensor.h"

int lookLeft()
{
	  ADC10CTL0 &= ~ENC; 				// clear enable to change input pin
	  ADC10CTL1 = INCH_4;

	 ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	 __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	 if (ADC10MEM < 0x2fd)
	 {
		 P1DIR &= ~BIT0;
		 return (0);
		 //forward();
	 }
	                          // Clear P1.0 LED off
	 else
	 {
		 P1DIR |= BIT0;
		 return 1;

	 }

	   //stop();
	   //smallRight();                        // Set P1.0 LED on

}

int lookRight()
{
	  ADC10CTL0 &= ~ENC; 					// clear enable to change input pin
	  ADC10CTL1 = INCH_7;                       // input A7

	 ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	 __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	 if (ADC10MEM < 0x2fd)
	 {
		P1DIR &= ~BIT6;    				// Clear P1.6 LED off
		return 0;
	 }

	 else
	 {
	   P1DIR |= BIT6;                        // Set P1.6 LED on
	   return 1;
	 }
}

int lookCenter()
{
	  ADC10CTL0 &= ~ENC; 					// clear enable to change input pin
	  ADC10CTL1 = INCH_5;                       // input A7

	 ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	 __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	 if (ADC10MEM < 0x2fd)
	 {
		P1DIR &= ~BIT6|BIT0;    				// Clear P1.6 LED off
		return 0;
	 }

	 else
	 {
	   P1DIR |= BIT6|BIT0;                        // Set P1.6 LED on
	   return 1;
	 }
}
// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

