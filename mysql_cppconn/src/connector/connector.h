#ifndef CONNECTOR_H
#define CONNECTOR_H 1

/**
 * Wrapper class for resource in order to prevent leak of memory
 */

#include <../jdbc/mysql_connector.h>
#include <../jdbc/mysql_driver.h>

class Connector {
public:
	Connector();	
	
private:
	
};

#endif // CONNECTOR_H
