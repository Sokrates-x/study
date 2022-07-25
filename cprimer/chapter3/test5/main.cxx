#include <iostream>

bool sameStr(std::string &&l, std::string &&r)
{
	return l == r;
}

bool sameLength(const std::string &l, const std::string &r)
{
	return l.size() == r.size();
}

int main(int argc, char *argv[])
{
	std::cout << sameStr("1", "1") << std::endl;	
	std::cout << sameLength("1", "1") << std::endl;	
	std::string str, ostr, bstr;
	while ( std::cin >> str)
	{
		ostr += str;
		bstr += str + " ";
	}
	std::cout << ostr << std::endl;
	std::cout << bstr << std::endl;

	std::cout << sameLength(ostr, bstr) << std::endl;
	std::cout << sameLength(std::move(ostr), std::move(bstr)) << std::endl;
	std::cout << ostr << std::endl;
	return 0;
}
