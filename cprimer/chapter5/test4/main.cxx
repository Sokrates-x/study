#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	std::vector<int> ivec(10, 1);	
	auto iter = ivec.cbegin();
	while (iter != ivec.cend())
		std::cout << *iter++ << ' ';
	std::cout << std::endl;
	int a;
	/*
	if (a++, int b)
		std::cout << "hello, world." << std::endl;
	*/
	return 0;
}
