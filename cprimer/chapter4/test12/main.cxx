#include <iostream>

int main(int argc, char **argv)
{
	int i;
	double d;
	i = d = 3.14;
	std::cout << i << ' ' << d << std::endl;
	d = i = 3.14;
	std::cout << i << ' ' << d << std::endl;

	int *p = nullptr;
	int ii = static_cast<int>(p);

	return 0;
}
