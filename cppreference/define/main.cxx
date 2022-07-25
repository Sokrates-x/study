#include <iostream>
#include <tuple>

auto t = std::make_tuple(1, 3);

#define df(i)\
	std::cout << std::get<i>(t) << std::endl;

void f(const int i)
{
	std::cout << std::get<1>(t) << std::endl;
}

int main(int, char **)
{
	df(1);
	return 0;
}
