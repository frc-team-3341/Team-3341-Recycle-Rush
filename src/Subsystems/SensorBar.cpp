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
	GetIrs();

	if(returnSuccesfully){
		return irValsInBytes;
	}
	else{
		return NULL;
	}
}
//private method
unsigned char* SensorBar::GetIrs(){


		unsigned short data[16];
		bool returnSuccesfully = arduino->Read(1 /*arbutrary register */, 8 * sizeof(data[0]),data);
	return NULL;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
