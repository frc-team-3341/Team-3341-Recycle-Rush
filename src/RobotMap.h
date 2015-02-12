#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

const int TALON_LEFT = 0;
const int TALON_RIGHT = 1;
const int ENCODER_LEFT_1 = 0;
const int ENCODER_LEFT_2 = 1;
const int ENCODER_RIGHT_1 = 2;
const int ENCODER_RIGHT_2 = 3;
const int DRIVESTICK = 0;
const int OPERATORSTICK = 1;

#endif
