#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

// Very Important
using std::istream;
using std::ostream;

class Sales_data
{
public:

	friend Sales_data operator+(const Sales_data &, const Sales_data &);

	friend std::ostream &operator<<(std::ostream &, const Sales_data &);

	Sales_data() = default;

	Sales_data(std::istream &);

	Sales_data(const std::string &, int, double);

	Sales_data &operator+=(const Sales_data &) &;

private:

	bool checkISBN(const Sales_data &) const;

	std::string ISBN_;
	int unitsSold_;	
	double price_;

};

#endif
