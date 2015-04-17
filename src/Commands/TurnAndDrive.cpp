#include <Commands/TurnAndDrive.h>
#include "../NetworkTablesInterface.h"

TurnAndDrive::TurnAndDrive(double inDistance, double inAngle)
	: distance(inDistance), angle(inAngle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drive);
	Requires(gyro);
	distancePid = NULL;
	anglePid = NULL;
}

// Called just before this Command runs the first time
void TurnAndDrive::Initialize()
{
	SetTimeout(2.2);
	drive->ResetEncoders();
	gyro->ResetGyro();
	distancePid = new NewPIDController(1.0, 0.05, 0.0, distance, true);
	anglePid = new NewPIDController(0.03, 1e-3, 0, angle, false);
}

// Called repeatedly when this Command is scheduled to run
void TurnAndDrive::Execute()
{
	double current_distance = drive->GetDistance();
	double pwm_val = distancePid->Tick(current_distance);
	double current_angle = gyro->GetAngle();
	double rotateVal = anglePid->Tick(current_angle);
	printf("Distance setpoint: %f; Current distance: %f; Distance error: %f; Distance Last PWM: %f; Distance rate: %f\n",
			distancePid->GetSetPoint(), current_distance, distancePid->GetError(), distancePid->GetLastPWM(), drive->GetRate());
	drive->arcadeDrive(Drive::Limit(pwm_val, .5), Drive::Limit(rotateVal, 1.0));
	//printf("Setpoint: %f\nCurrent Distance: %f\nError: %f\nPWM Value: %f\n\n", distancePid->GetSetPoint(), current_distance, distancePid->GetError(), pwm_val);
	//printf("Setpoint: %f\nCurrent Angle: %f\nError: %f\nPWM Value: %f\n\n", anglePid->GetSetPoint(), current_angle, anglePid->GetError(), rotateVal);
	//printf("%f", current_distance);
	//	if (distance >= 0){
//		drive->arcadeDrive(.5,0);
//	}
//	else {
//		drive -> arcadeDrive (-.5,0);
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool TurnAndDrive::IsFinished()
{
	return (((fabs(distancePid->GetError()) < 0.005) && (fabs(anglePid->GetError()) < 0.5) && (fabs(drive->GetRate()) < 1e-3)) || IsTimedOut());
}

// Called once after isFinished returns true
void TurnAndDrive::End()
{
	drive->arcadeDrive(0,0);
	printf("TurnAndDrive Finished!\n");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnAndDrive::Interrupted()
{

}

