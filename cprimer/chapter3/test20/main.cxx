#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
	std::vector<int> ivec { 2, 3, 4, 5 };
	auto a = ivec.cbegin();
	for (auto b = ivec.crbegin(); a - ivec.cbegin() < (ivec.size() + 1)/2;)
		std::cout << *a++ + *b++ << std::endl;

	return 0;
}
