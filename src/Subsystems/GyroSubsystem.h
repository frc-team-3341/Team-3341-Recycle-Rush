#ifndef GyroSubsystem_H
#define GyroSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class GyroSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Gyro* agyro;
public:
	GyroSubsystem();
	void InitDefaultCommand();
	double GetAngle();
	void ResetGyro();
};

#endif
