#include <iostream>

void x()
{
	int *p;
	int i;
	std::cout << p << std::endl;
	std::cout << i << std::endl;
}

int main(int argc, char *argv[])
{
	int *p;
	int i;
	std::cout << p << std::endl;
	std::cout << i << std::endl;

	x();
	return 0;
}
