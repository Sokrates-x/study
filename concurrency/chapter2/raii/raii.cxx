#include <iostream>
#include <thread>
#include <functional>

class C {
public:
	C(int &i) : i_(i) {}
	void operator()() {
		for (int i = 0; i < 100000; ++i)
			std::cout << ++i_ << std::endl;
	}
private:
	int &i_;
};

/**
 * RAII means Resource Acquire in initialisation
 */

class Raii {
public:
	explicit Raii(std::function<void ()> f) : t(f) {
	}
	~Raii() {
		if (t.joinable())
			t.join();
	}
	Raii(const Raii &) = delete;
	Raii &operator=(const Raii &) = delete;

private:
	std::thread t;	
};

void f() {
	int i = 100;
	Raii r{C(i)};
}

int main(int, char **)
{
	f();	
	return 0;
}
