#ifndef Drive_H
#define Drive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drive: public Subsystem
{
private:
	Talon* left;
	Talon* right;
	Encoder* eLeft;
	Encoder* eRight;
	float mult;
	bool rotationCurve;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	void toggleRotationCurve();
	bool getRotationCurve();
	void setMult(float m);
	Drive();
	void arcadeDrive(float move, float rotate);
	double GetDistance();
	double GetRate();
	void ResetEncoders();
	void InitDefaultCommand();
	static float Limit(float num, float max);
	//void ResetGyro();
};

#endif

