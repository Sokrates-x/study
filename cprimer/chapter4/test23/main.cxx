#include <iostream>

int main(int argc, char **argv)
{
	std::cout << std::string(*++argv) << ' ' << std::string(*++argv) <<
		(std::stoi(std::string(*--argv)) > 1 ? "s" : "") << std::endl;
	return 0;
}
