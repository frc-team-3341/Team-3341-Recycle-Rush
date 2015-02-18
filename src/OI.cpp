#include "OI.h"
#include "Commands/ClawOn.h"
#include "Commands/ClawOff.h"
#include "Commands/ClawOpen.h"
#include "Commands/ClawClose.h"
#include "Commands/DeployHook.h"
#include "Commands/RetractHook.h"
#include "Commands/BothOn.h"
#include "Commands/BothOff.h"
#include "Commands/CVAlignTote.h"
#include "Commands/GetStepResponse.h"
#include "NetworkTablesInterface.h"

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
	Button* clawOpen = new JoystickButton(operatorStick, 3);
	clawOpen->WhenPressed(new ClawOpen());
	Button* clawClose = new JoystickButton(operatorStick, 4);
	clawClose->WhenPressed(new ClawClose());
	Button* deployHook = new JoystickButton(driveStick, 1);
	deployHook->WhenPressed(new DeployHook());
	Button* retractHook = new JoystickButton(driveStick, 2);
	retractHook->WhenPressed(new RetractHook());
	// Automove control
	Button* autoMoveButton = new JoystickButton (operatorStick,5);
	autoMoveButton ->WhenPressed (new CVAlignTote());

	// Step response control
	//Button* stepresponse_button = new JoystickButton(operatorStick, 6);
	//stepresponse_button->WhenPressed(new GetStepResponse());
	// Process operator interface input here.

}

Joystick* OI::getDriveStick(){
	return driveStick;
}

Joystick* OI::getOperatorStick(){
	return operatorStick;
}
