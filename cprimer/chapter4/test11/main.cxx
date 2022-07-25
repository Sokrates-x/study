#include <iostream>

int main(int argc, char **argv)
{
	int a, b, c, d;
	if (a >= b && b >= c && c >= d)
		std::cout << "Ordered." << std::endl;

	int i, j, k;
	if (i != j < k)
		std::cout << "i != (j < k)" << std::endl;

	return 0;
}
