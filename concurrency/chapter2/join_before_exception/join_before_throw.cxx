#include <thread>
#include <iostream>
#include <vector>
#include <stdexcept>

class C {
public:
	C(int &i) : i_(i) {}
	void operator()() {
		for (int j = 0; j < 100000; ++j)
			std::cout << ++i_ << std::endl;
	}
private:
	int &i_;
};

void g() {
	int i = 100;
	std::thread t{C(i)};

	try {
		for (int i = 1; i != 10000000; ++i);
		throw(std::runtime_error("test failed"));
	} catch (...) {
		t.join();
		throw;
	}
	t.join();
	return ;
}

int main(int, char **)
{
	g();
	std::cout << "emm...." << std::endl;
	std::cout << "emm...." << std::endl;
	std::cout << "emm...." << std::endl;
	std::cout << "emm...." << std::endl;
	std::cout << "emm...." << std::endl;
	std::cout << "emm...." << std::endl;
	std::cout << "emm...." << std::endl;
	return 0;
}
