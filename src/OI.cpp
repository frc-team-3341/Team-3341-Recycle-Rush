#include "OI.h"
#include "Commands/ClawOn.h"
#include "Commands/ClawOff.h"


OI::OI() :
 driveStick(new Joystick(DRIVESTICK)), operatorStick(new Joystick(OPERATORSTICK))
{
	Button* trigger = new JoystickButton(operatorStick, 1);
	trigger->WhenPressed(new ClawOn());
	trigger->WhenReleased(new ClawOff());
	// Process operator interface input here.
}

Joystick* OI::getDriveStick(){
	return driveStick;
}

Joystick* OI::getOperatorStick(){
	return operatorStick;
}
