#include "NetworkTablesInterface.h"

NetworkTablesInterface::NetworkTablesInterface() :
	toteFound_bool(false), distance_m(-1),
	table(NetworkTable::GetTable("cv")), azimuth_deg(-1)
{

}

NetworkTablesInterface* NetworkTablesInterface::nti = NULL;

NetworkTablesInterface::~NetworkTablesInterface()
{
	delete nti;
}

NetworkTablesInterface* NetworkTablesInterface::GetInstance()
{
	if(!nti){
		nti = new NetworkTablesInterface();
	}
	return nti;
}

void NetworkTablesInterface::Update()
{
	toteFound_bool = table->GetBoolean("toteFound", false);
	if(toteFound_bool){
		distance_m = table->GetNumber("distance_m", -1);
		azimuth_deg = table->GetNumber("azimuth_deg", -1);
	}
}

bool NetworkTablesInterface::ToteFound()
{
	return toteFound_bool;
}

double NetworkTablesInterface::GetDistance()
{
	return distance_m;
}

double NetworkTablesInterface::GetAzimuth()
{
	return azimuth_deg;
}
