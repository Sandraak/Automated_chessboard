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

const float STRAIGHT_DISTANCE = 300.0;  // mm
const float DIAGONAL_DISTANCE = sqrt(2 * STRAIGHT_DISTANCE);

const float FULL_STEP_STRAIGHT = 340.0;  // mm
const float FULL_STEP_DIAGONAL = 470.0;  // mm

void controllerSetup(Pos oldPos, Pos newPos);
void performMove(Pos oldPos, Pos newPos);
int nrOfMoves(Pos oldPos, Pos newPos);
void setDirections(Directions* directions, int max, Pos oldPos, Pos newPos);
Pos shiftPos(Directions direction, Pos oldPos);
int calculateNrOfSteps(Directions direction);
Directions calculateDirection(Pos oldPos, Pos newPos);

#endif /* CONTROLLER_H */
