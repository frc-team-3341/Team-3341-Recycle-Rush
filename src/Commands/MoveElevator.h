#ifndef MoveElevator_H
#define MoveElevator_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveElevator: public CommandBase
{
public:
	MoveElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
