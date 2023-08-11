#include "controller.h"

// bool positionReached = false;
// Pos PreviousPosition = { 0, 0 };
// Pos NewPosition = { 0, 0 };

int calculateNrOfSteps(Directions direction) {
  int steps;
  if (direction == UP || direction == RIGHT || direction == DOWN || direction == LEFT) {
    steps = (STRAIGHT_DISTANCE / FULL_STEP_STRAIGHT) * FULLSTEP;
  } else {
    steps = (DIAGONAL_DISTANCE / FULL_STEP_DIAGONAL) * FULLSTEP;
  }
  return steps;
}

void setStart(Pos previousPosition, Pos NewPosition) {
  Pos PreviousPosition = { 0, 0 };
  Pos NewPosition = { 0, 0 };
}

Directions calculateDirection(Pos previousPosition, Pos newPosition) {
  Directions direction;
  bool up = false;
  bool down = false;
  bool right = false;
  bool left = false;
  if (previousPosition.y + newPosition.y > previousPosition.y) {
    up = true;
  }
  if (previousPosition.y + newPosition.y < previousPosition.y) {
    down = true;
  }
  if (previousPosition.x + newPosition.x > previousPosition.y) {
    right = true;
  }
  if (previousPosition.x + newPosition.x < previousPosition.y) {
    left = true;
  }

  if (up && (!left && !right)) {
    direction = Directions::UP;
    Serial.println("up");
  } else if (up && right) {
    direction = Directions::UP_RIGHT;
    Serial.println("up right");
  } else if (up && left) {
    direction = Directions::UP_LEFT;
    Serial.println("up left");
  } else if (down && (!left && !right)) {
    direction = Directions::DOWN;
    Serial.println("down");
  } else if (down && right) {
    direction = Directions::DOWN_RIGHT;
    Serial.println("down right");
  } else if (down && left) {
    direction = Directions::DOWN_LEFT;
    Serial.println("down left");
  } else if (left && (!up && !down)) {
    direction = Directions::LEFT;
    Serial.println("left");
  } else if (right && (!up && !down)) {
    direction = Directions::RIGHT;
    Serial.println("right");
  }
  return direction;
}
