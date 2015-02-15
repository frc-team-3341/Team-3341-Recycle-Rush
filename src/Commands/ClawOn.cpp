#include "ClawOn.h"

ClawOn::ClawOn()
{
	Requires(elevator);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ClawOn::Initialize()
{
	elevator->moveElevator(0);
	elevator->clawOn();
}

// Called repeatedly when this Command is scheduled to run
void ClawOn::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ClawOn::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ClawOn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawOn::Interrupted()
{

}
