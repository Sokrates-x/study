/**
 * keep away from return a handle (pointer or reference)
 * actually, i think this item is so strict that i can't completely agree
 * with. i think keep away from referenc or point to a soon to be deleted 
 * object is enough
 */

#include <iostream>

class C {
public:

	~C() {
		val_ = 1;
	}
	const int &val() { return val_; }
	const int cval() { return val_; }
	
private:
	int val_ = 3;
};

int main(int, char **)
{		
	// ok, right, it seems that the author is correct, the const int & return
	// type makes it possible to point to it, and the dtor is exec already
	// the pointer will point to wrong value but the complier does't do any
	// thing, it's very dangerous. if the return type is rvalue like int or 
	// const int, the compiler works.
	// more dangerous code
	const int *p = &(C().val());
	// wrong but safe code
	//p = &(C().cval());

	std::cout << *p << std::endl;
	return 0;
}
