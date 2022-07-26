/**
 * Multi-Inheritance 
 */
#include <iostream>
#include "example_mi.h"

int main(int, char **) {
	Example_mi mi;
	mi.print(std::cout);
	Example_mi_base1 *p = new Example_mi(3);
	p->print(std::cout);
	return 0;
}
