#include <iostream>
#include <eigen3/Eigen/Dense>
#include <iterator>
#include <functional>
#include "quick_sort.tcc"

int main(int, char **)
{
	std::vector<int> vec{ 5, 1, 3, 4, 2, 6 };
	Eigen::MatrixXi mat(2, 3);
	mat.setOnes();	

	std::copy(vec.begin(), vec.end(), mat.reshaped().begin());

	quickSort(mat.reshaped().begin(), mat.reshaped().end());

	std::copy(mat.reshaped().begin(), mat.reshaped().end(), 
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
