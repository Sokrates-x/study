#include <iostream>
#include <signal.h>
#include <functional>

int work_time = 20;

void fa(int) {
	std::cout << "Take a break." << std::endl;
	sleep(1);
}

int main(int, char **)
{
	signal(SIGALRM, fa);

	while (work_time > 0) {
		alarm(5);
		std::cout << "Working..." << std::endl;
		sleep(work_time);
		work_time -= 6;
	}
	std::cout << "Work Done." << std::endl;
	return 0;
}
