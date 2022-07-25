#include <iostream>

int main(int argc, char *argv[])
{
	int i = 0;
	const int ci = i;
	// auto = int
	auto a = i;
	auto b = ci;
	// auto = int &
	auto &c = i;
	// auto = const it &
	auto &d = ci;
	// auto = int *
	auto *e = &i;
	// auto = const int *
	auto *f = &ci;
	return 0;
}
