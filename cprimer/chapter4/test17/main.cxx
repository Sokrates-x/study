#include <iostream>

void f(int &&i)
{
	std::cout << i << std::endl;
}

int main(int argc, char **argv)
{
	int i;
	f(i++);
	return 0;
}
