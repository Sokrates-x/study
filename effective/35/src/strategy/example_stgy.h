#ifndef EXAMPLE_STGY_H
#define EXAMPLE_STGY_H 1

/**
 * Another NVI method. RunTime selectable. Less Effective. Low Pakeged.
 * Functions need more info of the class.
 */

// aviliable fuctions
void f1();
void f2();
void f3();

class Example_stgy_base {
public:
	typedef void (*Func)();
	explicit Example_stgy_base(Func f = f1) : func_(f) {}
	// dtor always virtual
	virtual ~Example_stgy_base() {}

	// just do_somthing 
	void do_somthing();

private:
	Func func_;	
};

class Example_stgy : public Example_stgy_base {
public:
	using Example_stgy_base::Func;
	explicit Example_stgy(Func f) : Example_stgy_base(f) {}
};

#endif // EXAMPLE_STGY_H
