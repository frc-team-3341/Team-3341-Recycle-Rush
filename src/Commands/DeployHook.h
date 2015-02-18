#ifndef DeployHook_H
#define DeployHook_H

#include "../CommandBase.h"
#include "WPILib.h"

class DeployHook: public CommandBase
{
public:
	DeployHook();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
