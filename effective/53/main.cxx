#include <iostream>

struct B {
	virtual void f() const {
		std::cout << "B" << std::endl;
	}	
};

struct D : public B {
	void f() const {
		std::cout << "D" << std::endl;
	}	
};

int main(int, char **)
{
	B b;
	D d;
	d.f();
	B *p = new D;
	p->f();
	return 0;
}
