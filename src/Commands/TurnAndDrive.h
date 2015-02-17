#ifndef DriveXFeet_H
#define DriveXFeet_H

#include "../CommandBase.h"
#include "../NewPIDController.h"
#include "WPILib.h"

class TurnAndDrive: public CommandBase
{
public:
	TurnAndDrive(double distance, double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double distance;
	double angle;
	NewPIDController* distancePid;
	NewPIDController* anglePid;
};

#endif
