#include <iostream>
#include <vector>
#include <iterator>
#include <functional>

#include "sort.h"

int main(int argc, char **argv)
{
	std::vector<int> ivec{ 3, 1, 5, 9, 7 };
	std::cout << "Reverse Pair Counts: " << reverse_pair_count(ivec.begin(),
		ivec.end()) << std::endl;
	
	//merge_sort(ivec.begin(), ivec.end());
	std::copy(ivec.cbegin(), ivec.cend(), std::ostream_iterator<int>(
		std::cout, " "));

	std::cout << std::endl;
	return 0;
}
