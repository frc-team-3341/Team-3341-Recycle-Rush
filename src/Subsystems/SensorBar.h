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
	I2C* arduino;
	unsigned short irData;
	unsigned char* GetIrs();
	int* getEdges(int list[], int maxI);
public:
	SensorBar();
	void InitDefaultCommand();
	unsigned short* GetIr();
};

#endif
