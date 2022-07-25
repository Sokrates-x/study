#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Enter Two Numbers: \n";
	double a, b;
	std::cin >> a;
	std::cin >> b;
	std::cout << a;
	std::cout << " x ";
	std::cout << b;
	std::cout << " = ";
	std::cout <<  a*b;
	std::cout <<  std::endl;
	return 0;
}
