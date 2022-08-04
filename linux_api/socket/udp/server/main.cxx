#include <iostream>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <iterator>
#include <functional>

int main(int , char **)
{
	// creat udp
	int sid = socket(AF_INET, SOCK_DGRAM, 0);
	
	sockaddr_in addr;	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(19953);	
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");	

	bind(sid, reinterpret_cast<sockaddr *>(&addr), sizeof(sockaddr_in));

	sockaddr_in caddr;
	socklen_t len = sizeof(sockaddr_in);

	char buffer[30];
	recvfrom(sid, buffer, 13, 0, 
		reinterpret_cast<sockaddr *>(&caddr), &len);
	
	std::copy(std::begin(buffer), std::end(buffer),
		std::ostream_iterator<char>(std::cout, ""));
	std::cout << std::endl;
	return 0;
}
