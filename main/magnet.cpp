#include "magnet.h"

void magnet_setup() {
  pinMode(MAGNET_PIN, OUTPUT);
}

void toggle_magnet(bool on) {
  if (on) {
    digitalWrite(MAGNET_PIN, HIGH);
  } else {
    digitalWrite(MAGNET_PIN, LOW);
  }
}