#include <iostream>

int main(int argc, char **argv)
{
	std::stoi(std::string(*++argv)) < 60 ? std::cout << "No Pass" :
		std::stoi(std::string(*argv)) < 75 ? std::cout << "Low Pass" :
		std::cout << "Pass", std::cout << std::endl; 
	std::cout << (std::stoi(std::string(*argv)) < 60 ? "No Pass" :
		std::stoi(std::string(*argv)) < 75 ? "Low Pass" : "Pass" )
		<< std::endl;
	return 0;
}
