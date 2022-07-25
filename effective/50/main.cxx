// placement new
#include <iostream>
#include <new>
#include <vector>
#include <memory>
#include <cstddef>

class C {
public:
	C(const std::vector<int> &s) : vec_(s) {} 
	~C() { std::cout << "Destructor of C" << std::endl; }
	std::vector<int> vec_;
};

int main(int, char **)
{
	int *p(static_cast<int *>(malloc(sizeof(int) * 5)));
	new(p) int(5);
	new(p) int(6);
	std::cout << *p << std::endl;
	delete p;
	std::cout << *p << std::endl;
	//free(p);
	//std::cout << *++p << std::endl;
	
	std::allocator<int> alloc;
	int *p1 = alloc.allocate(sizeof(int) * 5);
	std::construct_at(p1, 5);
	//new(p1) int(3);
	std::cout << *p1 << std::endl;
	std::destroy_at(p1);
	std::destroy_at(p1);
	delete p1;
	std::cout << *p1 << std::endl;
	//alloc.deallocate(p1, 600);
	std::cout << *p1 << std::endl;

	std::vector<int> v;
	v.push_back(2);

	std::allocator<C> alloc2;
	C *p2 = alloc2.allocate(sizeof(C) * 3);
	std::construct_at(p2, v);
	std::cout << *(p2->vec_.begin()) << std::endl;
	//std::destroy_at(p2);
	//std::cout << *(p2->vec_.begin()) << std::endl;
	delete p2;	
	std::cout << *(p2->vec_.begin()) << std::endl;
	return 0;
}
