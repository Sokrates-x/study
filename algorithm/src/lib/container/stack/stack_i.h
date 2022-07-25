#include "stack.h"
#include <cassert>

template <typename T>
void Stack<T>::push(const T &val)
{
	auto p = alloc.allocate(sizeof(T)*(size_ + 1));
	std::uninitialized_copy(top_ - size_ + 1, top_ + 1, p);
	free();
	top_ = p + size_++;
	// c++ 20
	std::construct_at(top_, val);
}

template <typename T>
T Stack<T>::pop()
{
	assert(!empty());
	
	T val = *top_;	
	auto p = alloc.allocate(sizeof(T)*(size_ - 1));
	std::uninitialized_copy(top_ - size_ + 1, top_, p);
	free();
	top_ = p + --size_ - 1;
	return val;	
}

template <typename T>
void Stack<T>::free()
{
	// c++ 17
	if (!empty())
	{
		std::destroy(top_ + 1 - size_, top_ + 1);
		alloc.deallocate(top_ - size_ + 1, size_);
		top_ = nullptr;
	}
}

template <typename T>
Stack<T>::~Stack()
{
	free();
}
