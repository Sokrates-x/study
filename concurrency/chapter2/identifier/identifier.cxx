#include <thread>
#include <iostream>

void f (){
	std::cout << std::this_thread::get_id() << std::endl;
}

int main()
{
	std::cout << std::this_thread::get_id() << std::endl;
	f();
	std::thread t(f);
	std::cout << t.get_id() << std::endl;
	t.join();
	return 0;	
}
