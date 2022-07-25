#ifndef EXAMPLE_CSTGY_H
#define EXAMPLE_CSTGY_H 1

class Strategy;

class Example_cstgy_base {
public:
	explicit Example_cstgy_base(Strategy &s) : stgy_(s) {}
	virtual ~Example_cstgy_base() {}

	// ...
	void do_somthing();
	
private:
	Strategy &stgy_;
};

class Example_cstgy : public Example_cstgy_base {
public:
	explicit Example_cstgy(Strategy &s) : Example_cstgy_base(s) {}
};

#endif // EXAMPLE_CSTGY_H
