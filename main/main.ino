#include "motor.h"
#include "server.h"
#include "controller.h"

int Delay = 1000;

void setup() {
  server_setup();
  // controllerSetup(Pos oldPos, Pos newPos);
  initMotor(MotorAxis::X);
  initMotor(MotorAxis::Y);
  // Serial.begin(9600);
  Pos oldPos = { -2, 0 };
  Pos newPos = { 8, 0 };

  performMove(oldPos, newPos);

  newPos = { -2, 0 };
  oldPos = { 8, 0 };
    performMove(oldPos, newPos);
  // Directions direction = calculateDirection(oldPos, newPos);
    // moveMotors(UP_RIGHT, 300);
  Serial.println("done");
}

void loop() {
  //   Pos oldPos = { 0, 0 };
  // Pos newPos = { -2, 0 };
  // performMove(oldPos, newPos);
  // Pos oldPos = { 0, 0 };
  // Pos newPos = { -1, -1 };
  // // calculateMovement(oldPos, newPos);
  // Directions direction = calculateDirection(oldPos, newPos);
  // server_loop();
  // moveMotors(UP_RIGHT, 300);
  // delay(Delay);
  // performMove(Directions::UP);
  // performMove(Directions::DOWN_LEFT);
  // delay(Delay);
  // performMove(Directions::UP);
  // delay(Delay);
  // performMove(Directions::RIGHT);
  // delay(Delay);
  // performMove(Directions::DOWN);
  // delay(Delay);
  // performMove(Directions::LEFT);
  // delay(Delay);
  // performMove(Directions::DOWN);
}
