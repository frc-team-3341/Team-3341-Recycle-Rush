#include "Hook.h"
#include "../CommandBase.h"
#include "../Commands/MoveHook.h"
#include "../RobotMap.h"

Hook::Hook()
	:	Subsystem("Hook"), hookControl(new Jaguar(HOOK)), active(false)
{

}

//TODO FIX DIRECTION IF NECESSARY
void Hook::activate(){
	active = true;
}

bool Hook::isActive(){
	return active;
}

void Hook::move(float val){
	if(active)
	{
		CommandBase::elevator->hardStop();
		hookControl->Set(val);
	}
}
void Hook::stop(){
	active = false;
	hookControl->Set(0.0);
}

void Hook::InitDefaultCommand()
{
	SetDefaultCommand(new MoveHook());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
