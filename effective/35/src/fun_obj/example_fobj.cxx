#include "example_fobj.h"

void fobj1() {
	std::cout << "I'm a normal function." << std::endl;
}

std::function<void ()>  fobj2 = []() {
	std::cout << "I'm a lamda express." << std::endl; };

class obj3 {
public:
	void operator()() { 
		std::cout << "I'm a function object operaotor." << std::endl;
	}
};
std::function<void ()> fobj3 = obj3();

class c {
public:
	void f() {
		std::cout << "I'm a class member function." << std::endl;
	}
};

auto f4 = std::mem_fn(&c::f);
std::function<void ()> fobj4 = std::bind(f4, c());

void Example_fobj_base::do_somthing() {
	fobj_();
}
