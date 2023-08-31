#include <ArduinoUnit.h>
#include "tests.h"

void testSetup() {}

void runTests() {
  Test::run();
}
test(castCharToInt) {
  // Test case for a single-digit integer
  char buf1[] = "5";
  int result1 = castChartoInt(buf1, 1);
  assertEqual(result1, 5);

  // Test case for a negative single-digit integer
  char buf2[] = "-3";
  int result2 = castChartoInt(buf2, 2);
  assertEqual(result2, -3);

  // Test case for a double-digit integer
  char buf3[] = "42";
  int result3 = castChartoInt(buf3, 2);
  assertEqual(result3, 42);
}


test(calculateNrOfSteps) {
  // Test when realDistance is equal to motorDistance
  float realDistance = 300.0; // mm
  float motorDistance = 300.0; // mm
  int steps = calculateNrOfSteps(realDistance, motorDistance);
  assertEqual(steps, FULLSTEP);

  // Test when realDistance is twice the motorDistance
  realDistance = 600.0; // mm
  motorDistance = 300.0; // mm
  steps = calculateNrOfSteps(realDistance, motorDistance);
  assertEqual(steps, 2 * FULLSTEP);

  // Test when realDistance is half the motorDistance
  realDistance = 150.0; // mm
  motorDistance = 300.0; // mm
  steps = calculateNrOfSteps(realDistance, motorDistance);
  assertEqual(steps, FULLSTEP / 2);
}

test(calculateDirection) {
  // Test moving UP
  Pos previousPos = {2, 2};
  Pos newPos = {2, 3};
  Directions direction = calculateDirection(previousPos, newPos);
  assertEqual(direction, UP);

  // Test moving RIGHT
  previousPos = {2, 2};
  newPos = {3, 2};
  direction = calculateDirection(previousPos, newPos);
  assertEqual(direction, RIGHT);

  // Test moving DOWN
  previousPos = {2, 2};
  newPos = {2, 1};
  direction = calculateDirection(previousPos, newPos);
  assertEqual(direction, DOWN);

  // Test moving LEFT
  previousPos = {2, 2};
  newPos = {1, 2};
  direction = calculateDirection(previousPos, newPos);
  assertEqual(direction, LEFT);

  // Test moving UP_RIGHT
  previousPos = {2, 2};
  newPos = {3, 3};
  direction = calculateDirection(previousPos, newPos);
  assertEqual(direction, UP_RIGHT);

  // Test moving UP_LEFT
  previousPos = {2, 2};
  newPos = {1, 3};
  direction = calculateDirection(previousPos, newPos);
  assertEqual(direction, UP_LEFT);

  // Test moving DOWN_RIGHT
  previousPos = {2, 2};
  newPos = {3, 1};
  direction = calculateDirection(previousPos, newPos);
  assertEqual(direction, DOWN_RIGHT);

  // Test moving DOWN_LEFT
  previousPos = {2, 2};
  newPos = {1, 1};
  direction = calculateDirection(previousPos, newPos);
  assertEqual(direction, DOWN_LEFT);

}

test(shiftPos) {
  // Test shifting UP
  Pos oldPos = {2, 2};
  Pos newPos = shiftPos(UP, oldPos);
  assertEqual(newPos.x, 2);
  assertEqual(newPos.y, 3);

  // Test shifting RIGHT
  oldPos = {2, 2};
  newPos = shiftPos(RIGHT, oldPos);
  assertEqual(newPos.x, 3);
  assertEqual(newPos.y, 2);

  // Test shifting DOWN
  oldPos = {2, 2};
  newPos = shiftPos(DOWN, oldPos);
  assertEqual(newPos.x, 2);
  assertEqual(newPos.y, 1);

  // Test shifting LEFT
  oldPos = {2, 2};
  newPos = shiftPos(LEFT, oldPos);
  assertEqual(newPos.x, 1);
  assertEqual(newPos.y, 2);

  // Test shifting UP_RIGHT
  oldPos = {2, 2};
  newPos = shiftPos(UP_RIGHT, oldPos);
  assertEqual(newPos.x, 3);
  assertEqual(newPos.y, 3);

  // Test shifting UP_LEFT
  oldPos = {2, 2};
  newPos = shiftPos(UP_LEFT, oldPos);
  assertEqual(newPos.x, 1);
  assertEqual(newPos.y, 3);

  // Test shifting DOWN_RIGHT
  oldPos = {2, 2};
  newPos = shiftPos(DOWN_RIGHT, oldPos);
  assertEqual(newPos.x, 3);
  assertEqual(newPos.y, 1);

  // Test shifting DOWN_LEFT
  oldPos = {2, 2};
  newPos = shiftPos(DOWN_LEFT, oldPos);
  assertEqual(newPos.x, 1);
  assertEqual(newPos.y, 1);
}

