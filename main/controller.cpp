// #include "HardwareSerial.h"
#include "controller.h"

bool posReached;
Pos lastPos;

void controllerSetup() {
  motorSetup();
  magnetSetup();
  lastPos = { 0, 0 };
  posReached = true;
}

bool getPosreached() {
  return posReached;
}

Pos getLastPos(){
  return lastPos;
}

void handleServerInput(ServerInput serverInput) {
  if (serverInput.poll) {
  } else {
    posReached = false;
    toggleMagnet(serverInput.magnetStatus);
    performMove(lastPos, serverInput.to);
    lastPos = serverInput.to;
    posReached = true;
  }
}


void performMove(Pos oldPos, Pos newPos) {
  int max = nrOfMoves(oldPos, newPos);
  Directions directions[max];
  setDirections(directions, max, oldPos, newPos);
  for (int i = 0; i < max; i++) {
    int steps = setNrOfSteps(directions[i]);
    moveMotors(directions[i], steps);
  }
}

int nrOfMoves(Pos oldPos, Pos newPos) {
  int dx = abs(oldPos.x - newPos.x);
  int dy = abs(oldPos.y - newPos.y);
  return max(dx, dy);
}

void setDirections(Directions directions[], int max, Pos oldPos, Pos newPos) {
  for (int i = 0; i < max; ++i) {
    Directions direction = calculateDirection(oldPos, newPos);
    oldPos = shiftPos(direction, oldPos);
    directions[i] = direction;
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

int setNrOfSteps(Directions direction) {
  int steps;
  switch (direction) {
    case UP:
      steps = calculateNrOfSteps(STRAIGHT_DISTANCE, FULL_STEP_UP);
      break;
    case RIGHT:
      steps = calculateNrOfSteps(STRAIGHT_DISTANCE, FULL_STEP_RIGHT);
      break;
    case DOWN:
      steps = calculateNrOfSteps(STRAIGHT_DISTANCE, FULL_STEP_DOWN);
      break;
    case LEFT:
      steps = calculateNrOfSteps(STRAIGHT_DISTANCE, FULL_STEP_LEFT);
      break;
    case UP_RIGHT:
      steps = calculateNrOfSteps(DIAGONAL_DISTANCE, FULL_STEP_UP_RIGHT);
      break;
    case UP_LEFT:
      steps = calculateNrOfSteps(DIAGONAL_DISTANCE, FULL_STEP_UP_LEFT);
      break;
    case DOWN_RIGHT:
      steps = calculateNrOfSteps(DIAGONAL_DISTANCE, FULL_STEP_DOWN_RIGHT);
      break;
    case DOWN_LEFT:
      steps = calculateNrOfSteps(DIAGONAL_DISTANCE, FULL_STEP_DOWN_LEFT);
      break;
    default:
      steps = 0;
      break;
  }
  return steps;
}

int calculateNrOfSteps(float realDistance, float motorDistance) {
  return int((realDistance / motorDistance) * FULLSTEP);
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
  } else if (up && right) {
    direction = Directions::UP_RIGHT;
  } else if (up && left) {
    direction = Directions::UP_LEFT;
  } else if (down && (!left && !right)) {
    direction = Directions::DOWN;
  } else if (down && right) {
    direction = Directions::DOWN_RIGHT;
  } else if (down && left) {
    direction = Directions::DOWN_LEFT;
  } else if (left && (!up && !down)) {
    direction = Directions::LEFT;
  } else if (right && (!up && !down)) {
    direction = Directions::RIGHT;
  }
  return direction;
}
