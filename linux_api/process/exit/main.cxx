#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main(int, char **)
{
	int pid;
	int status;

	pid = fork();
	switch (pid) {
	case -1:
		std::cout << "Fork Failed" << std::endl;
		break;
	case 0:
		std::cout << "Child ";
		exit(21);
		break;
	default:
		std::cout << "Child's Pid is " << pid << std::endl;
		std::cout << wait(&status) << " Exit Status: " << (status>>8) << 
			std::endl;
	}
	
	return 0;
}
