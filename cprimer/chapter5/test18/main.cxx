#include <stdexcept>
#include <iostream>

int main(int argc, char **argv)
{
/*
	int a;
	do 
	{
		std::cin >> a;
	} while (std::cin);

	std::cout << "Enter Your Numbers: " << std::endl;
*/

	int a;
	std::cin.clear();

	while (std::cin >> a)
	{
		try
		{
			if (a == 0)
				throw std::runtime_error("Divided by zero");
		
			std::cout << "Inverse is: " << 1.0/a << std::endl;
		} catch(std::runtime_error err)
		{
			std::cout << err.what() << std::endl;
			std::cout << "Retry ?";
			char c;
			std::cin >> c;
			if (c != 'y')
				break;
		}
	}
	return 0;
}
