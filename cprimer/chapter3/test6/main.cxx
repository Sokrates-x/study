#include <iostream>

int main(int argc, char *argv[])
{
	std::string str{"abcdef"};
	for (auto &m : str)
		m = 'X';
	for (char &m : str)
		m = 'Y';
	std::cout << str << std::endl;
	return 0;
}
