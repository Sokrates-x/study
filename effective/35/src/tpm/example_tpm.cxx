#include "example_tpm.h"
#include <iostream>

void Example_tpm_base::do_somthing() {
	// initialise
	std::cout << "Base: Initialise: " << std::endl;
	// step 1
	do_step1();
	// step 2
	do_step2();
	// step 3
	do_step3();
	// step ...
	// end
	std::cout << "Base: End." << std::endl;
}

void Example_tpm_base::do_step1() {
	std::cout << "Base: the default step one..." << std::endl;
}

void Example_tpm_base::do_step2() {
	std::cout << "Base: the default step two..." << std::endl;
}

void Example_tpm_base::do_step3() {
	std::cout << "Base: the default step three..." << std::endl;
}

void Example_tpm::do_step1() {
	std::cout << "Derived: the SPECIAL step one..." << std::endl;
}

void Example_tpm::do_step3() {
	std::cout << "Derived: the SPECIAL step three..." << std::endl;
}
