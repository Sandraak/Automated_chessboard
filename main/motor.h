#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>

const int FULLSTEP = 800;
const int DELAY = 500;

const int pulsePinX = 3;
const int dirPinX = 6;
const int enaPinX = 9;

const int pulsePinY = 2;
const int dirPinY = 5;
const int enaPinY = 8;

struct Motor {
  int pulse;
  int dir;
  int ena;
};

enum MotorAxis {
  X,
  Y,
};

enum Directions {
  UP,          // MOTORY.dir = low
  RIGHT,       // MOTORX.dir = low
  LEFT,        // MOTORX.dir = high
  DOWN,        //  MOTORY.dir = high
  UP_RIGHT,    //  MOTORY.dir = low && MOTORX.dir = low
  UP_LEFT,     //  MOTORY.dir = low && MOTORX.dir = high
  DOWN_RIGHT,  //  MOTORY.dir = high && MOTORX.dir = low
  DOWN_LEFT,   //  MOTORY.dir = high && MOTORX.dir = high
};

const Motor MOTORX = { pulsePinX, dirPinX, enaPinX };
const Motor MOTORY = { pulsePinY, dirPinY, enaPinY };


void initMotor(enum MotorAxis axis);
void moveMotorStraight(enum Directions dir, int steps);
void moveMotorDiagonal(enum Directions dir, int steps);
void moveMotors(enum Directions direction,int steps);


#endif /* MOTOR_H */
