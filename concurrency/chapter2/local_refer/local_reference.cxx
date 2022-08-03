#include <thread>
#include <iostream>

class C {
public:
	C(int &i) : i_(i) {}
	void operator()() {
		for (int j = 0; j < 1000000; ++j)
			std::cout << ++i_ << std::endl;
	}
private:
	int &i_;
};

void g() {
	int i = 100;
	std::thread t{C(i)};
	t.detach();
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
