#include <iostream>
#include <iomanip>

class Person;

void print(Person);

class Person {
public:
	friend void print(Person);
	Person(std::string s) : name_(s) { }

private:
	std::string name_;
	std::string addr_ = "bjtu";
};

void print(Person p)
{
	std::cout << std::left;
	std::cout << std::setw(12) << "Name:" << std::setw(12) << p.name_ << '\n';
	std::cout << std::setw(12) << "Addr:" << std::setw(12) << p.addr_ << '\n';
}

int main(int, char **)
{
	print(std::string("hello"));
	return 0;
}
