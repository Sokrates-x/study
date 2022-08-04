#include <sys/resource.h>
#include <iostream>

int main(int, char **)
{
	rlimit a;
	getrlimit(RLIMIT_NPROC, &a);
	std::cout << a.rlim_cur << " " << a.rlim_max << std::endl;
	getrlimit(RLIMIT_STACK, &a);
	std::cout << a.rlim_cur << " " << a.rlim_max << std::endl;

	return 0;
}
