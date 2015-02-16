#include <Commands/DriveXMeters.h>

DriveXMeters::DriveXMeters(double inDistance)
	: distance(inDistance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drive);
}

// Called just before this Command runs the first time
void DriveXMeters::Initialize()
{
	drive->ResetEncoders();
	pid = new NewPIDController(0.75, 0, 0, distance);
}

// Called repeatedly when this Command is scheduled to run
void DriveXMeters::Execute()
{
	double current_distance = drive->GetDistance();
	double pwm_val = pid->Tick(current_distance);
	drive->arcadeDrive(Drive::Limit(pwm_val,.5), 0);
	//printf("Setpoint: %f\nCurrent Distance: %f\nError: %f\nPWM Value: %f\n\n", pid->GetSetPoint(), current_distance, pid->GetError(), pwm_val);
//	if (distance >= 0){
//		drive->arcadeDrive(.5,0);
//	}
//	else {
//		drive -> arcadeDrive (-.5,0);
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveXMeters::IsFinished()
{
	return (fabs(pid->GetError()) < 0.005);
}

// Called once after isFinished returns true
void DriveXMeters::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveXMeters::Interrupted()
{

}
