#include <iostream>

template<typename T, typename T2>
T abs(T t, T2 Pos = [](T t){ return t > 0; })
{
	return Pos(t) ? t : -t;
}

int main(int argc, char **argv)
{
	std::cout << abs(5, [](int a) { return a > 0; }) << " " << abs(-4) << std::endl;
	return 0;
}
