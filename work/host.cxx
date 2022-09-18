#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <exception>
#include <functional>
#include <iterator>

int main(int, char **)
{
	// creat
	int sid = socket(AF_INET, SOCK_STREAM, 0);	
	if (sid < 0)
	{
		throw std::runtime_error("Creat Socket Failed.");
	}

	// addr
	in_addr iad;
	iad.s_addr = inet_addr("127.0.0.1");

	sockaddr_in addr_in;
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons(19931);
	addr_in.sin_addr = iad;

	// bind
	if (bind(sid, reinterpret_cast<sockaddr *>(&addr_in), sizeof(sockaddr_in)) == -1)
	{
		throw std::runtime_error("Bind Failed");
	}

	// listen	
	if (listen(sid, 1) == -1)
	{
		throw std::runtime_error("Listen Failed.");
	}

	// accept
	sockaddr_in other_addr_in;	
	socklen_t other_size;
	int new_fd = accept(sid, reinterpret_cast<sockaddr *>(&other_addr_in), 
		&other_size);
	// recv 
	char buffer[1];
	//while(recv(new_fd, buffer, 1, 0))
	{
	for (int i = 0; i < 20; ++i)
	{	
		if (recv(new_fd, buffer, 1, 0) == -1)
		{
			throw std::runtime_error("Connect Failed.");
		}
	
		std::copy(std::begin(buffer), std::end(buffer), 
			std::ostream_iterator<char>(std::cout, ""));
	}
	}

	send(new_fd, "q", 1, MSG_DONTWAIT);

	std::cout << std::endl;
	return 0;
}
