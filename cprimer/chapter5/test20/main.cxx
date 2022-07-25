#include <iostream>

int main(int argc, char **argv)
{
	int a;
	if (std::cin >> a)
	{
	}
	std::string str;
	std::cout << std::endl;
	std::cin.clear();	
	std::cin.ignore();
	std::cin.clear();
	//std::cin.sync();
	std::cout << std::endl;
	if (std::cin >> str)
	{
		std::cout << "stream aviliable" << std::endl;
	}
	return 0;
}
