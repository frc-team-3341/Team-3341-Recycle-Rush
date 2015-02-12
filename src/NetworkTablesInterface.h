#ifndef NETWORK_TABLES_INTERFACE_H
#define NETWORK_TABLES_INTERFACE_H

#include "NetworkTables/NetworkTable.h"
#include <map>

class NetworkTablesInterface{
public:
	static NetworkTablesInterface* GetInstance();
	~NetworkTablesInterface();
	void Update();
	bool ToteFound();
	double GetDistance();
	double GetAzimuth();
private:
	static bool exists;
	static NetworkTablesInterface* nti;
	NetworkTablesInterface();
	bool toteFound_bool;
	double distance_m;
	NetworkTable* table;
	double azimuth_deg;
};

#endif
