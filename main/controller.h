#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <math.h>
#include "motor.h"
#include "magnet.h"
#include "server.h"


struct Pos {
  int x;
  int y;

  inline bool operator==(Pos a) {
    return (a.x == x && a.y == y);
  };

  inline bool operator!=(Pos a) {
    return (a.x != x || a.y != y);
  };
};

//Size of the squares
const float STRAIGHT_DISTANCE = 300.0;  // mm
const float DIAGONAL_DISTANCE = sqrt(2 * STRAIGHT_DISTANCE);

//The distance that the magnet travels in one full step in a certain direction
const float FULL_STEP_RIGHT = 310.0;  // mm
const float FULL_STEP_LEFT = 315.0;   // mm
//todo
const float FULL_STEP_UP = 310.0;          // mm
const float FULL_STEP_DOWN = 315.0;        // mm
const float FULL_STEP_UP_RIGHT = 310.0;    // mm
const float FULL_STEP_UP_LEFT = 310.0;     // mm
const float FULL_STEP_DOWN_RIGHT = 310.0;  // mm
const float FULL_STEP_DOWN_LEFT = 310.0;   // mm

const float FULL_STEP_DIAGONAL = 470.0;  // mm

void controllerSetup();
void handleServerInput(Pos from, Pos to, bool magnetStatus);
void performMove(Pos oldPos, Pos newPos);
int nrOfMoves(Pos oldPos, Pos newPos);
void setDirections(Directions* directions, int max, Pos oldPos, Pos newPos);
Pos shiftPos(Directions direction, Pos oldPos);
int setNrOfSteps(Directions direction);
int calculateNrOfSteps(float realDistance, float motorDistance);
Directions calculateDirection(Pos oldPos, Pos newPos);

#endif /* CONTROLLER_H */
