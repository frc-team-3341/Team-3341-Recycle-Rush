#include "ResetElevatorEncoders.h"

ResetElevatorEncoders::ResetElevatorEncoders()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(elevator);
}

// Called just before this Command runs the first time
void ResetElevatorEncoders::Initialize()
{
	elevator->resetS2Distance();
}

// Called repeatedly when this Command is scheduled to run
void ResetElevatorEncoders::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetElevatorEncoders::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetElevatorEncoders::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetElevatorEncoders::Interrupted()
{

}

