#include <iostream>
#include <netdb.h>
#include <netinet/in.h>

int main(int, char **)
{
	auto h = gethostbyname("www.baidu.com");		
	std::cout << "HostName:" << h->h_name << std::endl;
	std::cout << "Address:" << *(h->h_addr_list) << std::endl;
	std::cout << "Address:" << *(++h->h_addr_list) << std::endl;
	return 0;
}
