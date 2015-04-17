#include "Commands/ResetElevatorEncoders.h"
#include "Commands/HooksToXMeters.h"
#include "Commands/TurnAndDrive.h"
#include "AutonomousProgram.h"

AutonomousProgram::AutonomousProgram()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	/*AddSequential(new TurnAndDrive(0.03, 0.0));
	AddSequential(new ResetElevatorEncoders());
	AddSequential(new HooksToXMeters(0.20));
	AddSequential(new TurnAndDrive(-2.0, 0.0));
	AddSequential(new HooksToXMeters(0.05));
	AddSequential(new TurnAndDrive(-0.05, 0.0));*/
}
