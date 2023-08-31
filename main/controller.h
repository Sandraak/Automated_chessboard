#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <math.h>
#include "motor.h"
#include "magnet.h"


/**
* Position on the chessboard.
*/
struct Pos {
  int x;
  int y;

  inline bool operator==(Pos a) {
    return (a.x == x && a.y == y);
  };

  inline bool operator!=(Pos a) {
    return (a.x != x || a.y != y);
  };
};


/**
* Information received by the server in struct format.
*/
struct ServerInput{
  bool poll; //Does the client want to know whether the magnet hsa reached its destination?
  Pos to; // Position the magnet has to move to
  bool magnetStatus; //Whether the magnet should be on or not.
};

//Size of the squares
const float STRAIGHT_DISTANCE = 300.0;  // mm
const float DIAGONAL_DISTANCE = sqrt(2 * pow(STRAIGHT_DISTANCE,2)); //pythagoras

//The distance that the magnet travels in one full step in a certain direction
const float FULL_STEP_RIGHT = 310.0;  // mm
const float FULL_STEP_LEFT = 315.0;   // mm
const float FULL_STEP_UP = 310.0;     // mm
const float FULL_STEP_DOWN = 315.0; // mm   
const float FULL_STEP_UP_RIGHT = 438.5;    // mm
const float FULL_STEP_DOWN_LEFT = 438.5;   // mm
const float FULL_STEP_UP_LEFT = 438.5;     // mm
const float FULL_STEP_DOWN_RIGHT = 438.5;  // mm


/**
* \brief Initializes the motors, magnet and sets the global controller values to default.
*/
void controllerSetup();
/**
* \brief Sends instructions to the magnet and motors to perform a move received by the server.
* @param serverInput Instructions for the magnet and steppermotors as received by the server.
*/
void handleServerInput(ServerInput serverInput);

/**
* \brief Instructs the steppermotors move the magnet from its old position to a new position.
* @param  oldPos The location of the magnet on the chessboard before the move.
* @param  newPos The location where the magnet will be after the move.
*/
void performMove(Pos oldPos, Pos newPos);

/**
* \brief Checks how many squares the magnet will have to cover.
* @param oldPos The location of the magnet on the chessboard before the move.
* @param newPos The location where the magnet will be after the move.
* @return The number of squares the magnet will cover during the move.
*/
int nrOfMoves(Pos oldPos, Pos newPos);

/**
* \brief Fills an array with the directions the motor will have to move the magnet to reach the new position.
* @param directions Empty array thwt will be filled by the function.
* @param max The number of directions that will be put in directions
* @param oldPos The location of the magnet on the chessboard before the move.
* @param newPos The location where the magnet will be after the move.
*/
void setDirections(Directions* directions, int max, Pos oldPos, Pos newPos);

/**
* \brief Updates the old position of the magnet.
* @param direction The direction in which the magnet is shifting
* @param oldPos The location of the magnet on the chessboard before the move.
* @return The updated position.
*/
Pos shiftPos(Directions direction, Pos oldPos);

/**
* \brief returns the number of steps the stppermotor has to perform to move one sqaure in a certain direction.
* @param direction The direction in which the magnet is moving.
* @return The number of steps the steppermotor will have to perform.
*/
int setNrOfSteps(Directions direction);

/**
* \brief Calculates the number of steps the steppermotor has to perform to cover a certain distance.
* @param realDistance The distance in mm the magnet has to travel to move from one square to another.
* @param motorDistance The distance in mmthe magnet travels when the steppermotor performs a full step in a certain direction.
* @return The number of steps the steppermotor has to perform to travel a certain distance. 
*/
int calculateNrOfSteps(float realDistance, float motorDistance);

/**
* \brief Determines in which direction the magnet has to move to get from its old position to the new position.
* @param oldPos The location of the magnet on the chessboard before the move.
* @param newPos The location where the magnet will be after the move.
* @return The direction in which the magnet has to move.
*/
Directions calculateDirection(Pos oldPos, Pos newPos);

bool getPosreached();
Pos getLastPos();

#endif /* CONTROLLER_H */
