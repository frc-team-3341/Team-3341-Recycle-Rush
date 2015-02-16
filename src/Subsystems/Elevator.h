#ifndef Elevator_H
#define Elevator_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Elevator: public Subsystem
{
private:
	Jaguar* s1Screw;
	Jaguar* s2Screw;
	double s1Distance;
	double s2Distance;
	Encoder* s1Encoder;
	Encoder* s2Encoder;
	bool clawControl;
	bool both;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Elevator();
	void InitDefaultCommand();
	void bothOn();
	void bothOff();
	void clawOn();
	void clawOff();
	void moveElevator(float speed);
};

#endif