test(setDirections) {
  // Test when moving UP
  Pos oldPos = {2, 2};
  Pos newPos = {2, 3};
  Directions directions[5];
  setDirections(directions, 1, oldPos, newPos);
  assertEqual(directions[0], UP);

  // Test when moving RIGHT
  oldPos = {2, 2};
  newPos = {3, 2};
  setDirections(directions, 1, oldPos, newPos);
  assertEqual(directions[0], RIGHT);

  // Test when moving DOWN
  oldPos = {2, 2};
  newPos = {2, 1};
  setDirections(directions, 1, oldPos, newPos);
  assertEqual(directions[0], DOWN);

  // Test when moving LEFT
  oldPos = {3, 2};
  newPos = {1, 2};
  setDirections(directions, 2, oldPos, newPos);
  assertEqual(directions[0], LEFT);
  assertEqual(directions[1], LEFT);

  // Test when moving diagonally UP_RIGHT
  oldPos = {1, 1};
  newPos = {3, 3};
  setDirections(directions, 2, oldPos, newPos);
  assertEqual(directions[0], UP_RIGHT);
  assertEqual(directions[1], UP_RIGHT);

  // Test when moving diagonally UP_LEFT
  oldPos = {7, 0};
  newPos = {5, 2};
  setDirections(directions, 2, oldPos, newPos);
  assertEqual(directions[0], UP_LEFT);
  assertEqual(directions[1], UP_LEFT);

  // Test when moving diagonally DOWN_RIGHT
  oldPos = {0, 7};
  newPos = {2, 5};
  setDirections(directions, 2, oldPos, newPos);
  assertEqual(directions[0], DOWN_RIGHT);
  assertEqual(directions[1], DOWN_RIGHT);

  // Test when moving diagonally DOWN_LEFT
  oldPos = {7, 7};
  newPos = {5, 5};
  setDirections(directions, 2, oldPos, newPos);
  assertEqual(directions[0], DOWN_LEFT);
  assertEqual(directions[1], DOWN_LEFT);

  // Test when moving diagonally 2 squares DOWN_LEFT, and then 3 squres LEFT
  oldPos = {7, 7};
  newPos = {2, 5};
  setDirections(directions, 5, oldPos, newPos);
  assertEqual(directions[0], DOWN_LEFT);
  assertEqual(directions[1], DOWN_LEFT);
  assertEqual(directions[2], LEFT);
  assertEqual(directions[3], LEFT);
  assertEqual(directions[4], LEFT);
}


test(nrOfMoves) {
  // Test when oldPos and newPos are the same
  Pos oldPos = {3, 4};
  Pos newPos = {3, 4};
  int result = nrOfMoves(oldPos, newPos);
  assertEqual(result, 0); // Expected result: 0 when positions are the same

  // Test when newPos is directly above oldPos
  oldPos = {2, 3};
  newPos = {2, 6};
  result = nrOfMoves(oldPos, newPos);
  assertEqual(result, 3); // Expected result: 3 when moving vertically

  // Test when newPos is directly to the right of oldPos
  oldPos = {2, 3};
  newPos = {5, 3};
  result = nrOfMoves(oldPos, newPos);
  assertEqual(result, 3); // Expected result: 3 when moving horizontally

  // Test when newPos is diagonally away from oldPos
  oldPos = {2, 4};
  newPos = {5, 5};
  result = nrOfMoves(oldPos, newPos);
  assertEqual(result, 3); // Expected result: 3 when moving diagonally
}

