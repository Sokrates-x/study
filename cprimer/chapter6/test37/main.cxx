#include <iostream>
#include <iterator>
#include <functional>

std::string p[10] = { "hi" };

std::string (&f())[10]
{
	return p;	
}

auto g() -> std::string (&)[10]
{
	return p;	
}

//typedef std::string Sarray[10];
using Sarray = std::string[10];
Sarray &h()
{
	return p;	
}

std::string a[10];
decltype(a) &i()
{
	return p;	
}

int main()
{
	f()[0] = "f";
	g()[1] = "g";
	h()[2] = "h";
	i()[3] = "i";
	std::copy(std::cbegin(p), std::cend(p), 
		std::ostream_iterator<std::string>(std::cout , " "));
	std::cout << std::endl;
	return 0;
}
