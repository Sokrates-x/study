#include "matrix.h"

#include <iostream>
#include <iterator>
#include <functional>

int main(int, char **)
{
	Matrix<int> m1(12, 3, 3);
	Matrix<int> m2(12, 2, 3);
//	Matrix<int> m = m1 + m2;
	Matrix<int> m(12, 1, 3); 
	m = (m1 - m2);
	
	std::cout << m.size() << " " << m.row_sz() << std::endl;
	std::copy(m.begin(), m.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
