#include <iostream>

class A {
public:
	A(int i = 0) : i(i) { }
	A(std::istream &is = std::cin) { is >> i; }	

private:
	int i;
};

int a(int i = 1){
	return i;
}

int a(std::istream &is = std::cin) {
	int i;
	is >> i;
	return i;
}

int main(int, char **)
{
	a();
	return 0;
}
