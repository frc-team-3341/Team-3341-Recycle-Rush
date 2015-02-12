#ifndef Drive_H
#define Drive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drive: public Subsystem
{
private:
	Talon* left;
	Talon* right;
	Encoder* eLeft;
	Encoder* eRight;
	float Limit(float num);
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Drive();
	void arcadeDrive(float move, float rotate);
	void InitDefaultCommand();
};

#endif
