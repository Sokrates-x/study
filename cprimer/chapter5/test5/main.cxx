#include <iostream>

int main(int argc, char **argv)
{
	int p = std::stoi(std::string(*++argv));

	if (p >= 100)
		std::cout << "S\n";
	else if (p > 90)
		std::cout << "A\n";
	else if (p > 80)
		std::cout << "B\n";
	else if (p > 70)
		std::cout << "C\n";
	else if (p >= 60)
		std::cout << "D\n";
	else 
		std::cout << "F\n";
	return 0;
}
