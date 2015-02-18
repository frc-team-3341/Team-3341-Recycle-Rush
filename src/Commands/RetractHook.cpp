#include "RetractHook.h"

RetractHook::RetractHook()
{
	Requires(hook);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void RetractHook::Initialize()
{
	hook->retract();
}

// Called repeatedly when this Command is scheduled to run
void RetractHook::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool RetractHook::IsFinished()
{
	return !oi->getDriveStick()->GetRawButton(2);
}

// Called once after isFinished returns true
void RetractHook::End()
{
	hook->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RetractHook::Interrupted()
{

}
