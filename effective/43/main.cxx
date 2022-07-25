#include <iostream>


class Base {
public:

	virtual void f1() = 0;
	virtual void f2();
	void f3();
protected:
	void default_f();
};

void Base::f1() {
	std::cout << "Base's pure virtual public function. Just for derived's "
		<< "implemention" << std::endl;
}
void Base::f2() {
	std::cout << "Base's virtual public function. For interface & default "
		<< "implemention." << std::endl;
}
void Base::f3() {
	std::cout << "Base's public non-virtual function. For interface & "
		<< "implemention. Base's invariance. " << std::endl;
}
void Base::default_f() {
	std::cout << "Base's protected non-virtual function. For derived's "
		<< "implemention" << std::endl;
}

class Derived : public Base {
public:
	// must be implemented
	virtual void f1();
	// choose to be implemented
	virtual void f2();
	// must not be implemented
	// void f3();
};

void Derived::f1() {
	// interface impelement divided
	// can't be protected
	Base::f1();
	// two much functions
	default_f();
	std::cout << "Derived's added implementions." << std::endl;
}

void Derived::f2() {
	// can't divide interface & implemention
	std::cout << "Derived's replace implementions." << std::endl;
}

int main(int, char **)
{
	Base *p = new Derived;
	// virtual
	p->f1();
	p->f2();
	// actual
	p->f3();	
	return 0;
}
