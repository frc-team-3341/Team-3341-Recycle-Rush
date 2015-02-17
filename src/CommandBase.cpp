#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
Drive* CommandBase::drive = NULL;
Elevator* CommandBase::elevator = NULL;
OI* CommandBase::oi = NULL;
<<<<<<< HEAD
GyroSubsystem* CommandBase::gyro = NULL;

=======
SensorBar* CommandBase::ir = NULL;
>>>>>>> FETCH_HEAD
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
	elevator = new Elevator();
	oi = new OI();
<<<<<<< HEAD
	gyro = new GyroSubsystem();
=======
	ir = new SensorBar();
>>>>>>> FETCH_HEAD
}
