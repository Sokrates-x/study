#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/wait.h>

int main(int, char **)
{
	// creat
	int sid = socket(AF_INET, SOCK_STREAM, 0);	

	// addr
	in_addr iad;
	iad.s_addr = inet_addr("127.0.0.1");

	sockaddr_in addr_in;
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons(18834);
	addr_in.sin_addr = iad;

	// bind
	bind(sid, reinterpret_cast<sockaddr *>(&addr_in), sizeof(sockaddr_in));

	// listen	
	listen(sid, 5);

	// serve
	while (true) {
		// accept
		sockaddr_in other_addr_in;	
		socklen_t other_size;
		int new_fd = accept(sid, reinterpret_cast<sockaddr *>(&other_addr_in), 
			&other_size);
		// send
		send(new_fd, "hello, socket", 13, 0);
	}

	return 0;
}
