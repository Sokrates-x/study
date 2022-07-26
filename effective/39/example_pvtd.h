#ifndef EXAMPLE_PVTD_H
#define EXAMPLE_PVTD_H 1

#include <iostream>

class ExPvtd_base {
public:
	ExPvtd_base() = default;
	virtual ~ExPvtd_base() {}
protected:
	virtual void f() {
		std::cout << "Base: dosomthing as Base." << std::endl;
	}
};

class ExPvtd : private ExPvtd_base {
public:
	void do_somthing() {
		f();
	}
private:
	void f() final {
		std::cout << "Do some special things." << std::endl;
		ExPvtd_base::f();
		std::cout << "I don't want my deriveds redefine me." << std::endl;
	}
};

#endif
