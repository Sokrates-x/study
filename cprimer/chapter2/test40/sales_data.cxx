#include <iostream>

#include "sales_data.h"

Sales_data operator+(const Sales_data &s1, const Sales_data &s2)
{
	if (!s1.checkISBN(s2))
	{
		std::cerr << "Error: ISBN Check Failed!!" << std::endl;
		return s1;
	}
	return Sales_data(s1.ISBN_, s1.unitsSold_ + s2.unitsSold_, s1.price_); 
}

std::ostream &operator<<(std::ostream &os, const Sales_data &s)
{
	os << "ISBN: " << s.ISBN_ << '\n';
	os << "Units Sold:" << s.unitsSold_ << '\n';
	os << "Price: " << s.price_ << '\n';	
	os << "Total Price: " << s.price_ * s.unitsSold_ << '\n';
	return os;
}

Sales_data::Sales_data(std::istream &is)
{
	is >> ISBN_;
	is >> unitsSold_;
	is >> price_;
}

Sales_data::Sales_data(const std::string &s, int i, double d)
	: ISBN_(s), unitsSold_(i), price_(d)
{ }

Sales_data &Sales_data::operator+=(const Sales_data &s) &
{
	if(!this->checkISBN(s))
	{
		std::cerr << "Error: ISBN Check Failed!!" << std::endl;
		return *this;
	}
	this->unitsSold_ += s.unitsSold_;
	return *this;
}

bool Sales_data::checkISBN(const Sales_data &s) const
{
	return this->ISBN_ == s.ISBN_;
}
