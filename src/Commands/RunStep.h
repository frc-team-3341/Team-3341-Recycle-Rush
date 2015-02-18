#ifndef RunStep_H
#define RunStep_H

#include "../CommandBase.h"
#include "../NewPIDController.h"
#include "WPILib.h"

class RunStep: public CommandBase
{
public:
	RunStep();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double step_size;
	int iteration = 0;
	NewPIDController* anglePid;
};

#endif
