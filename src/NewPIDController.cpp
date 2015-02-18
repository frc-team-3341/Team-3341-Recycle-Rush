#include <NewPIDController.h>

NewPIDController::NewPIDController(double Kp, double Ki, double Kd, double setPoint, bool integralThreshold)
	:lastPWM(0),error(0)
{
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	this->setPoint = setPoint;
	this->integralThreshold = integralThreshold;
	previousError = 0.0;
	integral = 0.0;
}

double NewPIDController::Tick(double measuredValue)
{
	error = setPoint - measuredValue;
	if(integralThreshold){
		if(error <= .1)
			integral += error;
	}
	else
		integral +=error;
	double derivative = error - previousError;
	previousError = error;

	lastPWM = Kp * error + Ki * integral + Kd * derivative;
	return lastPWM;
}

void NewPIDController::SetSetPoint(double setPoint)
{
	this->setPoint = setPoint;
	integral = 0;
	previousError = 0;
	error = 0;
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

double NewPIDController::GetError()
{
	return error;
}

double NewPIDController::GetLastPWM()
{
	return lastPWM;
}
