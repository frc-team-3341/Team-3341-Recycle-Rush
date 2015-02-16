#ifndef DriveXFeet_H
#define DriveXFeet_H

#include "../CommandBase.h"
#include "../NewPIDController.h"
#include "WPILib.h"

class DriveXMeters: public CommandBase
{
public:
	DriveXMeters(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double distance;
	NewPIDController* pid;
};

#endif
