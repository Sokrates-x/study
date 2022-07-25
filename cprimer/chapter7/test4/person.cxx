#include "person.h"
#include <iomanip>

std::istream &Person::read(std::istream &is)
{
	is >> name_ >> address_;
	return is;
}

std::ostream &Person::print(std::ostream &os) const
{
	os << std::left;
	os << std::setw(12) << "Name:" << std::setw(12) << name_ << '\n';
	os << std::setw(12) << "Address:" << std::setw(12) << address_ << '\n';
	return os;
}

Person::Person(std::istream &is)
{
	read(is);
}

Person::Person(const std::string &n, const std::string &a) : name_(n),
	address_(a) {}
