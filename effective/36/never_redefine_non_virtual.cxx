#include <iostream>

class Base {
public:
	Base() = default;
	virtual ~Base() {}
	void f() {
		std::cout << "Base:: Call f()" << std::endl;
	}
};

class Derived : public Base {
public:
	void f() {
		std::cout << "Derived:: Call f()" << std::endl;
	}
};

int main(int, char **)
{
	Derived *pd = new Derived; 
	Base *pb = pd;
	std::cout << "Same Object behave differently" << std::endl;
	pb->f();
	pd->f();
	return 0;
}
