#include "ClawOff.h"

ClawOff::ClawOff()
{
	Requires(elevator);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ClawOff::Initialize()
{
	elevator->moveElevator(0);
	elevator->clawOff();
}

// Called repeatedly when this Command is scheduled to run
void ClawOff::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ClawOff::IsFinished()
{

	return true;
}

// Called once after isFinished returns true
void ClawOff::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawOff::Interrupted()
{

}
