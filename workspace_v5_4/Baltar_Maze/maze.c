/*
 * maze.c
 *
 *  Created on: Dec 10, 2013
 *      Author: C15Catherine.Baltar
 */

#include "maze.h"
#include "sensor.h"
#include "motor.h"

void move()
{
	if (lookLeft()==1)
	{
		smallRight();
		forward();
	}

	else if (lookLeft() == 0 )
	{
		smallForward();
		smallLeft();
		smallForward();
	}

	else if ((lookLeft() == 1) & (lookCenter() == 1))
	{
		backwards();
		__delay_cycles(10000);
		bigRight();
		forward();
		forward();
	}

	else if ((lookLeft() == 0)&(lookCenter()==0))
	{
		smallLeft();
		forward();
	}

	else if ((lookRight() == 1) & (lookCenter() == 1))
	{
		bigLeft();
		bigLeft();
	}

	else if (lookRight() == 1)
	{
		smallLeft();
		forward();
	}

	else if ((lookCenter() == 1))
	{
		backwards();
		__delay_cycles(10000);
		bigRight();
		forward();
		forward();
	}

	else
	{
		forward();
	}
}
