#include "WPILib.h"
#include "NetworkTablesInterface.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include <stdint.h>

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
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

/*

		//char irVals[8] = {0,0,0,0,0,0,0,0};
<<<<<<< HEAD
		unsigned char *irVals;
		irVals = CommandBase::ir->GetIr();
		for(int i = 0; i < 8; i++){
			//SmartDashboard::PutNumber("IR Data:, ", (double)irVals[i]);
=======
		//unsigned char *irVals;
		//irVals = CommandBase::ir->GetIr();
		//for(int i = 0; i < 8; i++){
			//SmartDashboard::PutNumber("IR Data:, ", (double)irVals[i]);

		//}
>>>>>>> 900d5b39bab71ae7c90fccf1b571e2ca5588a1aa*/

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

