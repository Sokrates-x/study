#include <iostream>
#include <signal.h>
#include <sys/wait.h>

int main(int, char **)
{

	signal(SIGALRM, [] (int) {
		std::cout << "my pid is: " << getpid() << std::endl;
	});

	int pid = fork();		
	switch (pid) {
	case -1:
		std::cerr << "Fork Failed.\n";
		break;
	case 0:
		std::cout << "Child" << std::endl;
		sleep(10);
		break;
	default:
		sleep(2);
		std::cout << "Parent ask for child's uid. " << pid << 
			" ?" << std::endl;
		kill(pid, SIGALRM);
		wait(nullptr);
	}
	return 0;
}
