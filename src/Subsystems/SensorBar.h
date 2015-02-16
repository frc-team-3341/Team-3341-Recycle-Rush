#ifndef SensorBar_H
#define SensorBar_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <I2C.h>


class SensorBar: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	SensorBar();
	void InitDefaultCommand();
	char* GetIr();
};

#endif
