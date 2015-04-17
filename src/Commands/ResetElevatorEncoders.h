#ifndef ResetElevatorEncoders_H
#define ResetElevatorEncoders_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetElevatorEncoders: public CommandBase
{
public:
	ResetElevatorEncoders();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

