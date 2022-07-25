#include <vector>
#include <iostream>
#include <functional>
#include <iterator>

int main(int argc, char **argv)
{
	std::vector<int> vec(10, 42);	
	std::ostream_iterator<int> out_iter(std::cout, " ");	
	std::transform(vec.begin(), vec.end(), out_iter, [](int i) { return i*2; });
	std::cout << std::endl;		
	return 0;
}
