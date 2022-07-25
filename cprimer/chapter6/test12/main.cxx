#include <iostream>
#include <functional>

void swap(int &l, int &r)
{
	std::swap(l, r);
}

int main(int argc, char **argv)
{
	int a = 1, b = 2;
	swap(a, b);
	std::cout << a << b << std::endl;
	return 0;
}
