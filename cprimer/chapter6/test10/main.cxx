#include <iostream>
#include <functional>

void swap(int *a, int *b)
{
	std::swap(*a, *b);
}

int main(int argc, char **argv)
{
	int a = 1, b = 2, *pa = &a, *pb = &b;
	swap(pa, pb);
	std::cout << a << b << std::endl;
	return 0;
}
