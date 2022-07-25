#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << typeid(10.).name() << std::endl;
	std::cout << typeid(L'a').name() << std::endl;
	std::cout << typeid(L"a").name() << std::endl;
	return 0;
}
