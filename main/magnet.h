#ifndef MAGNET_H
#define MAGNET_H
#include <Arduino.h>

const int TRANSISTOR_PIN =7;

void magnetSetup();
void toggleMagnet(bool on);

#endif /* MAGNET_H */
