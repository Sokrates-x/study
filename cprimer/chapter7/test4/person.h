#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
public:

	// ctors
	Person() = default;
	explicit Person(std::istream &);
	Person(const std::string &, const std::string &);

	std::istream &read(std::istream &);
	std::ostream &print(std::ostream &) const;

	std::string name() const { return name_; }
	std::string address() const { return name_; }
	
private:
	std::string name_;
	std::string address_;
};

#endif
