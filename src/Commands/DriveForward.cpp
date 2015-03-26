#include "DriveForward.h"

DriveForward::DriveForward()
{
	Requires(drive);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveForward::Initialize()
{
	drive->setMult(1.0);
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DriveForward::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted()
{

}
