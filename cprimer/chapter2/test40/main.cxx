#include <fstream>
#include <iostream>

#include "sales_data.h"

int main(int argc, char*argv[])
{

	std::ifstream is;
	is.open("data");
	Sales_data s1(is);
	Sales_data s2(is);
	std::cout << s1 + s2 << std::endl;
	s1 += s2;
	std::cout << s1 << std::endl;

	return 0;
}
