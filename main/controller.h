#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <math.h>
#include "motor.h"

struct Pos {
  int x;
  int y;
};

struct Magnet {
  Pos lastPos;
  bool on;
};

//Size of the squares
const float STRAIGHT_DISTANCE = 300.0;  // mm
const float DIAGONAL_DISTANCE = sqrt(2 * STRAIGHT_DISTANCE);

//The distance that the magnet travels in one full step
const float FULL_STEP_STRAIGHT_RIGHT = 310.0;  // mm
const float FULL_STEP_STRAIGHT_LEFT = 315.0;  // mm
const float FULL_STEP_DIAGONAL = 470.0;  // mm

void controllerSetup(Pos oldPos, Pos newPos);
void performMove(Pos oldPos, Pos newPos);
int nrOfMoves(Pos oldPos, Pos newPos);
void setDirections(Directions* directions, int max, Pos oldPos, Pos newPos);
Pos shiftPos(Directions direction, Pos oldPos);
int calculateNrOfSteps(Directions direction);
Directions calculateDirection(Pos oldPos, Pos newPos);

#endif /* CONTROLLER_H */
