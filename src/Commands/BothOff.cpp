#include "BothOff.h"

BothOff::BothOff()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void BothOff::Initialize()
{
	elevator->moveElevator(0);
	elevator->bothOff();
}

// Called repeatedly when this Command is scheduled to run
void BothOff::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool BothOff::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void BothOff::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BothOff::Interrupted()
{

}
