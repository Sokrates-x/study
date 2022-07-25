#include "example_stgy.h"
#include <iostream>

void f1() {
	std::cout << "I'm F1, the default function..." << std::endl;
}

void f2() {
	std::cout << "I'm F2, another available function..." << std::endl;
}

void f3() {
	std::cout << "I'm F3, another available function..." << std::endl;
}

void Example_stgy_base::do_somthing() {
	func_();
}
