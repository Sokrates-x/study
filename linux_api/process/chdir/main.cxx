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
		chdir("test");
		execl("/bin/ls", ".", '\0');
		break;
	default:
		std::cout << "Parent." << std::endl;
		execl("/bin/ls", ".", '\0');
	}
	return 0;
}
