#include <iostream>

int main(int argc, char *argv[])
{
	int i;
	const auto a = i;
	const auto &b = i;
	const auto *c = &i;
	i = 3;
	const int &j = 1;
	int &k = i;
	std::cout << b << std::endl;
	std::cout << (typeid(b) == typeid(j)) << std::endl;
	std::cout << (typeid(i) == typeid(k)) << std::endl;
	return 0;
}
