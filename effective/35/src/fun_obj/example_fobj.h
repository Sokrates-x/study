#ifndef EXAMPLE_FOBJ_H
#define EXAMPLE_FOBJ_H 1

#include <functional>
#include <iostream>

/**
 * See also Strategy.
 */

void fobj1();
extern std::function<void ()> fobj2;
extern std::function<void ()> fobj3;
extern std::function<void ()> fobj4;

class Example_fobj_base {
public:
	typedef std::function<void ()> Fobj;
	explicit Example_fobj_base(Fobj f = fobj1) : fobj_(f) {}
	virtual ~Example_fobj_base() {}

	// do somthing
	void do_somthing();

private:
	Fobj fobj_;
};

class Example_fobj : public Example_fobj_base {
public:
	using Example_fobj_base::Fobj;
	explicit Example_fobj(Fobj f) : Example_fobj_base(f) {}
};

#endif // EXAMPLE_FOBJ_H
