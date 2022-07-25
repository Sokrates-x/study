#include <iostream>
#include <string>
#include <iterator>

int main(int argc, char *argv[])
{
	int a = std::stoi(std::string(*(++argv)));
	a % 2 ? std::cout << "odd" : std::cout << "even",
		std::cout << std::endl;
	return 0;
}
