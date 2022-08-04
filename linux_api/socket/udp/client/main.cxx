#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main(int, char **)
{
	int sid = socket(AF_INET, SOCK_DGRAM, 0);
	
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(19953); 
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	sendto(sid, "hello, socket", 13, 0, 
		reinterpret_cast<sockaddr *>(&addr), sizeof(sockaddr_in));

	return 0;
}
