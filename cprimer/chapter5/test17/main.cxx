#include <iostream>
#include <vector>
#include <functional>

int main(int argc, char **argv)
{
	std::vector<int> v1 { 1, 3, 5, 7, 9 };
	std::vector<int> v2 { 1, 2, 5, 7 };
	
	v1.size() < v2.size() ? v2 = std::vector<int>(v2.begin(), v2.begin() + 
		v1.size()) : v1 = std::vector<int>(v1.begin(), v1.begin() +
		v2.size());
	/*
	v2 = std::vector<int>(v2.begin(), v2.begin() + std::min(v1.size(), v2.size()));
	v1 = std::vector<int>(v1.begin(), v1.begin() + std::min(v1.size(), v2.size())); 
	*/
	std::cout << (v1 == v2) << std::endl;
	return 0;
}
