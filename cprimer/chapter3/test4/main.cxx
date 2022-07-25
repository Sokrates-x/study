#include <iostream>
#include <iterator>

int main(int argc, char *argv[])
{
	char str[] = "hello";
	const char *s = std::begin(str);	
	const char *se = std::end(str);
	std::cout << se - s << std::endl;
	std::cout << sizeof(str) << std::endl;
	return 0;
}
