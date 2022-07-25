#include <stdexcept>
#include <iostream>

long long fact(int n)
{
	return n <= 1 ? 1 : fact(n - 1)*n;
}

int main(int argc, char **argv)
{
	int a;
	do 
	{
		std::cout << "Enter an Interger: " << std::endl;
		std::cin >> a;
		try 
		{
			if (a < 0)
				throw(std::runtime_error("Invalid Negtive Input"));
			std::cout << "Factorial of " << a << " is " << fact(a) << 
				std::endl;
		}catch(std::runtime_error err)
		{
			std::cout << err.what() << std::endl <<
				" Try Again? (y/n)" << std::endl;
			char c;
			std::cin >> c;
			if (c != 'y')
				break;
		}
	} while(std::cin);

	return 0;
}
