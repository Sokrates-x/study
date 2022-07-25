#include <iostream>

int main(int argc, char *argv[])
{
	// real short solution
	std::cout << "Enter Two Numbers: \n";
	int b, e;
	std:: cin >> b >> e;
	while (b != e)
		b < e ? std::cout << b++ << ' ' : std::cout << b-- << ' ';
	std::cout << e << std::endl;
	return 0;
}
