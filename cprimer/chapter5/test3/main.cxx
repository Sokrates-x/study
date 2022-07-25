#include <iostream>

int main(int argc, char **argv)
{
	int max = 10, sum, i;
	while (i <= 10)
		sum += i++;
	std::cout << sum << std::endl;
	return 0;
}
