#include <iostream>

int main(int argc, char *argv[])
{
	int beg = 50;
	int sum = 0;
	while(beg <= 100)
		sum += beg++;
	std::cout << "50 + 51 + ... + 100 = " << sum << std::endl;
	return 0;
}
