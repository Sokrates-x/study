#include <memory_resource>
#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
	std::pmr::vector<int> a(1);	
	std::pmr::vector<int> b(1);	
	std::vector<int> c(1);
	std::swap(a, b);
	std::swap(a, c);
	return 0;
}
