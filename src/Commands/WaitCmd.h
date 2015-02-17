#ifndef Wait_H
#define Wait_H

#include "../CommandBase.h"
#include "WPILib.h"

class WaitCmd: public CommandBase
{
public:
	WaitCmd(double seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
