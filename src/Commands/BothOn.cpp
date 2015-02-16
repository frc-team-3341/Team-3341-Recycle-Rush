#include "BothOn.h"

BothOn::BothOn()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void BothOn::Initialize()
{
	elevator->moveElevator(0);
	elevator->bothOn();
}

// Called repeatedly when this Command is scheduled to run
void BothOn::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool BothOn::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void BothOn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BothOn::Interrupted()
{

}
