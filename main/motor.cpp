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

void moveMotorStraight(enum Directions dir, int steps){
  Motor motor;
  // int steps;
  switch (dir){
    case UP:
    motor = MOTORY;
    digitalWrite(motor.dir,LOW);
//    steps = FULLSTEP;
    break;
    case RIGHT:
    motor = MOTORX;
    digitalWrite(motor.dir,LOW);
    break;
    case DOWN:
    motor = MOTORY;
    digitalWrite(motor.dir,HIGH);
    break;
    case LEFT:
    motor = MOTORX;
    digitalWrite(motor.dir,HIGH);
    default:
    steps = FULLSTEP;
    break;
  }
  // steps = FULLSTEP;  
  for (int i = 0; i < steps; ++i){
    digitalWrite(motor.pulse,HIGH); 
    delayMicroseconds(DELAY); 
    digitalWrite(motor.pulse,LOW); 
    delayMicroseconds(DELAY);   
  }
  digitalWrite(motor.pulse,LOW);
  delayMicroseconds(4* DELAY);   
}

void moveMotorDiagonal(enum Directions dir, int steps){
  // steps = FULLSTEP;
  Motor motors[] = {MOTORX, MOTORY};

    switch (dir){
    case UP_RIGHT:
    digitalWrite(MOTORY.dir,LOW);
    digitalWrite(MOTORX.dir,LOW);
    break;
    case UP_LEFT:
    digitalWrite(MOTORY.dir,LOW);
    digitalWrite(MOTORX.dir,HIGH);
    break;
    case DOWN_RIGHT:
    digitalWrite(MOTORY.dir,HIGH);
    digitalWrite(MOTORX.dir,LOW);
    break;
    case DOWN_LEFT:
    digitalWrite(MOTORY.dir,HIGH);
    digitalWrite(MOTORX.dir,HIGH);
    default:
    // steps = FULLSTEP;
    break;
  }

  for (int i = 0; i < steps; ++i){
      digitalWrite(MOTORX.pulse,HIGH);
      digitalWrite(MOTORY.pulse,HIGH);  
      delayMicroseconds(DELAY); 
      digitalWrite(MOTORX.pulse,LOW);
      digitalWrite(MOTORY.pulse,LOW); 
      delayMicroseconds(DELAY); 
  }
  digitalWrite(MOTORX.pulse,LOW);
  digitalWrite(MOTORY.pulse,LOW);
  delayMicroseconds(4*DELAY);   
}


void moveMotors(enum Directions direction, int steps){
  // steps = FULLSTEP;
  Serial.println("move motor ");
  if (direction == UP || direction == RIGHT || direction == DOWN || direction == LEFT){
    moveMotorStraight(direction, steps);
  }
  else {
    moveMotorDiagonal(direction, steps);
  }
  //update location
}
