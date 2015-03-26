#include "StopHook.h"

StopHook::StopHook()
{
	Requires(hook);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void StopHook::Initialize()
{
	hook->stop();
}

// Called repeatedly when this Command is scheduled to run
void StopHook::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StopHook::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void StopHook::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopHook::Interrupted()
{

}
