#include <stdlib.h>
#include <unistd.h>
#include <iostream>

int main()
{
	std::cout << getpid() << std::endl;	
	execl("/root/work/hello", "./hello", "", NULL);

	std::cout << getpid() << std::endl;	
}
