#include "queue.h"
#include <iostream>
#include <cassert>

template <typename T>
Queue<T>::Queue()
{
	auto p = alloc.allocate(sizeof(T) * capcity());
	first_ = p;
	last_ = p;
}

template <typename T>
void Queue<T>::free()
{
	if (!empty())
	{
		// c++ 17
		std::destroy(first_, last_);
		alloc.deallocate(first_ - front_capcity_, capcity());
		first_ = last_ = nullptr;
	}
}

template <typename T>
void Queue<T>::enqueue(const T &val)
{
	if (back_capcity_)
	{
		// c++ 20
		std::construct_at(last_++, val);	
		--back_capcity_;
	}
	else
	{
		// front_capcity > back_capcity_ from last alloc or move
		// move without reallocate
		if (front_capcity_ > last_back_capcity_)	
		{
			// c++ 17
			std::uninitialized_move(first_, last_, first_ - front_capcity_);
			first_ = first_ - front_capcity_;
			last_ = last_ - front_capcity_;
			back_capcity_ = front_capcity_ - 1;
			last_back_capcity_ = back_capcity_;
			front_capcity_ = 0;
			
			// c++ 20
			std::construct_at(last_++, val);
		}
		// reallocate and move
		else
		{
			auto p = alloc.allocate(sizeof(T) * capcity() * 2);
			size_t cap = capcity();
			size_t sz = size();

			// c++ 17
			std::uninitialized_move(first_, last_, p);
			free();

			back_capcity_ = front_capcity_ + cap - 1;
			last_back_capcity_ = back_capcity_;
			front_capcity_ = 0;
			first_ = p;
			last_ = p + sz;

			// c++ 20
			std::construct_at(last_++, val); 
		}
	}
}

template <typename T>
T Queue<T>::dequeue()
{
	assert(!empty());
	T val = *first_;
	++first_;
	++front_capcity_;

	// two many val dequeued from queue shrink the queue size
	if (front_capcity_ > last_back_capcity_)
	{
		// move to front c++ 17	
		// realloc & move because of no way to dealloc the lasts alone
		auto p = alloc.allocate(sizeof(T) * (size() + last_back_capcity_));	
		// move	
		auto sz = size();
		std::uninitialized_move(first_, last_, p);
		free();
		first_ = p;
		last_ = p + sz;
		back_capcity_ = last_back_capcity_;
		front_capcity_ = 0;
	}
	return val;
}

template <typename T>
Queue<T>::~Queue()
{
	free();	
}
