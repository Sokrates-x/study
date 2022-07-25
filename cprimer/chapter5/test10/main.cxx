#include <iostream>
#include <functional>
#include <iterator>
#include <numeric>

int main(int argc, char **argv)
{
	int p[5];
	std::string str(*argv);
	for (auto m : str)
	{
		switch (m)
		{
		case 'a': case 'A':
			++p[0]; break;
		case 'e': case 'E':
			++p[1]; break;
		case 'i': case 'I':
			++p[2]; break;
		case 'o': case 'O':
			++p[3]; break;
		case 'u': case 'U':
			++p[4]; break;
		default:;
		}
	}
	std::copy(std::cbegin(p), std::cend(p), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::cout << std::accumulate(std::cbegin(p), std::cend(p), 0) << std::endl;

	return 0;
}
