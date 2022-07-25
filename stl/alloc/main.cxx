#include <iostream>

int main(int argc, char **argv)
{
	int *p = (int *)(operator new(sizeof(int)*5));

	return 0;
}
