#ifndef ActivateHook_H
#define ActivateHook_H

#include "../CommandBase.h"
#include "WPILib.h"

class ActivateHook: public CommandBase
{
public:
	ActivateHook();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
