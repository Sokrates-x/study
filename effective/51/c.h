#ifndef C_H
#define C_H 1

#include <iostream>
#include <new>
#include <stack>

class _new_handler_holder {
public:
	_new_handler_holder(std::new_handler p = nullptr) : nh_(p) {}
	~_new_handler_holder() {
		std::cout << "Set new handler back." << std::endl;
		std::set_new_handler(nh_);
	}
private:
	std::new_handler nh_;
};

template <typename T>
class _do_new_for {
public:

	// do not really set_new_handler just store the new_handler
	static std::new_handler set_new_handler(std::new_handler p) {
		nh_ = p;
		return std::get_new_handler();
	}
	static void add_new_handler(std::new_handler p) {
		nhstack_.push(p);
	}

	// implicit static
	template <typename... Args>
	void *operator new[](std::size_t sz, Args... args) throw() {
		//
		nhstack_.push(nh_);
		while (!nhstack_.empty()) { 
			nh_ = nhstack_.top();
			nhstack_.pop();
			if (void *p = malloc(sz))
				return ::new(p) T(args...);
			_new_handler_holder nhh(std::set_new_handler(nh_));
			(*nh_)();
			std::cout << "normal new in _do_new_for template" << std::endl;
		}
		return ::operator new[](sz, args...);
	}

	void operator delete(void *p, std::size_t sz) throw() {
		std::cout << "normal delete in _do_new_for template" << std::endl;
		return ::operator delete(p, sz);
	}

private:
	static std::new_handler nh_;
	static std::stack<std::new_handler> nhstack_;
};

void out_of_memory1()
{
	std::cout << "Trying to handle new operation...(1)." << std::endl;
}

void out_of_memory2()
{
	std::cout << "Trying to handle new operation...(2)." << std::endl;
}

void out_of_memory3()
{
	std::cout << "Trying to handle new operation...(3)." << std::endl;
}

class C;

template <typename T>
std::new_handler _do_new_for<T>::nh_ = nullptr;

template <typename T>
std::stack<std::new_handler> _do_new_for<T>::nhstack_;

class C : public _do_new_for<C> {
public:
	explicit C(int i = 1, int j = 2) : i_(i), j_(j) {}

	virtual ~C() {}

	int i() const { return i_; }
	int j() const { return j_; }

private:
	int i_;	
	int j_;
};

#endif // C_H
