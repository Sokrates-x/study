#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <array>

void f()
{
}
class A
{
public:
	int a[10];
};

int main(int argc, char **argv)
{
	std::cout << std::left;
	std::cout << std::setw(12) << "char:" << sizeof(char) << '\n';
	std::cout << std::setw(12) << "wchar:" << sizeof(wchar_t) << '\n';
	std::cout << std::setw(12) << "int:" << sizeof(int) << '\n';
	std::cout << std::setw(12) << "short:" << sizeof(short) << '\n';
	std::cout << std::setw(12) << "long:" << sizeof(long) << '\n';
	std::cout << std::setw(12) << "long long:" << sizeof(long long) << '\n';
	std::cout << std::setw(12) << "float:" << sizeof(float) << '\n';
	std::cout << std::setw(12) << "double:" << sizeof(double) << '\n';
	std::cout << std::setw(12) << "l double:" << sizeof(long double) << '\n';
	std::cout << std::setw(12) << "string:" << sizeof(std::string) << '\n';
	std::cout << std::setw(12) << "ivec:" << sizeof(std::vector<int>) << '\n';
	std::cout << std::setw(12) << "svec:" << sizeof(std::vector<std::string>) << '\n';
	std::cout << std::setw(12) << "dvec:" << sizeof(std::vector<double>) << '\n';
	std::cout << std::setw(12) << "iset:" << sizeof(std::set<int>) << '\n';
	std::cout << std::setw(12) << "iimap:" << sizeof(std::map<int, int>) << '\n';
	std::cout << std::setw(12) << "int *:" << sizeof(int *) << '\n';
	std::cout << std::setw(12) << "int &:" << sizeof(int &) << '\n';
	std::cout << std::setw(12) << "ilist:" << sizeof(std::list<int>) << '\n';
	std::cout << std::setw(12) << "iflist:" << sizeof(std::forward_list<int>) << '\n';
	std::cout << std::setw(12) << "ideque:" << sizeof(std::deque<int>) << '\n';
	std::cout << std::setw(12) << "int &&:" << sizeof(int &&) << '\n';
	std::cout << std::setw(12) << "boll:" << sizeof(bool) << '\n';
	std::cout << std::setw(12) << "iarr32" << sizeof(std::array<int, 32>) << '\n';
	std::cout << std::setw(12) << "int[32]" << sizeof(int [32]) << '\n';
	int ia[32], *p = ia;
	std::cout << std::setw(12) << "int *[32]" << sizeof p << '\n';
	std::cout << std::setw(12) << "int " << sizeof *ia << '\n';
	std::cout << std::setw(12) << "int " << sizeof *p << '\n';
	A a, *ap = &a;
	std::cout << std::setw(12) << "int " << sizeof ap->a[9] << '\n';
	std::cout << ap->a[9] << std::endl;
	std::cout << sizeof f() << std::endl;
	std::cout << sizeof(void) << std::endl;
	return 0;
}
