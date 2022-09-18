#include <iostream>
#include <unistd.h>

int main(int, char **)
{
	std::cout << getpid() << std::endl;
	std::cout << "hello" << std::endl;
	std::string str;
	std::cin >> str;
	std::cout << str << std::endl;
	return 0;
}
