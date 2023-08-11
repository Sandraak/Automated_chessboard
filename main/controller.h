#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <math.h>
#include "motor.h"

struct Pos {
  int x;
  int y;
};

const int STRAIGHT_DISTANCE = 300;  // mm
const int DIAGONAL_DISTANCE = short(sqrt(2 * STRAIGHT_DISTANCE));

const int FULL_STEP_STRAIGHT = 340;  // mm
const int FULL_STEP_DIAGONAL = 470;  // mm

int calculateNrOfSteps(Directions direction);
void setStart(Pos newPosition);
Directions calculateDirection(Pos oldPos, Pos newPos);

#endif /* CONTROLLER_H */