test(controllerSetup) {
  controllerSetup();
  assertEqual(getPosreached(), true);
  assertEqual(getLastPos().x, 0);
  assertEqual(getLastPos().y, 0);
}

test(handeServerInput) {
  controllerSetup();
  ServerInput input;
  input.poll = false;
  input.magnetStatus = true;
  input.to = { 2, 2 };
  handleServerInput(input);
  assertEqual(getLastPos().x, 2);
  assertEqual(getLastPos().y, 2);
  assertEqual(getPosreached(), true);

  input.poll = true;
  input.magnetStatus = true;
  input.to = { 3, 3 };
  handleServerInput(input);
  assertNotEqual(getLastPos().x, 3);
  assertNotEqual(getLastPos().y, 3);
}

test(motorSetup) {
  motorSetup();
  assertEqual(digitalRead(MOTORX.pulse), LOW);
  assertEqual(digitalRead(MOTORY.pulse), LOW);
}

test(moveMotorStraight) {
  motorSetup();
  moveMotorStraight(UP, 10);
  assertEqual(digitalRead(MOTORY.dir), LOW);
  moveMotorStraight(DOWN, 10);
  assertEqual(digitalRead(MOTORY.dir), HIGH);
  moveMotorStraight(LEFT, 10);
  assertEqual(digitalRead(MOTORX.dir), HIGH);
  moveMotorStraight(RIGHT, 10);
  assertEqual(digitalRead(MOTORX.dir), LOW);
}

test(moveMotorDiagonal) {
  motorSetup();
  moveMotorDiagonal(UP_RIGHT, 10);
  assertEqual(digitalRead(MOTORY.dir), LOW);
  assertEqual(digitalRead(MOTORX.dir), LOW);
  moveMotorDiagonal(UP_LEFT, 10);
  assertEqual(digitalRead(MOTORY.dir), LOW);
  assertEqual(digitalRead(MOTORX.dir), HIGH);
  moveMotorDiagonal(DOWN_RIGHT, 10);
  assertEqual(digitalRead(MOTORY.dir), HIGH);
  assertEqual(digitalRead(MOTORX.dir), LOW);
  moveMotorDiagonal(DOWN_LEFT, 10);
  assertEqual(digitalRead(MOTORY.dir), HIGH);
  assertEqual(digitalRead(MOTORX.dir), HIGH);
}

test(moveMotors) {
  motorSetup();
  moveMotors(UP, 10);
  assertEqual(digitalRead(MOTORY.dir), LOW);
  moveMotors(DOWN, 10);
  assertEqual(digitalRead(MOTORY.dir), HIGH);
  moveMotors(LEFT, 10);
  assertEqual(digitalRead(MOTORX.dir), HIGH);
  moveMotors(RIGHT, 10);
  assertEqual(digitalRead(MOTORX.dir), LOW);
  moveMotors(UP_RIGHT, 10);
  assertEqual(digitalRead(MOTORY.dir), LOW);
  assertEqual(digitalRead(MOTORX.dir), LOW);
  moveMotors(UP_LEFT, 10);
  assertEqual(digitalRead(MOTORY.dir), LOW);
  assertEqual(digitalRead(MOTORX.dir), HIGH);
  moveMotors(DOWN_RIGHT, 10);
  assertEqual(digitalRead(MOTORY.dir), HIGH);
  assertEqual(digitalRead(MOTORX.dir), LOW);
  moveMotors(DOWN_LEFT, 10);
  assertEqual(digitalRead(MOTORY.dir), HIGH);
  assertEqual(digitalRead(MOTORX.dir), HIGH);
}


test(magnet) {
  magnetSetup();
  toggleMagnet(true);
  assertEqual(digitalRead(TRANSISTOR_PIN), HIGH);
  toggleMagnet(false);
  assertEqual(digitalRead(TRANSISTOR_PIN), LOW);
}