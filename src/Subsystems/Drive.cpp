#include "Drive.h"
#include "../RobotMap.h"
#include <math.h>
#include "Commands/ArcadeDrive.h"
#define max(x, y) (((x) > (y)) ? (x) : (y))

Drive::Drive() :
		Subsystem("Drive"), left(new Talon(DRIVE_LEFT)), right(new Talon(DRIVE_RIGHT)),
		eLeft(new Encoder(ENCODER_LEFT_1, ENCODER_LEFT_2)),
		eRight(new Encoder(ENCODER_RIGHT_1, ENCODER_RIGHT_2))
{
}

void Drive::arcadeDrive(float moveValue, float rotateValue){
		float leftMotorOutput;
		float rightMotorOutput;

		moveValue = Limit(moveValue);
		rotateValue = Limit(rotateValue);

		if (moveValue > 0.0)
		{
			if (rotateValue > 0.0)
			{
				leftMotorOutput = moveValue - rotateValue;
				rightMotorOutput = max(moveValue, rotateValue);
			}
			else
			{
				leftMotorOutput = max(moveValue, -rotateValue);
				rightMotorOutput = moveValue + rotateValue;
			}
		}
		else
		{
			if (rotateValue > 0.0)
			{
				leftMotorOutput = - max(-moveValue, rotateValue);
				rightMotorOutput = moveValue + rotateValue;
			}
			else
			{
				leftMotorOutput = moveValue - rotateValue;
				rightMotorOutput = - max(-moveValue, -rotateValue);
			}
		}
		double mult;
		//if((moveValue >= 0.01 && rotateValue >= 0.01) || eRight->GetRate() == 0)
			mult = 1;
		//else
		//	mult = abs(eLeft->GetRate())/abs(eRight->GetRate());
		float limitedL = Limit(leftMotorOutput);
		float limitedR = Limit(((float) mult)*rightMotorOutput);
		printf("%f, %f\n", eLeft->GetRate(), eRight->GetRate());
		left->Set(limitedL);
		right->Set(limitedR);
}

float Drive::Limit(float num)
{
	if (num > 1.0)
	{
		return 1.0;
	}
	if (num < -1.0)
	{
		return -1.0;
	}
	return num;
}

double Drive::GetDistance()
{
	return (eLeft->GetDistance() + eRight->GetDistance()) / 2.0;
}

void Drive::InitDefaultCommand()
{
	SetDefaultCommand(new ArcadeDrive());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
