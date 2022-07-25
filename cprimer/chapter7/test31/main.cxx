#include <iostream>

class Y;

class X {
	Y *py_;
};

class Y {
	X x;	
};

int main(int, char **)
{
	return 0;
}
