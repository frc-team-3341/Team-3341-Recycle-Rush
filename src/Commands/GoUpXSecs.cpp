#include "GoUpXSecs.h"

GoUpXSecs::GoUpXSecs(double time)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(elevator);
}

// Called just before this Command runs the first time
void GoUpXSecs::Initialize()
{
	SetTimeout(1000 * fabs(time));
}

// Called repeatedly when this Command is scheduled to run
void GoUpXSecs::Execute()
{
	if (time >= 0){
		elevator->moveElevator(0.5);
		elevator->clawOn();
	}
	else {
		elevator->moveElevator(-0.5);
		elevator->clawOn();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GoUpXSecs::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void GoUpXSecs::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoUpXSecs::Interrupted()
{

}
