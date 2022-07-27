/**
 * type conversion is not a good idea
 * if nessary, use the c++ cast instead of c conversion
 */

#include <iostream>
#include <new>

void f(int &i) {
	i = 2;
}

void fc(const int &i) {
	std::cout << i << std::endl;
}

class Base {
public:
	Base() = default;
	~Base() {}
	virtual void d() {}
};

class Derived : public Base {
public:
	void f(){
		std::cout << "Derived: do somthing" << std::endl;
	}
	void d() {
		Base::d();
		// never use dynamic cast, the meaning is incorrect
		//dynamic_cast<Base>(*this).d();
		std::cout << "Wow." << std::endl;
	}
};

int main(int, char **)
{

	// const_cast remove the const, not safe
	const int &a = 3;
	f(const_cast<int &>(a));
	std::cout << a << std::endl;

	// dynamic cast really slow....
	Base *pb = new Derived;
	dynamic_cast<Derived*>(pb)->f();
	
	// reprient cast : not safe depend on the compiler and the impemention of
	// the objects. any assumption of it is not always correct
	void *p = malloc(sizeof(int) * 3);
	new(p) int(3);
	new(reinterpret_cast<char *>(p)) char('c');
	std::cout << *(static_cast<char *>(p)) << std::endl;	

	// static cast : it seems that it's the most useful one
	// derived -> base
	Derived *pd = new Derived;		
	pb = static_cast<Base *>(pd);
	pb->d();
	// emmm not actually useful
	int i, &ri = i;			
	fc(static_cast<const int &>(ri));
	double d = static_cast<double>(1)/3;	
	std::cout << d << std::endl;

	return 0;
}
