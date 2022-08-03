#include <iostream>

int main(int, char **)
{
	auto f = [] (auto i) {
		std::cout << i << ", c++ 17" << std::endl;
	};
	f("hello");
	return 0;
}
