#ifndef BothOn_H
#define BothOn_H

#include "../CommandBase.h"
#include "WPILib.h"

class BothOn: public CommandBase
{
public:
	BothOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
