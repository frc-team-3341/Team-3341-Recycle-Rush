#include <NewPIDController.h>
#include "../NetworkTablesInterface.h"
#include "CVAlignTote.h"

CVAlignTote::CVAlignTote()
{
	Requires(drive);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void CVAlignTote::Initialize()
{
	// Goal is to get to 2 feet away and pointed directly at the tote
	distance_ctl = new NewPIDController(1e-1, 0, 0, 0.6096 /* 2 feet in meters */);
	azimuth_ctl = new NewPIDController(1e-1, 0, 0, 0);
	
}

// Called repeatedly when this Command is scheduled to run
void CVAlignTote::Execute()
{
	if (NetworkTablesInterface::GetInstance()->ToteFound())
	{
		drive->arcadeDrive(distance_ctl->Tick(NetworkTablesInterface::GetInstance()->GetDistance()),
				   azimuth_ctl->Tick(NetworkTablesInterface::GetInstance()->GetAzimuth()));
	}
	else
	{
		drive->arcadeDrive(0, 0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CVAlignTote::IsFinished()
{
	return !NetworkTablesInterface::GetInstance()->ToteFound();
}

// Called once after isFinished returns true
void CVAlignTote::End()
{
	delete distance_ctl;
	delete azimuth_ctl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CVAlignTote::Interrupted()
{

}
