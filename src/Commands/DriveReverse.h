#ifndef DriveReverse_H
#define DriveReverse_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveReverse: public CommandBase
{
public:
	DriveReverse();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
