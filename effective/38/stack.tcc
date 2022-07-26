#include "stack.h"

template <typename T>
void Stack<T>::push(const T &val) {
	vec_.push_back(val);
}

template <typename T>
void Stack<T>::pop() {
	vec_.pop_back();
}

template <typename T>
T Stack<T>::top() const {
	return *vec_.rbegin();
}

template <typename T>
bool Stack<T>::empty() const {
	return vec_.empty();
}
