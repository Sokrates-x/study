#include <iostream>

int main(int argc, char *argv[])
{
	// Bad test oct
//	int i = 08;
//	int j = A;
//
	int i = 07;
	int j = 9;
	// Hex
	int k = 0xA;
	std::cout << std::showbase;
	std::cout << std::hex << i << ' ' << std::oct << j << ' ' << std::dec << k << std::endl;
	std::cout << std::noshowbase;
	return 0;
}
