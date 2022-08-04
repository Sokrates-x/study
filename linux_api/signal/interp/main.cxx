#include <iostream>
#include <sys/wait.h>
#include <signal.h>

int main(int, char **)
{
	auto old_sig = signal(SIGINT, [](int) {
		std::cout << "Interped" << std::endl;
	});

	int pid = fork();

	switch (pid) {
	case -1:
		std::cerr << "Fork Failed." << std::endl;
		break;
	case 0:
		std::cout << "Child" << std::endl;
		sleep(10);	
		std::cout << errno << " " << EINTR << std::endl;
		break;
	default:
		wait(nullptr);
		sleep(10);
		std::cout << "Parent" << std::endl;
		std::cout << errno << " " << EINTR << std::endl;
	}

	signal(SIGINT, old_sig);
	return 0;
}
