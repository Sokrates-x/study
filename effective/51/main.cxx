#include <iostream>

#include "c.h"

int main(int, char **)
{
	_do_new_for<C>::add_new_handler(out_of_memory1);
	_do_new_for<C>::add_new_handler(out_of_memory2);
	_do_new_for<C>::add_new_handler(out_of_memory3);
	_do_new_for<C>::set_new_handler(out_of_memory1);

	C *p = new C[10000000000];
	std::cout << p->i() << " " << p->j() << std::endl;
	delete p;
	return 0;
}
