#include <iostream>

int main(int argc, char *argv[])
{
	int sum = 0;
	for (int b = 50; b <= 100; ++b)
		sum += b;
	std::cout << "50 + 51 + ... + 100 = " << sum << std::endl;

	for (int b = 10; b >= 0; --b)
		std::cout << b << ' ';
	std::cout << std::endl;

	std::cout << "Enter Two Numbers: \n";
	int b, e;
	std::cin >> b >> e;
	for (;b!=e;)
		b < e ? std::cout << b++ << ' ' : std::cout << b-- <<  ' ';	
	std::cout << e << std::endl;
		
	return 0;
}
