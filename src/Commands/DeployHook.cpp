#include "DeployHook.h"

DeployHook::DeployHook()
{
	Requires(hook);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DeployHook::Initialize()
{
	hook->deploy();
}

// Called repeatedly when this Command is scheduled to run
void DeployHook::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DeployHook::IsFinished()
{
	return !oi->getDriveStick()->GetRawButton(1);
}

// Called once after isFinished returns true
void DeployHook::End()
{
	hook->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DeployHook::Interrupted()
{

}
