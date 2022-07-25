#include <iostream>
#include <iterator>
#include <functional>
#include <vector>
#include <iomanip>
#include "flist.h"

int main(int, char **)
{
	Slist<int> s;
	s.insert(1);
	std::vector<int> v{ 1, 3, 5, 7, 9 };
	_node<std::vector<int>> nv(v.begin(), v.end());
	_node<std::vector<int>> nv2;
	std::copy(nv.val.begin(), nv.val.end(), std::ostream_iterator<int>(
		std::cout, " "));
	std::cout << std::boolalpha << nv2.val.empty() << std::endl;
	return 0;
}
