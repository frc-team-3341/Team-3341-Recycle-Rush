#ifndef ToggleRotationCurve_H
#define ToggleRotationCurve_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleRotationCurve: public CommandBase
{
public:
	ToggleRotationCurve();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

