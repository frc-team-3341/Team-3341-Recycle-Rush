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
	double y = oi->getOperatorStick()->GetY();
	if(fabs(y) > 0.05)
		elevator->moveElevator(-y);
	else
		elevator->moveElevator(0.0);
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

