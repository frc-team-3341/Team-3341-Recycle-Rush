#ifndef MoveHook_H
#define MoveHook_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveHook: public CommandBase
{
public:
	MoveHook();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
