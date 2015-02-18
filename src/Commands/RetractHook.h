#ifndef RetractHook_H
#define RetractHook_H

#include "../CommandBase.h"
#include "WPILib.h"

class RetractHook: public CommandBase
{
public:
	RetractHook();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
