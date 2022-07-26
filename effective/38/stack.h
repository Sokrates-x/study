#ifndef STACK_H
#define STACK_H 1

#include <iostream>
#include <vector>

template <typename T>
class Stack {
public:
	void push(const T &);	
	void pop();
	T top() const;
	bool empty() const;
private:
	std::vector<T> vec_;
};

#include "stack.tcc"
#endif // STACK_H
