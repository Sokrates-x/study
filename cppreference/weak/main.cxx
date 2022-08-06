#include <memory>
#include <iostream>

int main(int, char **)
{
	auto p = std::make_shared<int>(3);

	std::cout << *p << std::endl;
	{
		auto pp = std::make_shared<int>(4);
		std::weak_ptr<int> wp(pp);
		p = wp.lock();
	}

	std::cout << *p << std::endl;
	return 0;
}
