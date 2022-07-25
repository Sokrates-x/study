#include <iostream>

int main(int argc, char *argv[])
{
	int i = 4;
	int j = 5;
	int *p = &i;
	int *q = &j;
	std::cout << p << ' ' <<  *p << std::endl;
	std::cout << q << ' ' <<  *q << std::endl;
	std::cout << (p < q) << std::endl;
	std::cout << (p > q) << std::endl;
	return 0;
}
