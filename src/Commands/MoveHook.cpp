#include "MoveHook.h"

MoveHook::MoveHook()
{
	Requires(hook);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void MoveHook::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MoveHook::Execute()
{
	hook->move(-oi->getOperatorStick()->GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool MoveHook::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveHook::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveHook::Interrupted()
{

}
