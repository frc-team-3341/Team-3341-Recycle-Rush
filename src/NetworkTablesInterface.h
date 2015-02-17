#ifndef NETWORK_TABLES_INTERFACE_H
#define NETWORK_TABLES_INTERFACE_H

#include "NetworkTables/NetworkTable.h"

class NetworkTablesInterface{
public:
	static bool ToteFound();
	static double GetDistance();
	static double GetAzimuth();
};

#endif
