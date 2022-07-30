#include <iostream>
#include <jdbc.h>
#include <memory>

int main(int, char **)
{
	// A SIMPLE WAY TO CONNECT
	/*
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *conn;
	driver = sql::mysql::get_mysql_driver_instance();
	conn = driver->connect("localhost", "root", "");
	
	while (!conn->isValid()) {
		std::cout << "Connecting..." << std::endl;
		conn->reconnect();
	}
	
	std::cout << "Connected!" << std::endl;
	
	delete conn;
	*/

	// CONNECT IN ANOTHER WAY 
	sql::ConnectOptionsMap connection_properties;
	
	connection_properties["hostName"] = "localhost";
	connection_properties["userName"] = "root";
	connection_properties["password"] = "";
	connection_properties["schema"] = "test";
	connection_properties["OPT_LOCAL_INFILE"] = 1;
	connection_properties["OPT_RECONNECT"] = true;

	// never delete a driver;
	//driver = sql::mysql::MySQL_Driver::get_mysql_driver_instance();
	sql::mysql::MySQL_Driver *driver = 
				sql::mysql::get_mysql_driver_instance();
	std::shared_ptr<sql::Connection> conn( 
				driver->connect(connection_properties));

	//  SIMPLE STATEMENT
	std::shared_ptr<sql::Statement> stmt(conn->createStatement());
	stmt->execute("DROP TABLE IF EXISTS pet");
	stmt->execute("CREATE TABLE pet (name VARCHAR(20), owner VARCHAR(20),\
		species VARCHAR(20), sex CHAR(1), birth DATE, death DATE)");
	stmt->execute("LOAD DATA LOCAL INFILE '/tmp/pet.txt' INTO TABLE pet");
	stmt->execute("INSERT INTO pet VALUES ('Puffball', 'Diane', 'hamster',\
		'f', '1999-3-30', NULL)");
	stmt->execute("UPDATE pet SET birth='1989-8-31' WHERE name='Bowser'");

	// PREPARED STATEMENT
	std::shared_ptr<sql::PreparedStatement> pstmt(
		conn->prepareStatement("INSERT INTO pet (name, owner, \
		species, sex, birth, death) VALUES (?, ?, ?, ?, ?, ?)"));
	
	pstmt->setString(1, "Simmi");
	pstmt->setString(2, "Bob");
	pstmt->setString(3, "cat");
	pstmt->setString(4, "f");
	pstmt->setString(5, "1994-3-13");
	pstmt->setNull(6, 0);
	
	pstmt->execute();

	// SIMPLE QUERY
	std::shared_ptr<sql::ResultSet> res(
		stmt->executeQuery("SELECT * FROM pet"));
	while (res->next()) {
		std::cout << res->getString(1) << "\t";
		std::cout << res->getString(2) << "\t";
		std::cout << res->getString(3) << "\t";
		std::cout << res->getString(4) << "\t";
		std::cout << res->getString(5) << "\t";
		std::cout << res->getString(6) << "\t";
		std::cout << "\n";
	}

	return 0;
}
