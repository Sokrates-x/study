#include <vector>

class NoDefault {
public:
	explicit NoDefault(int i) : i(i) { }

private:
	int i;
};

class D {
public:

private:
	NoDefault nd;
};

class C {
public:
	C() : nd(0) { }
	C(int i) : nd(i) { }
	
private:
	NoDefault nd;
};

int main(int, char **)
{
	C c;
	//NoDefault nd;
	D d;	
	std::vector<C> v;
	std::vector<NoDefault> v1;
//	std::vector<NoDefault> v2(10);
	return 0;
}
