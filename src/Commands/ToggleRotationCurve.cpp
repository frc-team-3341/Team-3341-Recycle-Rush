#include "ToggleRotationCurve.h"

ToggleRotationCurve::ToggleRotationCurve()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drive);
}

// Called just before this Command runs the first time
void ToggleRotationCurve::Initialize()
{
	drive->toggleRotationCurve();
}

// Called repeatedly when this Command is scheduled to run
void ToggleRotationCurve::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleRotationCurve::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleRotationCurve::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleRotationCurve::Interrupted()
{

}
