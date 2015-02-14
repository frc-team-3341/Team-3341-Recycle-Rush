#include <NewPIDController.h>

NewPIDController::NewPIDController(double Kp, double Ki, double Kd, double setPoint)
{
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	this->setPoint = setPoint;

	previousError = 0.0;
	integral = 0.0;
}

double NewPIDController::Tick(double measuredValue)
{
	double error = setPoint - measuredValue;
	integral += error;
	double derivative = error - previousError;
	previousError = error;

	return Kp * error + Ki * integral + Kd * derivative;
}

void NewPIDController::SetSetPoint(double setPoint)
{
	this->setPoint = setPoint;
}

double NewPIDController::GetSetPoint()
{
	return setPoint;
}

void NewPIDController::SetKp(double Kp)
{
	this->Kp = Kp;
}

double NewPIDController::GetKp()
{
	return Kp;
}

void NewPIDController::SetKi(double Ki)
{
	this->Ki = Ki;
}


double NewPIDController::GetKi()
{
	return Ki;
}

void NewPIDController::SetKd(double Kd)
{
	this->Kd = Kd;
}

double NewPIDController::GetKd()
{
	return Kd;
}
