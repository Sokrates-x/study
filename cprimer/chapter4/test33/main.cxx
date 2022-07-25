#include <iostream>

int main(int argc, char **argv)
{
	argc - 1 ? std::cout << "more" , std::cout << std::endl : std::cout << "single" , std::cout << std::endl;
	return 0;
}
