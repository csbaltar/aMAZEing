#include <msp430.h> 
#include "motor.h"
#include "sensor.h"
#include "maze.h"


/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    initMotor();				//set up motor

    initSensors();				//set up sensors

    while(1)
    {
    	lookCenter();

    	lookLeft();

    	lookRight();

    	move();
    }

	
	return 0;
}
