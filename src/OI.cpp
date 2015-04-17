#include "OI.h"
#include "Commands/ClawOn.h"
#include "Commands/ClawOff.h"
#include "Commands/ClawOpen.h"
#include "Commands/ClawClose.h"
#include "Commands/ActivateHook.h"
#include "Commands/StopHook.h"
#include "Commands/DriveReverse.h"
#include "Commands/DriveForward.h"
#include "Commands/BothOn.h"
#include "Commands/BothOff.h"
#include "Commands/CVAlignTote.h"
#include "Commands/GetStepResponse.h"
#include "Commands/ToggleRotationCurve.h"
#include "NetworkTablesInterface.h"
#include "CommandBase.h"

OI::OI() :
 driveStick(new Joystick(DRIVESTICK)), operatorStick(new Joystick(OPERATORSTICK))
{
	Button* driveTrigger = new JoystickButton(driveStick, 1);
	driveTrigger->WhenPressed(new DriveReverse());
	driveTrigger->WhenReleased(new DriveForward());
	Button* toggleRotationCurve = new JoystickButton(driveStick, 5);
	toggleRotationCurve->WhenPressed(new ToggleRotationCurve());
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
	Button* autoMoveButton = new JoystickButton(operatorStick, 5);
	autoMoveButton->WhenPressed (new CVAlignTote());
	Button* hookButton = new JoystickButton(operatorStick, 7);
	hookButton->WhenPressed(new ActivateHook());
	hookButton->WhenReleased(new StopHook());
}

Joystick* OI::getDriveStick(){
	return driveStick;
}

Joystick* OI::getOperatorStick(){
	return operatorStick;
}

