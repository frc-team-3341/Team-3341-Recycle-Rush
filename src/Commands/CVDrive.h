#ifndef CVDrive_H
#define CVDrive_H

#include "../CommandBase.h"
#include "../NewPIDController.h"
#include "WPILib.h"

class CVDrive: public CommandBase
{
public:
	CVDrive();
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
