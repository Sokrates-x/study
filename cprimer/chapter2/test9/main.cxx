#include <iostream>

int main(int argc, char *argv[])
{
	// Bad test
	//std::cin >> int a;
	// Good  test
	int i = { 1 };
	i = { 2 };
	std::cout << i << std::endl;
	// Bad test
	//double a = b = 3.14;
	// Good test
	double b, a = b = 3.14;
	
	return 0;
}
