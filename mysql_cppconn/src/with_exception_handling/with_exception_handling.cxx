#include <jdbc.h>
#include <iostream>
#include <memory>

int main(int, char **)
{
	sql::ConnectOptionsMap connection_properties;	
	connection_properties["hostName"] = "localhost";
	connection_properties["userName"] = "root";
	connection_properties["password"] = "";
	connection_properties["OPT_LOCAL_INFILE"] = 1;
	connection_properties["schema"] = "test";
	connection_properties["OPT_RECONNECT"] = true;

	sql::mysql::MySQL_Driver *driver = 
		sql::mysql::get_mysql_driver_instance();
	std::shared_ptr<sql::Connection> conn(
		driver->connect(connection_properties));

	std::shared_ptr<sql::Statement> stmt(conn->createStatement());	
	stmt->execute("USE test");
	stmt->execute("DROP TABLE IF EXISTS linux_counts");
	stmt->execute("CREATE TABLE linux_counts (name VARCHAR(20), \
		usage_amount INT)");
	stmt->execute("INSERT INTO linux_counts VALUES ('RedHat', '5324154')");
	stmt->execute("INSERT INTO linux_counts VALUES ('CentOS', '7422335')");
	stmt->execute("INSERT INTO linux_counts VALUES ('Ubuntu', '5542451')");
	stmt->execute("INSERT INTO linux_counts VALUES ('Fedora', '3095834')");
	stmt->execute("INSERT INTO linux_counts VALUES ('Debian', '4342411')");

	return 0;
}
