#include "PIDController.h"

PIDController::PIDController(double Kp, double Ki, double Kd, double setPoint)
{
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	this->setPoint = setPoint;

	previousError = 0.0;
	integral = 0.0;
}

double PIDController::Tick(double measuredValue)
{
	double error = setPoint - measuredValue;
	integral += error;
	double derivative = error - previousError;
	previousError = error;

	return Kp * error + Ki * integral + Kd * derivative;
}

void PIDController::SetSetPoint(double setPoint)
{
	this->setPoint = setPoint;
}

void double PIDController::GetSetPoint()
{
	return setPoint;
}

void PIDController::SetKp(double Kp)
{
	this->Kp = Kp;
}

double PIDController::GetKp()
{
	return Kp;
}

void PIDController::SetKi(double Ki)
{
	this->Ki = Ki;
}

double PIDController::GetKi()
{
	return Ki;
}

void PIDController::SetKd(double Kd)
{
	this->Kd = Kd;
}

double PIDController::GetKd()
{
	return Kd;
}
