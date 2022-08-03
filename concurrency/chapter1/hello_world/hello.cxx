#include <iostream>
#include <thread>

void hello() {
	std::cout << "Hello Concurrent World\n";
}
int main(int, char **)
{
	std::thread t(hello);	
	t.detach();
	for (int i = 1; i < 100; ++i) {
		std::cout << "emmmm...." << std::endl;
	}
	return 0;
}
