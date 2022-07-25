#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Enter Your Numbers: \n";
	double d, sum = 0;
	while (std::cin >> d)
		sum += d;	
	std::cout << "Sum = " << sum << std::endl;
	return 0;
}	
