#include <iostream>
#include <sys/resource.h>

int main(int, char **)
{
	rusage u;	
	getrusage(RUSAGE_SELF, &u);
	std::cout << u.ru_ixrss << std::endl;
	return 0;
}
