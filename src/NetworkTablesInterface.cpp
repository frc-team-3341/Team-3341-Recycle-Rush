#include "NetworkTablesInterface.h"

bool NetworkTablesInterface::ToteFound()
{
	return NetworkTable::GetTable("cv")->GetBoolean("toteFound", false);
}

double NetworkTablesInterface::GetDistance()
{
	return NetworkTable::GetTable("cv")->GetNumber("distance_m", -1.0);
}

double NetworkTablesInterface::GetAzimuth()
{
	return NetworkTable::GetTable("cv")->GetNumber("azimuth_deg", -1.0);
}
