#include <iostream>

int main(int argc, char *argv[])
{
	int i = 1;
	void *p = &i;
	std::cout << *((int*)p) << std::endl;
	return 0;
}
