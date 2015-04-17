#ifndef HooksToXMeters_H
#define HooksToXMeters_H

#include "../CommandBase.h"
#include "../NewPIDController.h"
#include "WPILib.h"

class HooksToXMeters: public CommandBase
{
public:
	HooksToXMeters(double height);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double height;
	NewPIDController* hookElevatorPid;
};

#endif

