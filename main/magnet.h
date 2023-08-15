#ifndef MAGNET_H
#define MAGNET_H
#include <Arduino.h>

const int MAGNET_PIN = 1;

void magnet_setup();
void toggle_magnet(bool on);

#endif /* MAGNET_H */
