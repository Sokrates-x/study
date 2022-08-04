#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main(int, char **)
{
	int pid;
	pid = fork();	
	switch (pid) {
	case -1:
		std::cerr << "Fork Failed." << std::endl;
		break;
	case 0:
		std::cout << "Child." << std::endl;
		std::cout << "GID: " << getgid() << std::endl;
		std::cout << "UID: " << getuid() << std::endl;
		setgid(1000);
		setuid(1000);
		seteuid(0);
		setegid(0);
		execl("./a","", '\0');	
		break;
	default:
		wait(nullptr);
		std::cout << "Parent." << std::endl;
		std::cout << "GID: " << getgid() << std::endl;
		std::cout << "UID: " << getuid() << std::endl;
		execl("./a","", '\0');	
	}

	return 0;
}
