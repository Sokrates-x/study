#include <iostream>
#include <cassert>

double divide(double a, double b)
{
	assert(b != 0);
	return a/b;
}
int main(int argc, char **argv)
{
	std::cout << divide(3.14, 0) << std::endl;
	return 0;
}
