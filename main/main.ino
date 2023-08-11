#include "motor.h"
#include "server.h"


void setup() {
  server_setup();
  initMotor(MotorAxis::X);
  initMotor(MotorAxis::Y);
}

void loop() {
  server_loop();
//  performMove(Directions::UP_RIGHT);
//  performMove(Directions::DOWN_LEFT);
}
