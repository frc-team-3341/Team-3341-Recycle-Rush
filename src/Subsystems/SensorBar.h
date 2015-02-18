/*
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
	int* irData;
	int currentVal;
	unsigned char* GetIrs();
	int* getEdges(int list[], int maxI);
	int* convert(unsigned char*);

public:
	SensorBar();
	void InitDefaultCommand();
	int* GetIr();
	void printValues();
	int* getEdges();

};

#endif
*/
