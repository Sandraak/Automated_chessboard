#include "motor.h"

void initMotor(enum MotorAxis axis){
  Motor motor;
  switch (axis){
    case X:
    motor = MOTORX;
    break;
    case Y:
    motor = MOTORY;
    break;
    default:
    break;
  }
  pinMode(motor.pulse,OUTPUT); 
  pinMode(motor.dir,OUTPUT);
  pinMode(motor.ena,OUTPUT);
  digitalWrite(motor.ena,LOW);
}

void moveMotor(enum Directions dir){
  Motor motor;
  int steps;
  switch (dir){
    case UP:
    motor = MOTORY;
    digitalWrite(motor.dir,HIGH);
//    steps = FULLSTEP;
    break;
    case RIGHT:
    motor = MOTORX;
    digitalWrite(motor.dir,LOW);
    break;
    case DOWN:
    motor = MOTORY;
    digitalWrite(motor.dir,LOW);
    break;
    case LEFT:
    motor = MOTORX;
    digitalWrite(motor.dir,HIGH);
    default:
    steps = FULLSTEP;
    break;
  }
  steps = FULLSTEP;  
  for (int i = 0; i < steps; ++i){
    digitalWrite(motor.pulse,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(motor.pulse,LOW); 
    delayMicroseconds(500);   
  }
  digitalWrite(motor.pulse,LOW);
  delayMicroseconds(2000);   
}


//enum DirectionDiagonal{
//  UP_RIGHT,  //  MOTORY.dir = high && MOTORX.dir = low
//  UP_LEFT, //  MOTORY.dir = high && MOTORX.dir = high
//  DOWN_RIGHT, //  MOTORY.dir = low && MOTORX.dir = low
//  DOWN_LEFT,  //  MOTORY.dir = low && MOTORX.dir = high
//}

void moveMotorDiagonal(enum Directions dir){
  int stepsX;
  int stepsY;
  int steps = FULLSTEP;
  Motor motors[] = {MOTORX, MOTORY};

    switch (dir){
    case UP_RIGHT:
    digitalWrite(MOTORY.dir,HIGH);
    digitalWrite(MOTORX.dir,LOW);
//    stepsX = FULLSTEP;
//    stepsY = FULLSTEP;
    break;
    case UP_LEFT:
    digitalWrite(MOTORY.dir,HIGH);
    digitalWrite(MOTORX.dir,HIGH);
    break;
    case DOWN_RIGHT:
    digitalWrite(MOTORY.dir,LOW);
    digitalWrite(MOTORX.dir,LOW);
    break;
    case DOWN_LEFT:
    digitalWrite(MOTORY.dir,LOW);
    digitalWrite(MOTORX.dir,HIGH);
    default:
    steps = FULLSTEP;
    break;
  }

  for (int i = 0; i < steps; ++i){
      digitalWrite(MOTORX.pulse,HIGH);
      digitalWrite(MOTORY.pulse,HIGH);  
      delayMicroseconds(500); 
      digitalWrite(MOTORX.pulse,LOW);
      digitalWrite(MOTORY.pulse,LOW); 
      delayMicroseconds(500); 
  }
  digitalWrite(MOTORX.pulse,LOW);
  digitalWrite(MOTORY.pulse,LOW);
  delayMicroseconds(20000);   
}


void performMove(enum Directions direction){
  if (direction == UP || direction == RIGHT || direction == DOWN || direction == LEFT){
    moveMotor(direction);
  }
  else {
    moveMotorDiagonal(direction);
  }
}
