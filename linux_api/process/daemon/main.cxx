#include <iostream>
#include <unistd.h>
#include <signal.h>

int main(int, char **)
{
	int pid, dpid;
	pid = fork();
	switch (pid) {
	case -1:
		std::cerr << "Fork Failed" << std::endl;
		break;
	case 0:
		setsid();
		signal(SIGHUP, SIG_IGN);
		dpid = fork();
		if (dpid != 0) {
			std::cout << dpid << std::endl;
			exit(0);
		} else {
			while (true) {
				sleep(100);
			}
		}
	default:;
	}
	return 0;
}
