#include <iostream>
#include <vector>

void printv(std::ostream &os, std::vector<int> &vec)
{
	if(vec.empty())
		return;
	std::vector<int> v(++vec.begin(), vec.end());
	os << *vec.begin() << " ";
	printv(os, v);
	return;
}

void printv(std::ostream &os, std::vector<int>::iterator b,
	std::vector<int>::iterator e)
{
	if (e - b <= 1)
	{	
		os << *b << " ";
		return;
	}

	printv(os, b, b + (e - b)/2);
	printv(os, b + (e - b)/2, e);
	return;
}

int main(int argc, char **argv)
{
	std::vector<int> vec{ 1, 3, 5, 7, 9 };
	printv(std::cout, vec);	
	std::cout << std::endl;
	printv(std::cout, vec.begin(), vec.end());
	std::cout << std::endl;
	return 0;
}
