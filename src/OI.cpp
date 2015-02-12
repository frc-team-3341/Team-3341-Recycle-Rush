#include "OI.h"

OI::OI() :
 driveStick(new Joystick(DRIVESTICK)), operatorStick(new Joystick(OPERATORSTICK))
{

	// Process operator interface input here.
}

Joystick* OI::getDriveStick(){
	return driveStick;
}

Joystick* OI::getOperatorStick(){
	return operatorStick;
}
