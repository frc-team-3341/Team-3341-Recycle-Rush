#include "OI.h"
#include "Commands/ClawOn.h"
#include "Commands/ClawOff.h"
#include "Commands/BothOn.h"
#include "Commands/BothOff.h"
#include "Commands/CVAlignTote.h"

OI::OI() :
 driveStick(new Joystick(DRIVESTICK)), operatorStick(new Joystick(OPERATORSTICK))
{
	// Claw control
	Button* trigger = new JoystickButton(operatorStick, 1);
	trigger->WhenPressed(new ClawOn());
	trigger->WhenReleased(new ClawOff());
	Button* both = new JoystickButton(operatorStick, 2);
	both->WhenPressed(new BothOn());
	both->WhenReleased(new BothOff());

	// CV auto-align control
	Button* cvaligntote_button = new JoystickButton(operatorStick, 4);
	cvaligntote_button->ToggleWhenPressed(new CVAlignTote());
	// Process operator interface input here.
}

Joystick* OI::getDriveStick(){
	return driveStick;
}

Joystick* OI::getOperatorStick(){
	return operatorStick;
}
