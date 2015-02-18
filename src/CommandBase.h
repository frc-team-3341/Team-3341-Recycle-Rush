#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Hook.h"
#include "Subsystems/GyroSubsystem.h"
#include "Subsystems/Claw.h"
#include "Subsystems/SensorBar.h"

#include "OI.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static Drive* drive;
	static Elevator* elevator;
	static OI *oi;
	static Claw* claw;
	static GyroSubsystem* gyro;
	static Hook* hook;

	//static SensorBar *ir;
};
#endif
