#include "ClawOpen.h"

ClawOpen::ClawOpen()
{
	Requires(claw);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ClawOpen::Initialize()
{
	claw->open();
}

// Called repeatedly when this Command is scheduled to run
void ClawOpen::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ClawOpen::IsFinished()
{
	return !oi->getOperatorStick()->GetRawButton(3);
}

// Called once after isFinished returns true
void ClawOpen::End()
{
	claw->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawOpen::Interrupted()
{

}
