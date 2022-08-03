#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main(int, char **)
{
	int pid;
	int ppid;
	pid = fork();

	switch (pid) {
	case -1:
		std::cout << "Fork Faild" << std::endl;
		break;
	case 0:
		std::cout << "Parent Pid: " << getppid() << std::endl;
		std::cout << "Child  Pid: " << getpid() << std::endl;
		break;
	default:
		wait(nullptr);
		std::cout << "Parent Pid: " << getpid() << std::endl;
		std::cout << "Child  Pid: " << pid << std::endl;
	}
	return 0;
}
