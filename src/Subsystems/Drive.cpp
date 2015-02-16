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
			//eLeft->SetDistancePerPulse(1.219);
			//eRight->SetDistancePerPulse(1.219);
}

void Drive::ResetEncoders()
{
	eLeft->Reset();
	eRight->Reset();
}

void Drive::arcadeDrive(float moveValue, float rotateValue){
		float leftMotorOutput;
		float rightMotorOutput;

		moveValue = Drive::Limit(moveValue,1.0);
		rotateValue = Drive::Limit(rotateValue,1.0);

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
		float limitedL = Drive::Limit(leftMotorOutput,1.0);
		float limitedR = -Drive::Limit(rightMotorOutput,1.0);
		//printf("%f, %f\n", eLeft->GetRate(), eRight->GetRate());
		left->Set(limitedL);
		right->Set(limitedR);
}

float Drive::Limit(float num, float max)
{
	if (num > max)
	{
		return max;
	}
	if (num < -max)
	{
		return -max;
	}
	return num;
}

double Drive::GetDistance()
{
	return -((double)((eLeft->Get())) - (double)((eRight->Get()))) / 2.0;
}

void Drive::InitDefaultCommand()
{
	SetDefaultCommand(new ArcadeDrive());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
