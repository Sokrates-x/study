#include<vector>
#include <iostream>

#include "has_two_added.h"

int main(int argc, char **argv)
{
	std::vector<int> vec{ 3, 1, 5, 9, 7 };

	std::cout << has_two_added(vec.begin(), vec.end(), 8) << std::endl;	
	return 0;
}
