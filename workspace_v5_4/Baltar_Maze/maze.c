/*
 * maze.c
 *
 *  Created on: Dec 10, 2013
 *      Author: C15Catherine.Baltar
 */

#include "maze.h"
#include "sensor.h"
#include "motor.h"

void checkLeft()
{
	if (lookLeft() == 1)
		{
			stop();
			smallRight();
			stop();
			forward();
		}

	else if (lookLeft()==0)
	{
		bigLeft();
		stop();
		forward();
	}
	else
	{
		forward();
	}
}

void leftAndCenter()
{
	if ((lookLeft() == 1) & (lookCenter()==1))
	{
		stop();
		bigRight();
		stop();
		forward();
	}
	else
	{
		forward();
	}
}

void checkRight()
{
	if ((lookRight()==1))
	{
		stop();
		smallLeft();
		stop();
		forward();
	}
	else
	{
		forward();
	}
}
