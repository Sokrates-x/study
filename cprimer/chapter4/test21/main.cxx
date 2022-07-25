#include <iterator>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

int main(int argc, char **argv)
{
	std::vector<int> ivec (10, std::stoi(std::string(*++argv)));
	std::transform(ivec.cbegin(), ivec.cend(), std::ostream_iterator<int>  	
		(std::cout, " "), [] (int i) { return i % 2 ? i * 2 : i; });
	std::cout << std::endl;
	return 0;
}
