#include <iostream>
#include <signal.h>

int main(int, char **)
{
	void (*sig)(int) = signal(SIGINT, [] (int) { 
		std::cout << "\nInterp" << std::endl; });
	signal(SIGINT, sig);
	std::cout << "start." << std::endl;
	sleep(11);
	std::cout << "end." << std::endl;
	return 0;
}
