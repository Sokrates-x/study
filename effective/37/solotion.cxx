#include <iostream>

class Base {
public:
	Base() = default;
	virtual ~Base() {}
	void f(int i = 10) {
		f_(i);
	}
private:
	virtual void f_(int i) {
		std::cout << "Base: The default No. is: " << i << std::endl;
	}
};

class Derived : public Base {
	void f_(int i) {
		std::cout << "Derived: The default No, is: " << i << std::endl;
	}
};

int main(int, char **)
{
	Derived *pd = new Derived;
	Base *pb = pd;
	std::cout << "Then, we can always use the same default parameter." << std::endl;
	pb->f();
	pd->f();
	return 0;
}
