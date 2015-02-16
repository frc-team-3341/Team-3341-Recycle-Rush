#include "MoveElevator.h"

MoveElevator::MoveElevator()
{
	Requires(elevator);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void MoveElevator::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MoveElevator::Execute()
{
	elevator->moveElevator(-oi->getOperatorStick()->GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool MoveElevator::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveElevator::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveElevator::Interrupted()
{

}
