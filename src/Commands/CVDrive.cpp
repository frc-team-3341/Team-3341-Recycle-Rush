#include "CVDrive.h"
#include "../NetworkTablesInterface.h"

CVDrive::CVDrive()
{
	Requires(drive);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void CVDrive::Initialize()
{
	if(NetworkTablesInterface::ToteFound()){
		distance = NetworkTablesInterface::GetDistance() - .05;
		angle = NetworkTablesInterface::GetAzimuth();
	}
	else{
		distance = 0;
		angle = 0;
	}
	drive->ResetEncoders();
	gyro->ResetGyro();
	distancePid = new NewPIDController(1.3125, 0, 0, distance);
	anglePid = new NewPIDController(.05, 0, 0, -angle);
}

// Called repeatedly when this Command is scheduled to run
void CVDrive::Execute()
{
	double current_distance = drive->GetDistance();
	double pwm_val = distancePid->Tick(current_distance);
	double current_angle = gyro->GetAngle();
	double rotateVal = anglePid->Tick(current_angle);
	drive->arcadeDrive(Drive::Limit(pwm_val,.5), -Drive::Limit(rotateVal, 1.0));
}

// Make this return true when this Command no longer needs to run execute()
bool CVDrive::IsFinished()
{
	return (fabs(distancePid->GetError()) < 0.005 && fabs(anglePid->GetError()) < 0.7);
}

// Called once after isFinished returns true
void CVDrive::End()
{
	drive->arcadeDrive(0,0);
	delete distancePid;
	delete anglePid;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CVDrive::Interrupted()
{

}
