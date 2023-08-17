#include "magnet.h"


//npn transistor 220 ohm

void magnetSetup() {
  pinMode(TRANSISTOR_PIN, OUTPUT);
  // digitalWrite(TRANSISTOR_PIN, LOW);
}

void toggleMagnet(bool on) {
  if (on) {
    digitalWrite(TRANSISTOR_PIN, HIGH);
  } else {
    digitalWrite(TRANSISTOR_PIN, LOW);
  }
}

