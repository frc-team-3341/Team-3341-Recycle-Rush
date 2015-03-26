/*
#include "SensorBar.h"
#include "../RobotMap.h"
//#include <I2C.h>
#include <wpilib.h>
#include <stdint.h>

SensorBar::SensorBar() :Subsystem("SensorBar")
{

	enum I2C::Port a = I2C::Port::kOnboard;
	unsigned char num = (unsigned char)41;
	arduino = new I2C(a, num);
	irData = NULL;
}

void SensorBar::InitDefaultCommand()
{

	//arduino = new I2C(Port.kOnboard, 41);
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

int* SensorBar::GetIr()
{
	//GetIrs();
	unsigned char data[16];
	bool returnFailed = arduino->Read(41, 16, data);
	//at this point, data has recieved the array of ir values
	if(!returnFailed){
		int* finalData = convert(data);
		irData = finalData;
		return finalData;//returns this data, if needed
	}
	else{
		return NULL;
	}
}
//private method
int* SensorBar::convert(unsigned char* bytes){
	int newData[4];
	for(int j = 0; j < 4; j++){
		int temp;
		for(int i = 0; i < 4; i++){
			temp = i | j;
		}
		newData[j] = temp;
	}
	return newData;
}
//private method
unsigned char* SensorBar::GetIrs(){



	return NULL;
}
int* SensorBar::getEdges(){

	return SensorBar::getEdges(irData, 4);
}
int* SensorBar::getEdges(int list[], int maxI){

	int k, j, l, first = 0, last = 0;
	j = list[0] - list[1];
	l = list[0] - list[1];
	for (int i = 0; i < maxI - 1; i++)
	{
		k = list[i] - list[i + 1];
		if (k > j)
		{
			j = k;
		}
		else if (k < l)
		{
			l = k;
		}
	}

	//System.out.println(j + "and" + l);

	for (int i = 0; i < maxI - 1; i++)
	{
		k = list[i] - list[i + 1];
		if (k == l)
		{
			last = i + 1;
		}
	}
	for (int i = maxI - 1; i > 0; i--)
	{
		k = list[i - 1] - list[i];
		if (k == j)
		{
			first = i - 1;
		}
	}

	int newArray[2] = {first, last};

	//System.out.println(list.get(first) + "and" + list.get(last));



	return NULL;

}

void SensorBar::printValues(){
	for(int i = 0; i < 7; ++i)
	{
		printf("Sensor %d: %d ;", i, irData[i]);
	}

	printf("\n");
}
//private method

// Put methods for controlling this subsystem
// here. Call these from Commands.
 * */

