/**
 * Postpone the var define as possible
 */

#include <iostream>

class C {};

int main(int, char **)
{
	C c, d;
	// case 1
	for (int i = 0; i != 100; ++i) {
		c = d; 
	}
	// case 2
	for (int i = 0; i != 100; ++i) {
		C c(d); 
	}

	// generally, case 2 works better
	return 0;
}
