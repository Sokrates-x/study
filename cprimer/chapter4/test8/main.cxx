#include <iostream>

static int a = 1;

int f()
{
	return ++a;
}

int main(int argc, char **argv)
{
	for (int a = 0; a < 10; ++a)
		std::cout << f() << ' ' <<  (f() < f())<< std::endl;	
	return 0;
}
