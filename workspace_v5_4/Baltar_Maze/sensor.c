/*
 * sensor.c
 *
 *  Created on: Dec 3, 2013
 *      Author: C15Catherine.Baltar
 */


#include <msp430.h>
#include "sensor.h"

void initSensors()
{
    ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
    ADC10CTL1 = INCH_4;                       // input A4
    ADC10AE0 |= BIT4;                         // PA.1 ADC option select
    ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
    ADC10CTL1 |= ADC10DIV1|ADC10DIV0|ADC10DIV2;
                                // Set P1.0 to output direction

}

int lookLeft()
{
	  ADC10CTL0 &= ~ENC; 				// clear enable to change input pin
	  ADC10CTL1 &= ~(INCH_7|INCH_3|INCH_2|INCH_1|INCH_0);
	  ADC10CTL1 |= INCH_4;
	  ADC10AE0|=BIT4;

	 ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	 __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	 if (ADC10MEM < 0x370)
	 {
		return (0);
	 }

	 else
	 {
		 return 1;
	 }

}

int lookCenter()
{
	  ADC10CTL0 &= ~ENC; 					// clear enable to change input pin
	  ADC10CTL1 &= ~(INCH_7|INCH_4|INCH_2|INCH_1|INCH_0);
	  ADC10CTL1 |= INCH_3;                       // input A7

	 ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	 __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	 if (ADC10MEM < 0x3d0)
	 {
		return 0;
	 }

	 else
	 {
	   return 1;
	 }
}

int lookRight()
{
	  ADC10CTL0 &= ~ENC; 					// clear enable to change input pin
	  ADC10CTL1 &= ~(INCH_4|INCH_3|INCH_2|INCH_1|INCH_0);
	  ADC10CTL1 |= INCH_7;                       // input A7

	 ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	 __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	 if (ADC10MEM < 0x3d0)
	 {
		return 0;
	 }

	 else
	 {
	   return 1;
	 }
}


// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

