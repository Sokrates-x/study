#include <iostream>

void print();

class A
{
public:
	friend void print() {
		std::cout << "hello" << std::endl;
	}
private:
	int pri_ = 1;
};

void print();

int main()
{
	A a;
	print();
	return 0;
}
