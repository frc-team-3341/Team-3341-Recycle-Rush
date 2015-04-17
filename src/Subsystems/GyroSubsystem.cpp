#include "GyroSubsystem.h"
#include "../RobotMap.h"

GyroSubsystem::GyroSubsystem() :
		Subsystem("GyroSubsystem")
{
	agyro = new Gyro(new AnalogInput(0));
	agyro->InitGyro();
	agyro->Reset();
}

void GyroSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

double GyroSubsystem::GetAngle()
{
	return -agyro->GetAngle();
}

void GyroSubsystem::ResetGyro()
{
	agyro->Reset();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

