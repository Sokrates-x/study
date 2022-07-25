#include <iostream>
#include <iterator>
#include <functional>
#include <vector>

#include "sort.h"

int main()
{
	int vec[] = { 31, 15, 59, 97, 73, 31, 13 };
	int vec1[] = { 3, 1, 5, 9, 7 };
	bucket_sort(vec, vec + 7);
	std::copy(std::begin(vec), std::end(vec),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
