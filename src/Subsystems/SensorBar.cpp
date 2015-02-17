#include "SensorBar.h"
#include "../RobotMap.h"
//#include <I2C.h>
#include <wpilib.h>
#include <stdint.h>

SensorBar::SensorBar() :Subsystem("SensorBar")
{
	enum I2C::Port a = I2C::Port::kOnboard;
	unsigned char num = (unsigned char)41;
	arduino = new I2C(a, num);
}

void SensorBar::InitDefaultCommand()
{

	//arduino = new I2C(Port.kOnboard, 41);
			// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

unsigned char* SensorBar::GetIr()
{
	unsigned char* irValsInBytes;
	bool returnSuccesfully = arduino->Read(41,5,irValsInBytes);
	if(returnSuccesfully){
		return irValsInBytes;
	}
	else{
		return NULL;
	}

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
