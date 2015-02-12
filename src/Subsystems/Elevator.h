#ifndef Elevator_H
#define Elevator_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Elevator: public Subsystem
{
private:
	Jaguar* s1Screw;
	Jaguar* s2Screw;
	Encoder* s1Encoder;
	Encoder* s2Encoder;
	bool clawControl;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Elevator();
	void InitDefaultCommand();
	void clawOn();
	void clawOff();
	void moveElevator(float speed);
};

#endif
