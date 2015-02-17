#include <Commands/WaitCmd.h>

WaitCmd::WaitCmd(double seconds)
{
	SetTimeout(seconds);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void WaitCmd::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void WaitCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitCmd::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void WaitCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitCmd::Interrupted()
{

}
