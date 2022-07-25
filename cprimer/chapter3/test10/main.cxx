#include <iostream>

int main(int argc, char *argv[])
{
	std::string str{ "ab.cd.ef.g" };
	std::cout << str.size() << std::endl;
	std::cout << sizeof(str) << std::endl;
	std::cout << std::size(str) << std::endl;

	int i;	
	for (auto m : str)
	{
		if (!ispunct(m)) 
			str[i++] = m;
	}
	str.erase(str.begin() + i, str.end());

	std::cout << str << std::endl;
	std::cout << str.size() << std::endl;
	return 0;
}
