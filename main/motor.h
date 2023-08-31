#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>

const int FULLSTEP = 800; //Hardware specific
const int DELAY = 500;

const int pulsePinX = 3;
const int dirPinX = 6;
const int enaPinX = 9;

const int pulsePinY = 2;
const int dirPinY = 5;
const int enaPinY = 8;

/**
* Struct containing fields for pins needed by a steppermotor.
*/
struct Motor {
  int pulse;
  int dir;
  int ena;
};

/**
* Enum containing the axis's a motor can move the magnet over.
*/
enum MotorAxis {
  X,
  Y,
};

/**
* All directions the motors can move the magnet in.
*/
enum Directions {
  UP = 0,          // MOTORY.dir = low
  RIGHT = 1,       // MOTORX.dir = low
  LEFT = 2,        // MOTORX.dir = high
  DOWN = 3,        //  MOTORY.dir = high
  UP_RIGHT = 4,    //  MOTORY.dir = low && MOTORX.dir = low
  UP_LEFT = 5,     //  MOTORY.dir = low && MOTORX.dir = high
  DOWN_RIGHT = 6,  //  MOTORY.dir = high && MOTORX.dir = low
  DOWN_LEFT = 7,   //  MOTORY.dir = high && MOTORX.dir = high
};

const Motor MOTORX = { pulsePinX, dirPinX, enaPinX };
const Motor MOTORY = { pulsePinY, dirPinY, enaPinY };

/**
* \brief Initializes all (in this case 2) motors.
*/
void motorSetup();
/**
* \brief Initializes a steppermotor on the given axis.
* @param axis The axis over which the motor will move the magnet. 
*/
void initMotor(enum MotorAxis axis);
/**
* \brief Instructs a specific motor to move the magnet in a direction.
* @param dir The direction, should be UP, RIGHT, DOWN or LEFT.
* @param steps The number of steps the steppermotor will perform.
*/
void moveMotorStraight(enum Directions dir, int steps);
/**
*
*/
void moveMotorDiagonal(enum Directions dir, int steps);
/**
* \brief Instructs 2 motors to move the magnet in a diagonal direction.
* @param dir The direction, should be UP_RIGHT, DOWN_RIGHT, DOWN_LEFT or UP_LEFT.
* @param steps The number of steps the steppermotor will perform.
*/
void moveMotors(enum Directions direction, int steps);


#endif /* MOTOR_H */
