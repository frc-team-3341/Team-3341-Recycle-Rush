#include "DriveReverse.h"

DriveReverse::DriveReverse()
{
	Requires(drive);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveReverse::Initialize()
{
	drive->setMult(-1.0);
}

// Called repeatedly when this Command is scheduled to run
void DriveReverse::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveReverse::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DriveReverse::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveReverse::Interrupted()
{

}
