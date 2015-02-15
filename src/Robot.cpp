#include "WPILib.h"
#include "NetworkTablesInterface.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		NetworkTablesInterface::GetInstance()->Update();
		CommandBase::init();
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		NetworkTablesInterface::GetInstance()->Update();
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		NetworkTablesInterface::GetInstance()->Update();
		if(NetworkTablesInterface::GetInstance()->ToteFound()){
			printf("Distance: %f; Azimuth: %f\n", NetworkTablesInterface::GetInstance()->GetDistance(),
					NetworkTablesInterface::GetInstance()->GetAzimuth());
		}
		//else
			//printf("Tote not found\n");
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

