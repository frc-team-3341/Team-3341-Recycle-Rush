#ifndef Claw_H
#define Claw_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Claw: public Subsystem
{
private:
	Jaguar* left;
	Jaguar* right;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	void open();
	void close();
	void stop();
	Claw();
	void InitDefaultCommand();
};

#endif
