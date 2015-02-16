#include "SensorBar.h"
#include "../RobotMap.h"
#include <I2C.h>
#include <wpilib.h>

//I2C arduino;

SensorBar::SensorBar() :
		Subsystem("ExampleSubsystem")
{

}

void SensorBar::InitDefaultCommand()
{

	//arduino = new I2C(Port.kOnboard, 41);
			// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

char* SensorBar::GetIr()
{
	char*irValsInBytes = new char[8];
	I2C::Read(0,5,irValsInBytes);
	return irValsInBytes;

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
