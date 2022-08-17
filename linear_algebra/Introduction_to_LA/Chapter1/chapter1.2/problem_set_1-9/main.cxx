#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cassert>

int main(int, char **)
{
	// Problem 1
	std::cout << "Problem 1" << std::endl;
	Eigen::Vector2f v1_u, v1_v, v1_w;
	v1_u << -.6, .8;
	v1_v << 4, 3;
	v1_w << 1, 2;
	std::cout << "u dot v = " << v1_u.dot(v1_v) << '\n';
	std::cout << "u dot w = " << v1_u.dot(v1_w) << '\n';
	std::cout << "u dot (v + w)= " << v1_u.dot(v1_v + v1_w) << '\n';

	// Problem 2
	std::cout << "Problem 2" << std::endl;
	Eigen::Vector2f v2_u, v2_v, v2_w;
	v2_u << -.6, .8;
	v2_v << 4, 3;
	v2_w << 1, 2;
	std::cout << "u len: " << v2_u.norm() << '\n';
	std::cout << "v len: " << v2_v.norm() << '\n';
	std::cout << "w len: " << v2_w.norm() << '\n';
	// Schwarz inequalities
	assert(std::abs(v2_u.dot(v2_v)) <= v2_u.norm() * v2_v.norm());
	assert(std::abs(v2_v.dot(v2_w)) <= v2_v.norm() * v2_w.norm());
	
	// Problem 3
	std::cout << "Problem 3" << std::endl;
	Eigen::Vector2f v3_u, v3_v, v3_w;
	v3_u << -.6, .8;
	v3_v << 4, 3;
	v3_w << 1, 2;
	std::cout << "u direction: " << v3_u.transpose() << '\n';  
	std::cout << "u cosine: " << v3_u(0) << '\n';
	std::cout << "v direction: " << v3_v.transpose()/v3_v.norm() << '\n';	
	std::cout << "v cosine: " << v3_v(0)/v3_v.norm() << '\n';
	std::cout << "w direction: " << v3_w.transpose()/v3_w.norm() << '\n';	
	std::cout << "w cosine: " << v3_w(0)/v3_w.norm() << '\n';
	std::cout << "A solution 4 0 deg: " << 2 * v3_w.transpose() << '\n';
	std::cout << "A solution 4 90 deg: " << "1 -0.5" << '\n';
	std::cout << "A solution 4 180 deg: " << -2 * v3_w.transpose() << '\n';

	// Problem 4
	std::cout << "Problem 4" << std::endl;
	

	
	return 0;
}
