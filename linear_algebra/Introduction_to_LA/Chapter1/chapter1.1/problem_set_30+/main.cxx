#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	// Problem 30
	std::cout << "Problem 30" << std::endl;
	Eigen::Matrix4f m0_A;
	m0_A.setZero();
	Eigen::Matrix4f m0_A_kernel = m0_A.fullPivLu().kernel();
	std::cout << "col of 0 matrix's kernel is a base" << std::endl;
	std::cout << m0_A_kernel << std::endl;

	// Problem 31
	std::cout << "Problem 31" << std::endl;
	Eigen::Matrix3f m1_A;		
	m1_A << 2, -1, 0, -1, 2, -1, 0, -1, 2;
	Eigen::Vector3f v1_b;	
	v1_b << 1, 0, 0;
	Eigen::Vector3f v1_x = m1_A.fullPivLu().solve(v1_b);
	std::cout << "A Solution: " << v1_x.transpose() << std::endl;

	return 0;
}
