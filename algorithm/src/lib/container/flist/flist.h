#ifndef SLIST_H
#define SLIST_H

#include <iterator>

// node iterator seprated
//
template <typename T>
class _node;

template <typename T>
class _node {
public:
	template <typename... Arg>
	_node(Arg... args) : next_(nullptr), val(T(args...)) { }

	_node<T> *next_;
	T val;
};

template <typename T>
class iter_ : public std::iterator<std::forward_iterator_tag, T>{
public:

	iter_(_node<T> *n = nullptr) : node_(n) { }
	
	T &operator*() { return node_->val; }

	iter_ &operator++() { 
		node_ = node_->next_; 
		return *this; 
	}
	iter_ operator++(int) { 
		auto tmp = this;
		node_ = node_->next;
		return *tmp; 
	}
	
	iter_ &operator--() = delete;
	iter_ operator--(int) = delete;

private:
	_node<T> *node_;
};

template <typename T>
class Slist {
public:
	typedef T value_type;
	typedef T& reference;
	typedef iter_<T> iterator;

	Slist() {}
	
	void insert(const T &);
	
	iterator begin() const { return head_; }

protected:
	std::allocator<T> alloc;

private:
	iterator head_;
};

#include "flist.tcc"

#endif
