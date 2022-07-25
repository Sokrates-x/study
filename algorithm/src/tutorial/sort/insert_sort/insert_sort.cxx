#include <iostream>
#include <vector>
#include <iterator>
#include <functional>

#include "sort.h"

int main(int argc, char **argv)
{
	std::vector<int> ivec{ 3, 5, 1, 7, 9 };		
	insert_sort(ivec.begin(), ivec.end());
	std::copy(ivec.cbegin(), ivec.cend(), std::ostream_iterator<int>(std::cout, " "));

	return 0;
}
