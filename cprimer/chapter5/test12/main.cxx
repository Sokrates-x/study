#include <iostream>
#include <functional>
#include <iterator>

void fmatch(const std::string &str, int *p)
{
	bool flag = false;	
	for (auto m : str)
	{
		switch (m)
		{
		case 'f':
			if (flag)
				++*p;
			flag = true;	
			break;
		case 'i':
			if (flag)
				++*(p + 1);
			flag = false;
			break;
		case 'l':
			if (flag)
				++*(p + 2);
			flag = false;
			break;
		default:
			flag = false;
		}
	}
	return;
}

void fsmatch(const std::string &str, int *p)
{
	bool flag = false;	
	for (auto m : str)
	{
		switch (m)
		{
		case 'f':
			if (flag)
				++*p, flag = false;
			else
				flag = true;	
			break;
		case 'i':
			if (flag)
				++*(p + 1);
			flag = false;
			break;
		case 'l':
			if (flag)
				++*(p + 2);
			flag = false;
			break;
		default:
			flag = false;
		}
	}
	return;
}

int main(int argc, char **argv)
{
	// ff fi fl
	int p[3], p1[3];
	std::string str("xxxffiffffliffifflflfiiffxx");

	fmatch(str, p);
	fsmatch(str, p1);

	std::copy(std::cbegin(p), std::cend(p), 
		std::ostream_iterator<int>(std::cout, " ")); 
	std::copy(std::cbegin(p1), std::cend(p1), 
		std::ostream_iterator<int>(std::cout, " ")); 
	return 0;	
}
