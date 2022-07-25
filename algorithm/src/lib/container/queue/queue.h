#ifndef QUEUE_H
#define QUEUE_H

#include <memory>

template <typename T>
class Queue {
public:
	typedef T value_type;
	typedef T* pointer;
	
	Queue();

	Queue(const Queue &) = delete;
	Queue(Queue &&) = delete;

	Queue &operator=(const Queue &) = delete;
	Queue &operator=(Queue &&) = delete;

	~Queue();

	size_t size() const { return last_ - first_; }
	bool empty() const { return last_ == first_; }
	size_t capcity() const { return last_ - first_ + front_capcity_ + 
								back_capcity_; }

	void enqueue(const T &);
	T dequeue();

	void free();

	std::allocator<T> alloc;

private:

	pointer first_ = nullptr;
	pointer last_ = nullptr;
	size_t front_capcity_ = 0;
	size_t back_capcity_ = 10;
	size_t last_back_capcity_ = 10;
};

#include "queue_i.h"

#endif
