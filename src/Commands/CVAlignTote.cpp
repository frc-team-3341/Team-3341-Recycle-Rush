#include "CVAlignTote.h"
#include "CVDrive.h"
#include "math.h"
#include "TurnAndDrive.h"
#include "WaitCmd.h"
CVAlignTote::CVAlignTote()
{
	//for explanation look at diagram
	AddSequential(new CVDrive());
	//AddSequential(new TurnAndDrive(-0.25,0)); //moving backwards y1
	//AddSequential(new TurnAndDrive(0,-20)); //turning theta degrees (look at diagram) where x = 0.3
	//AddSequential(new TurnAndDrive(0.1,0)); //moving forward y2
	//AddSequential(new TurnAndDrive(0, 20)); //turning back to straight original position
	//AddSequential(new TurnAndDrive(0.125,0)); // moving forward to its position next to the tote*/
	//AddSequential(new TurnAndDrive(2, 0));

}
