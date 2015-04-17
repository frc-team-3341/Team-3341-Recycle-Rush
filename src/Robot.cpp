#include "WPILib.h"
#include "NetworkTablesInterface.h"
#include "Commands/Command.h"
#include "Commands/AutonomousProgram.h"
#include "CommandBase.h"
#include <stdint.h>

class Robot: public IterativeRobot
{
private:
	AutonomousProgram *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = new AutonomousProgram();
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
		CommandBase::drive->ResetEncoders();
		CommandBase::gyro->ResetGyro();
	}

	void TeleopPeriodic()
	{
		//SmartDashboard::PutBoolean("Tote Found", NetworkTablesInterface::GetInstance()->ToteFound());
		//SmartDashboard::PutNumber("Distance", NetworkTablesInterface::GetInstance()->GetDistance());
		//SmartDashboard::PutNumber("Azimuth", NetworkTablesInterface::GetInstance()->GetAzimuth());
//		if(NetworkTablesInterface::GetInstance()->ToteFound()){
//			printf("Distance: %f; Azimuth: %f\n", NetworkTablesInterface::GetInstance()->GetDistance(),
//					NetworkTablesInterface::GetInstance()->GetAzimuth());
//		}

		//printf("Gyro Angle: %f\n", CommandBase::gyro->GetAngle());
		Scheduler::GetInstance()->Run();
		//CommandBase::ir->printValues();
		//printf("Ticks: %f\n", CommandBase::elevator->getS2Distance());
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);


