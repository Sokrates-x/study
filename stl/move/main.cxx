#include <iostream>

int main(int, char **)
{
	int a = 0;
	int &&b = std::move(a);
	++b;
	std::cout << a << std::endl;
	return 0;
}
