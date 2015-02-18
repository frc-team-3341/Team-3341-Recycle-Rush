#include "ClawClose.h"

ClawClose::ClawClose()
{
	Requires(claw);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ClawClose::Initialize()
{
	claw->close();
}

// Called repeatedly when this Command is scheduled to run
void ClawClose::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ClawClose::IsFinished()
{
	return !oi->getOperatorStick()->GetRawButton(4);
}

// Called once after isFinished returns true
void ClawClose::End()
{
	claw->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawClose::Interrupted()
{

}
