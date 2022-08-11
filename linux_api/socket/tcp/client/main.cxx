#include <iostream>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iterator>
#include <functional>

int main(int, char **)
{
	// creat 
	int sid = socket(AF_INET, SOCK_STREAM, 0);

	// addr
	in_addr adi;
	adi.s_addr = inet_addr("127.0.0.1");

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(19931);
	addr.sin_addr = adi;

	// connect
	connect(sid, reinterpret_cast<sockaddr *>(&addr), sizeof(addr));


	// recv
	char buffer[100];
	recv(sid, buffer, 13, 0);

	// print
	std::copy(std::begin(buffer), std::end(buffer), 
		std::ostream_iterator<char>(std::cout, ""));
	std::cout << std::endl;

	return 0;
}
