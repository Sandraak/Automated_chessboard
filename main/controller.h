#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <math.h>
#include <Vector.h>
#include "motor.h"

struct Pos {
  int x;
  int y;
};

struct Magnet {
  Pos lastPos;
  bool on;
};

const int STRAIGHT_DISTANCE = 300;  // mm
const int DIAGONAL_DISTANCE = short(sqrt(2 * STRAIGHT_DISTANCE));

const int FULL_STEP_STRAIGHT = 340;  // mm
const int FULL_STEP_DIAGONAL = 470;  // mm

void controllerSetup(Pos oldPos,Pos newPos);
void performMove(Directions direction, int steps);
Vector<Directions>  SetDirections(Pos oldPos,Pos newPos);
Pos shiftPos(Directions direction, Pos oldPos);
int calculateNrOfSteps(Directions direction);
Directions calculateDirection(Pos oldPos, Pos newPos);

#endif /* CONTROLLER_H */
