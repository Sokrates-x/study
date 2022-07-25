#include <iostream>
#include <string>

int main(int argc, char*argv[])
{
	std::string s1 = "hello";
	std::string s2 = "world";
	decltype(s1 += s2) s = s1;
	std::cout << s << std::endl;

	int i = 1;
	const int j = i;
	decltype((j)) k = i;
	decltype(j) l = i;
	i = 32;
	std::cout << k << std::endl;
	std::cout << l << std::endl;

	return 0;

}	
