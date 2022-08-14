#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	Eigen::MatrixXd m(2, 2);

	std::cout << m << std::endl;

	return 0;
}
