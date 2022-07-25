#include <iostream>
#include <iterator>
#include <functional>

int main(int argc, char ** argv)
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::vector<int> vec;
	std::copy(std::cbegin(a), std::cend(a), std::back_inserter(vec));
	std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	int b[10];
	std::copy(vec.cbegin(), vec.cend(), b);
	std::copy(std::cbegin(b), std::cend(b), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
