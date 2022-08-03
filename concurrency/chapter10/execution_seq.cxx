#include <iostream>
#include <iterator>
#include <execution>
#include <vector>
#include <functional>

int main(int, char **)
{
	std::vector<int> vec(1000);	
	int count = 0;
	std::for_each(std::execution::par_unseq, vec.begin(), vec.end(), [&count] 
		(int &i) { i = ++count; });

	std::copy(std::execution::par, vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout,
		" "));
	std::cout << std::endl;
	return 0;
}
