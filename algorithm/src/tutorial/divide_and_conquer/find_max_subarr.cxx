#include <vector>
#include <tuple>
#include <iostream>
#include <functional>
#include <iterator>

#include "divide.h"

int main(int argc, char **argv)
{
	std::vector<int> vec{ 1, -2, 3, -4, 3, 2, -1, 4, 7, -4, -3, 9, -2, 1 };
	auto res = find_max_subarr(vec.begin(), vec.end());
	std::cout << "Max Subarray Sum: " << std::get<2>(res) << std::endl;
	std::cout << "Max Subarray: " << std::endl;
	std::copy(std::get<0>(res), std::get<1>(res), 
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
