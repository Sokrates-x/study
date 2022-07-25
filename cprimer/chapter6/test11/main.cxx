#include <iostream>

void reset(int & i)
{
	i = 0;
	return;
}

int main(int argc, char ** argv)
{
	int i = 1;
	reset(i);
	std::cout << i << std::endl;
	return 0;
}
