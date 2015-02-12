#ifndef ClawOn_H
#define ClawOn_H

#include "../CommandBase.h"
#include "WPILib.h"

class ClawOn: public CommandBase
{
public:
	ClawOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
