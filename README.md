# aMAZEing - Lab 8 Robot


## Description
  - The robot can navigate through a maze following the left wall.  
 

## Libraries
  - Maze
      - the maze library calls the movement function required for the robot using the inputs from the sensor to determine the outputs sent to the motors.
    
  - Sensor
      -The sensor library takes ann input from the sensors and returns either true if it is within the threshold or false if it is not.  Each threshold is set for the three sensors. 

  - Motor
     - The motor library sets the pins for each motor to travel in multiple directions.  
     - 

## Functions
  - `lookLeft();` - take in the input from the left sensors.
  - `lookRight();` - take in the input from the left sensor.
  - `lookCenter();`  take in the input from the center sensor.
  - `move();` - a series of if statements that takes the input from the sensors and turns it into outputs for the motors.
  - 
## Sample Code
