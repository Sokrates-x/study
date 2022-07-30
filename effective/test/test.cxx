/**
 * validate the coversions from derived to base of shared_ptrs
 * cast from base to derived or derived to base acts seems trivil
 */

#include <iostream>
#include <memory>

class Base {
public:
	Base()=default;
	virtual ~Base() {
		std::cout << "Dtor of Base Exec." << std::endl;
	}

	virtual void f() {
		std::cout << "Base calling f()" << std::endl;
	}
};

class Derived : public Base {
public:
	~Derived() {
		std::cout << "Dtor of Derived Exec." << std::endl;
	}

	void f() {
		std::cout << "Derived calling f()" << std::endl;
	}
};

int main(int, char **)
{
	std::shared_ptr<const Base> spb;	
	std::shared_ptr<Derived> spd(new Derived);
	Derived *pd = new Derived;
	spb.reset(pd);
	//spb->f();
	//spb.get()->f();
	auto p =std::const_pointer_cast<Base>(spb);
	p->f();
	return 0;
}

