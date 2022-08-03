#include <iostream>
#include <unistd.h>
#include <iterator>
#include <functional>
#include <cstring>

int main(int, char **)
{
	extern char **environ;
	//while (*environ)
	//	std::cout << *environ++ << std::endl;

	std::cout << getenv("PATH") << std::endl;	
	putenv(const_cast<char *>("myname=xie"));
	setenv("myname", "xiedong", 1);
	std::cout << getenv("myname") << std::endl;
	return 0;
}
