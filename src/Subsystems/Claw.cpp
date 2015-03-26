#include "Claw.h"
#include "../RobotMap.h"

Claw::Claw() :
		Subsystem("Claw"), left(new Jaguar(CLAW_LEFT)), right(new Jaguar(CLAW_RIGHT))
{

}

void Claw::stop(){
	left->Set(0);
	right->Set(0);
}

void Claw::open(){
	left->Set(.4);
	right->Set(-.6);
}

void Claw::close(){
	left->Set(-.4);
	right->Set(.6);
}


void Claw::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
