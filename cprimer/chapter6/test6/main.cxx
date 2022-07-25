#include <iostream>

int f()
{
	static int i = 0;
	return i++;
}

int main(int argc, char **argv)
{
	f();
	std::cout << f() << std::endl;
	return 0;
}
