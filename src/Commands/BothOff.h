#ifndef BothOff_H
#define BothOff_H

#include "../CommandBase.h"
#include "WPILib.h"

class BothOff: public CommandBase
{
public:
	BothOff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
