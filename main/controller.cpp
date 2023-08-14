#include "controller.h"

void controllerSetup(Pos oldPos, Pos newPos) {
  oldPos = { 0, 0 };
  newPos = { 0, 0 };
  Magnet magnet{ newPos, false };
}

void performMove(Pos oldPos, Pos newPos) {
  Vector<Directions> directions = SetDirections(oldPos,newPos);
  for(int i =0; i < directions.size(); i++){
  int steps = calculateNrOfSteps(directions[i]);
  moveMotors(directions[i], steps);
  }
  //send done
}

Vector<Directions> SetDirections(Pos oldPos, Pos newPos) {
  int dx = abs(oldPos.x - newPos.x);
  int dy = abs(oldPos.y - newPos.y);
  int max = max(dx, dy);
  Vector<Directions> directions;
  for (int i = 0; i < max; ++i) {
    Directions direction = calculateDirection(oldPos, newPos);
    oldPos = shiftPos(direction, oldPos);
    directions.push_back(direction);
  }
  return directions;
}

Pos shiftPos(Directions direction, Pos oldPos) {
  switch (direction) {
    case UP:
      oldPos.y + 1;
      break;
    case RIGHT:
      oldPos.x + 1;
      break;
    case DOWN:
      oldPos.y - 1;
      break;
    case LEFT:
      oldPos.x - 1;
      break;
    case UP_RIGHT:
      oldPos.y + 1;
      oldPos.x + 1;
      break;
    case UP_LEFT:
      oldPos.y + 1;
      oldPos.x - 1;
      break;
    case DOWN_RIGHT:
      oldPos.y - 1;
      oldPos.x + 1;
      break;
    case DOWN_LEFT:
      oldPos.y - 1;
      oldPos.x - 1;
      break;
    default:
      break;
  }
  return oldPos;
}

int calculateNrOfSteps(Directions direction) {
  int steps;
  if (direction == UP || direction == RIGHT || direction == DOWN || direction == LEFT) {
    steps = (STRAIGHT_DISTANCE / FULL_STEP_STRAIGHT) * FULLSTEP;
  } else {
    steps = (DIAGONAL_DISTANCE / FULL_STEP_DIAGONAL) * FULLSTEP;
  }
  return steps;
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
