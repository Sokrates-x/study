#include <string>
#include <iostream>

bool has_upper(const std::string &str)
{
	for (auto m : str)
		if (std::isupper(m))
			return true;
	return false;
}

void to_lower(std::string &str)
{
	for (auto &m : str)
		m = tolower(m);
	return;
}

int main(int argc, char **argv)
{
	std::string str{ "C++ Primer" };
	if (has_upper(str))
		to_lower(str);
	std::cout << str << std::endl;
	return 0;
}
