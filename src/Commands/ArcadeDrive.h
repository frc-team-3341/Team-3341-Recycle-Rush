#ifndef ArcadeDrive_H
#define ArcadeDrive_H

#include "../CommandBase.h"
#include "../NewPIDController.h"
#include "WPILib.h"

class ArcadeDrive: public CommandBase
{
public:
	ArcadeDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isReset;
	NewPIDController* anglePid;
};

#endif
