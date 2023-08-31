#ifndef MAGNET_H
#define MAGNET_H
#include <Arduino.h>

const int TRANSISTOR_PIN =7;

/**
* \brief Initializes the transistor pin that powers the magnet. 
*/
void magnetSetup();

/**
* \brief Will power the magnet when on is true, and shut it off when false
* @param on Whether the magnet should be on or off.
*/
void toggleMagnet(bool on);

#endif /* MAGNET_H */
