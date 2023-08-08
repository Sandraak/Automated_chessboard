 #ifndef MOTOR_H
 #define MOTOR_H
 #include <Arduino.h>
const int pulsePinX = 2; 
const int dirPinX = 5; 
const int enaPinX = 8;

const int pulsePinY = 3; 
const int dirPinY = 6; 
const int enaPinY = 9;

const int FULLSTEP = 400;
const int DELAY = 500;

struct Motor{
  int pulse;
  int dir;
  int ena;
};

enum MotorAxis{
  X,
  Y,
};

enum Directions{
  UP, // MOTORY.dir = high
  RIGHT, // MOTORX.dir = low
  LEFT, // MOTORX.dir = high
  DOWN, //  MOTORY.dir = low
  UP_RIGHT,  //  MOTORY.dir = high && MOTORX.dir = low
  UP_LEFT, //  MOTORY.dir = high && MOTORX.dir = high
  DOWN_RIGHT, //  MOTORY.dir = low && MOTORX.dir = low
  DOWN_LEFT,  //  MOTORY.dir = low && MOTORX.dir = high
};

const Motor MOTORX = {pulsePinX,dirPinX,enaPinX};
const Motor MOTORY = {pulsePinY,dirPinY,enaPinY};


void initMotor(enum MotorAxis axis);
void moveMotor(enum Directions dir);
void moveMotorDiagonal(enum Directions dir);
void performMove(enum Directions direction);


 #endif /* MOTOR_H */
