#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
	std::vector<int> v1(10, 42);	
	std::vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
	std::vector<int> v3(v1);
	std::cout << (v1 == v2 && v2 == v3) << std::endl;
	return 0;
}
