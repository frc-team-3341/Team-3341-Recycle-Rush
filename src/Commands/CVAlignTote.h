#ifndef CVALIGNTOTE_H
#define CVALIGNTOTE_H

#include <NewPIDController.h>
#include "../CommandBase.h"
#include "WPILib.h"

class CVAlignTote : public CommandBase
{
public:
	CVAlignTote();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	NewPIDController* distance_ctl;
	NewPIDController* azimuth_ctl;
};

#endif
