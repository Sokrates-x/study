#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	// Problem 10
	std::cout << "Problem 10" << std::endl;
	Eigen::Vector3i v0_i, v0_j, v0_k;
	v0_i << 1, 0, 0;
	v0_j << 0, 1, 0;
	v0_k << 0, 0, 1;
	std::cout << "i + j = " << (v0_i + v0_j).transpose() << '\n';
	std::cout << "i + j + k = " << (v0_i + v0_j + v0_k).transpose() << '\n';

	// Problem 11
	std::cout << "Problem 11" << std::endl;
	std::cout << "Edge Number: " << 3 * 8 / 2 << std::endl;

	// Problem 12
	std::cout << "Problem 12" << std::endl;
	Eigen::Vector3i v2_i, v2_j;
	v2_i << 1, 0, 0;
	v2_j << 0, 1, 0;
	std::cout << "The normal of the plane is : " << 
		v2_i.cross(v2_i + v2_j).transpose() << std::endl;

	// Problem 13
	std::cout << "Problem 13" << std::endl;
	std::cout << "Sum is Zero\n";	
	std::cout << "2:00 Vector is: " << 
		Eigen::Vector2f(M_PI/3, M_PI/6).array().sin().transpose() << '\n';

	// Problem 14
	std::cout << "Problem 14" << std::endl;
	std::cout << "New Sum is: 12\n";
	
	// Problem 15
	std::cout << "Problem 15" << std::endl;
	
	// Problem 16 
	std::cout << "Problem 16" << std::endl;
	std::cout << "A line defined by the two end points of w & v\n";

	// Problem 17
	std::cout << "Problem 16" << std::endl;
	std::cout << "A diagnol of the parallelogram defined by edge w & v\n";

	// Problem 18 
	std::cout << "Problem 18" << std::endl;
	std::cout << "A parallelogram defined by edge w & v\n";

	// Problem 19 
	std::cout << "Problem 19" << std::endl;
	std::cout << "A cone defined by half line 0w & 0v\n";

	return 0;
}
