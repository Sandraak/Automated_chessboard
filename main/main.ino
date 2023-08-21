#include "server.h"
// #include "motor.h"
// #include "magnet.h"
// #include "controller.h"

// int Delay = 1000;

void setup() {
  serverSetup();
  // controllerSetup();
  // controllerSetup();
  // magnetSetup();
  // initMotor(MotorAxis::X);
  // initMotor(MotorAxis::Y);
  // // Serial.begin(9600);
  // Pos oldPos = { 0, 0 };
  // Pos newPos = { 5, 0 };
  // performMove(oldPos, newPos);
  // oldPos = { 5, 0 };
  // newPos = { 0, 0 };
  // performMove(oldPos, newPos);
  // Serial.println("done");
}

void loop() {
  serverLoop();
  // controllerLoop();
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
