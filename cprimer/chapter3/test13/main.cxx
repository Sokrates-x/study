#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<std::string> svec{ 10 };
	std::vector<int> ivec{ 10 };
	std::cout << svec.size() << ' ' << ivec.size() << std::endl;

	return 0;
}
