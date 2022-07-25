#include <iostream>

int sum(std::initializer_list<int> a)
{
	int sum = 0;
	for (auto m : a)
		sum += m;
	return sum;
}

template <typename T>
auto sum(T t)
{
	return t;
}

template <typename T, typename... Args>
auto sum(T t, Args... rest)
{
	return t + sum(rest...);
}

int main(int argc, char **argv)
{
	std::cout << sum( { 1, 2, 3, 4 } ) << std::endl;
	std::cout << sum(1, 'c', 'd', 3.15) << std::endl;
	return 0;
}
