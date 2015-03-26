#ifndef StopHook_H
#define StopHook_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopHook: public CommandBase
{
public:
	StopHook();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
