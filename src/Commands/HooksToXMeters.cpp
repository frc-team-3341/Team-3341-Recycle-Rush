#include <math.h>
#include "HooksToXMeters.h"

HooksToXMeters::HooksToXMeters(double height)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(elevator);

	this->height = height;
	hookElevatorPid = NULL;
}

// Called just before this Command runs the first time
void HooksToXMeters::Initialize()
{
	SetTimeout(7.0);
	hookElevatorPid = new NewPIDController(10.0, 0.0, 0.0, height, false);
}

// Called repeatedly when this Command is scheduled to run
void HooksToXMeters::Execute()
{
	double current_height = elevator->getS2Distance();
	double pwm_val = hookElevatorPid->Tick(current_height);
	printf("Current height: %f; Height error: %f; Last Height PWM: %f\n", current_height, hookElevatorPid->GetError(), hookElevatorPid->GetLastPWM());
	elevator->moveElevator(Drive::Limit(pwm_val, 1.0));
}

// Make this return true when this Command no longer needs to run execute()
bool HooksToXMeters::IsFinished()
{
	return (fabs(hookElevatorPid->GetError()) < 0.01) || (fabs(hookElevatorPid->GetLastPWM()) <= 0.05) || IsTimedOut();
}

// Called once after isFinished returns true
void HooksToXMeters::End()
{
	elevator->moveElevator(0.0);
	delete hookElevatorPid;
	printf("HookToXMeters Finished\n");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HooksToXMeters::Interrupted()
{

}

