#include <iostream>

struct A
{
	int operator[](int i, int j)
	{	
		return 11;
	}	
};

int main(int, char **)
{
	return 0;
}
