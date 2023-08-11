#include "motor.h"
#include "server.h"
#include "controller.h"

int Delay = 1000;

void setup() {
  server_setup();
  initMotor(MotorAxis::X);
  initMotor(MotorAxis::Y);
  // Serial.begin(9600);
  // Pos oldPos = { 0, 0 };
  // Pos newPos = { 1, 1 };
  // Directions direction = calculateDirection(oldPos, newPos);
  // // Serial.println(oldPos);
}

void loop() {
  // Pos oldPos = { 0, 0 };
  // Pos newPos = { -1, -1 };
  // // calculateMovement(oldPos, newPos);
  // Directions direction = calculateDirection(oldPos, newPos);
  // server_loop();
  // performMove(Directions::UP_RIGHT);
  // performMove(Directions::DOWN_LEFT);
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
