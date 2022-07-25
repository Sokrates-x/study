#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
	std::vector<int> ivec;
	int i;
	while (std::cin >> i)
		ivec.push_back(i);

	std::string str;
	std::vector<std::string> svec;
	std::cin.clear();
	while (std::cin >> str)
		svec.push_back(str);

	for (auto m : ivec)
		std::cout << m << ' ';
	std::cout << std::endl;
	for (auto m : svec)
		std::cout << m << ' ';
	std::cout << std::endl;
	return 0;
}
