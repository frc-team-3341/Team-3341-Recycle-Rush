#ifndef Hook_H
#define Hook_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Hook: public Subsystem
{
private:
	Jaguar* hookControl;
	bool active;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	bool isActive();
	void move(float val);
	void activate();
	void stop();
	Hook();
	void InitDefaultCommand();
};

#endif
