#include "HardwareSerial.h"
#include "controller.h"

void controllerSetup(Pos oldPos, Pos newPos) {
  oldPos = { 0, 0 };
  newPos = { 0, 0 };
  Magnet magnet{ newPos, false };
}

void performMove(Pos oldPos, Pos newPos) {
  int max = nrOfMoves(oldPos, newPos);
  Directions directions[max];
  setDirections(directions, max, oldPos, newPos);

  //   Directions directions[max] = { Directions::
  //   LEFT,
  // };
  // Serial.print("directions size: ");
  // Serial.println(directions.size());
  for (int i = 0; i < max; i++) {
    int steps = calculateNrOfSteps(directions[i]);
    Serial.print("directions: ");
    Serial.println(directions[i]);
    Serial.print("steps: ");
    Serial.println(steps);

    // int steps = 500;
    moveMotors(directions[i], steps);
  }
}

int nrOfMoves(Pos oldPos, Pos newPos) {
  int dx = abs(oldPos.x - newPos.x);
  int dy = abs(oldPos.y - newPos.y);
  return max(dx, dy);
}

void setDirections(Directions directions[], int max, Pos oldPos, Pos newPos) {
  // int max = nrOfMoves(oldPos, newPos);
  // Directions directions[max];
  for (int i = 0; i < max; ++i) {
    Directions direction = calculateDirection(oldPos, newPos);
    oldPos = shiftPos(direction, oldPos);
    directions[i] = direction;
    Serial.print("set direction, direction: ");
    Serial.println(directions[i]);
  }
}

Pos shiftPos(Directions direction, Pos oldPos) {
  switch (direction) {
    case UP:
      oldPos.y += 1;
      break;
    case RIGHT:
      oldPos.x += 1;
      break;
    case DOWN:
      oldPos.y -= 1;
      break;
    case LEFT:
      oldPos.x -= 1;
      break;
    case UP_RIGHT:
      oldPos.y += 1;
      oldPos.x += 1;
      break;
    case UP_LEFT:
      oldPos.y += 1;
      oldPos.x -= 1;
      break;
    case DOWN_RIGHT:
      oldPos.y -= 1;
      oldPos.x += 1;
      break;
    case DOWN_LEFT:
      oldPos.y -= 1;
      oldPos.x -= 1;
      break;
    default:
      break;
  }
  return oldPos;
}

int calculateNrOfSteps(Directions direction) {
  int steps;
  if (direction == UP || direction == RIGHT || direction == DOWN || direction == LEFT) {
    Serial.println("calc number of steps straight");
    steps = int((STRAIGHT_DISTANCE / FULL_STEP_STRAIGHT) * FULLSTEP);
  } else {
    Serial.println("calc number of steps diagonal");
    steps = int((DIAGONAL_DISTANCE / FULL_STEP_DIAGONAL) * FULLSTEP);
  }
  return steps;
}

Directions calculateDirection(Pos previousPosition, Pos newPosition) {
  Directions direction;
  bool up = false;
  bool down = false;
  bool right = false;
  bool left = false;
  if (previousPosition.y < newPosition.y) {
    up = true;
  }
  if (previousPosition.y > newPosition.y) {
    down = true;
  }
  if (previousPosition.x < newPosition.x) {
    right = true;
  }
  if (previousPosition.x > newPosition.x) {
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
