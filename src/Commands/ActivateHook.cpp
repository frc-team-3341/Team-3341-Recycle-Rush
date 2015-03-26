#include "ActivateHook.h"

ActivateHook::ActivateHook()
{
	Requires(hook);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ActivateHook::Initialize()
{
	hook->activate();
}

// Called repeatedly when this Command is scheduled to run
void ActivateHook::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ActivateHook::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ActivateHook::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActivateHook::Interrupted()
{

}
