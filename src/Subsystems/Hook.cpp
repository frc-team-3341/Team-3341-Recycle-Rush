#include "Hook.h"
#include "../RobotMap.h"

Hook::Hook()
	:	Subsystem("Hook"), hookControl(new Jaguar(HOOK))
{

}

//TODO FIX DIRECTION IF NECESSARY
void Hook::deploy(){
	hookControl->Set(.1);
}

void Hook::retract(){
	hookControl->Set(-.1);
}

void Hook::stop(){
	hookControl->Set(0);
}

void Hook::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
