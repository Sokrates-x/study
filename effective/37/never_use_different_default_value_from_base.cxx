#include <iostream>

class Base {
public:
	Base() = default;
	virtual ~Base() {}
	virtual void f(int i = 10) {
		std::cout << "The default No. is: " << i << std::endl;
	}
};

class Derived : public Base {
public:
	void f(int i = 100) {
		std::cout << "The default No, is: " << i << std::endl;
	}
};

int main(int, char **)
{
	Derived *pd = new Derived;
	Base *pb = pd;
	std::cout << "Same Object behave Differently because of the default parameter." << std::endl;
	pb->f();
	pd->f();
	return 0;
}
