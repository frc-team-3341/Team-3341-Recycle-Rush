#include "CommandBase.h"
#include "Subsystems/Drive.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
Drive* CommandBase::drive = NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drive = new Drive();

	oi = new OI();
}
