#include <compare>
#include <iostream>
#include <string> 

int main()
{
	std::string s1;
	std::string s2;
	if (s1 <=> s2 == 0)
		std::cout << "s1 = s2" << std::endl;
	if (std::partial_ordering::less < 0)
		std::cout << "less" << std::endl;
	
	return 0;
}
