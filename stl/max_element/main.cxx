#include <iostream>

struct Max{};

template <typename T>
bool operator<(T t, Max m)
{
	return true;
}

bool operator<(Max t, Max m)
{
	return false;
}

int main(int argc, char **argv)
{
	Max m;
	int a;
	if (a < m)
		std::cout << "a < m" << std::endl;
	if (m < m)
		std::cout << "m < m" << std::endl;

	return 0;
}
