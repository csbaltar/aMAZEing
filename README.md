Lab7_Sensors
============
Functions

void lookLeft();
  detects signals from left sensor through input A4. Sends signal through P1.0 to light up the left LED. Turns on when the robot is a inch away from the wall.  Clears the enable bit first and then sets the input then sets the enable again for exectuion.
  
void lookRight();
  same as lookLeft() but for the right sensor.  Uses input A7 and P1.6 to light up the LED.  Same distance (1 inch). 
