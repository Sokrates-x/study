#include <unistd.h>
#include <iostream>

int main(int, char **)
{
	
	int pid;
	pid = fork();
	switch (pid) {
	case -1:
		std::cout << "Fork Failed" << std::endl;
		break;
	case 0:
		std::cout << "I'm Child" << std::endl;
		break;
	default:
		std::cout << "I'm Parent" << std::endl;
	}

	return 0;
}
