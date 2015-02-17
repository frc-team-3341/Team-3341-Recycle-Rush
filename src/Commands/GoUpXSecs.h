#ifndef GoUpXSecs_H
#define GoUpXSecs_H

#include "../CommandBase.h"
#include "WPILib.h"

class GoUpXSecs: public CommandBase
{
public:
	GoUpXSecs(double time);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double time;
};

#endif
