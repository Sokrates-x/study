#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>

int main(int argc, char *argv[])
{
	std::string sstr{ "where there's a will, there's a way. once upon a time, there's a old man named Bob. he's so old that can't eat anything." };
	std::istringstream is(sstr);

	std::string str;
	std::vector<std::string> svec;
	bool flag = true;
	while (is >> str) 
	{
		if (flag)
			*str.begin() = toupper(*str.begin()), flag = false, str = "\b" + str;
		if (*str.crbegin() == '.')
			flag = true, str += "\n";
		svec.push_back(str);
	}
	std::cout << ' ';
	for (const auto m : svec)
		std::cout << m << " ";
	std::cout << '\b';
	return 0;
}
