#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	double a = 3.14;
	std::cout << ++a << std::endl;
	
	std::string str("hello, linux");
	auto iter = str.begin();
	std::cout << ++*iter << std::endl;
	std::cout << *iter++ << std::endl;

	std::vector<std::string> svec(2);
	auto iteri = svec.begin(); 
	//std::cout << ++iteri->empty() << std::endl;
	std::cout << iteri++->empty() << std::endl;
	return 0;
}
