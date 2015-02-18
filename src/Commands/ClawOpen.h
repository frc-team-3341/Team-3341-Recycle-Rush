#ifndef ClawOpen_H
#define ClawOpen_H

#include "../CommandBase.h"
#include "WPILib.h"

class ClawOpen: public CommandBase
{
public:
	ClawOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
