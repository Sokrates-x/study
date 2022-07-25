// new handler 
// resource class
// mixin
// template statics
// operator new
// throw new nothrow new

#include <new>
#include <iostream>

class NewHandlerHolder {
public:

	NewHandlerHolder(std::new_handler n) : curr_handler_(n) {}
	~NewHandlerHolder() {
		std::cout << "reset the new handler." << std::endl;
		std::set_new_handler(curr_handler_); 
	}

	NewHandlerHolder(const NewHandlerHolder &) = delete;
	NewHandlerHolder(NewHandlerHolder &&) = delete;
	NewHandlerHolder &operator=(const NewHandlerHolder &) = delete;
	NewHandlerHolder &operator=(NewHandlerHolder &&) = delete;

private:
	std::new_handler curr_handler_; 
};

template <typename T>
class NewHandler {
public:

	static std::new_handler set_new_handler(std::new_handler n) {
		auto tmp = std::get_new_handler();
		curr_new_handler = n;
		return tmp;
	}

	static void *operator new[](std::size_t sz) throw() {
		std::cout << "set new_handler out_of_memory" << std::endl;
		NewHandlerHolder h(std::set_new_handler(curr_new_handler)); 
		std::cout << "::new" << std::endl;
		return ::operator new(sz);
	}

private:
	
	static std::new_handler curr_new_handler;
};

template <typename T>
std::new_handler NewHandler<T>::curr_new_handler = nullptr;

class Widget;

void out_of_memory()
{
	std::cerr << "Error: Bad_Alloc. Run out of Memory. abort()." << std::endl;
	std::abort();
}


class Widget : public NewHandler<Widget>
{
public:	

	Widget() {}
	
};


int main(int, char **)
{
	Widget::set_new_handler(out_of_memory);	
	Widget *p= new Widget[10];
	Widget *p2= new Widget[10];
//	delete [] p;
//	int *pp = new int[1000000000000000];
	return 0;
}
