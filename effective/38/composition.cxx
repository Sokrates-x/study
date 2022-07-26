/**
 * Composition means 'has a' relation or 'is implementated in-terms-of'
 * For example, a stack may be implementated in-terms-of a vector 
 * But a stack 'is a' vector is incorrect
 */

#include "stack.h"
#include <iostream>
#include <iomanip>

int main(int, char **)
{
	Stack<std::string> s;
	s.push("hello");
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << std::boolalpha << s.empty() << std::endl;
	return 0;
}
