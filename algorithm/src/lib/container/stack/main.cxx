#include <iostream>
#include "stack.h"

int main(int, char **)
{

	Stack<int> s;

	s.push(1);

	s.push(2);

	std::cout << s.pop() << std::endl;

	s.push(3);

	std::cout << s.pop() << std::endl;

	return 0;
}
