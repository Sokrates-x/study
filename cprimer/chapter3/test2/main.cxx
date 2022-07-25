#include <iostream>
#include <sstream>

int main(int argc, char *argv[])
{
	std::cout << "Enter Your Sentence:";
	std::string s;
	std::getline(std::cin, s);
	std::cout << "Your Santence: " << s << std::endl;

	std::istringstream is(s);
	while (is >> s)
		std::cout << "Your Words: " << s << '\n';
	std::cout << std::endl;

	std::cout << "Enter Your Sentence:";
	while (std::cin >> s)
		std::cout << "Your Words: " << s << '\n';
	std::cout << std::endl;
	return 0;
}
