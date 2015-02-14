#ifndef CVALIGNTOTE_H
#define CVALIGNTOTE_H

#include "../CommandBase.h"
#include "../PIDController.h"
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
	PIDController* distance_ctl;
	PIDController* azimuth_ctl;
};

#endif
