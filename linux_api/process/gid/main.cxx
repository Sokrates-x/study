#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

int main(int, char **)
{
	int pid, gid, newgrpid;
	pid = fork();
	switch (pid) {
	case -1:
		std::cout << "Fork Failed" << std::endl;
		break;
	case 0:
		std::cout << "Process Group ID: " << getpgrp() << std::endl;
		break;
	default:
		wait(nullptr);
		std::cout << "Process Group ID: " << getpgrp() << std::endl;
		newgrpid = setpgrp();
	}

	switch (pid) {
	case -1:
		std::cout << "Fork Failed" << std::endl;
		break;
	case 0:
		std::cout << "New Process Group ID: " << getpgrp() << std::endl;
		break;
	default:
		wait(nullptr);
		std::cout << "New Process Group ID: " << getpgrp() << std::endl;
	}

	return 0;
}
