#ifndef STACK_H
#define STACK_H

#include <memory>

template <typename T>
class Stack {

public:

	typedef T value_type;
	typedef T* pointer;

	Stack() : top_(nullptr), size_(0) { }
	
	Stack(const Stack &) = delete;
	Stack(Stack &&) = delete;

	Stack &operator=(const Stack &) = delete;
	Stack &operator=(Stack &&) = delete;

	~Stack();

	void free();
		
	void push(const T &);
	T pop();
	
	bool empty() const { return size_ == 0; }
	size_t size() const { return size_; }
	
protected:
	std::allocator<T> alloc;

private:
	pointer top_;
	size_t size_;
};

#include "stack_i.h"

#endif
