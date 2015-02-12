#ifndef ClawOff_H
#define ClawOff_H

#include "../CommandBase.h"
#include "WPILib.h"

class ClawOff: public CommandBase
{
public:
	ClawOff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
