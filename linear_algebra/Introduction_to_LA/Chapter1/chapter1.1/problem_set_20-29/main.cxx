#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	// Problem 20
	std::cout << "Problem 20" << std::endl;
	std::cout << "c + e < 1 && c + d < 1 && d + e > 1 && c,d,e > 0\n"; 

	// Problem 21
	std::cout << "Problem 21" << std::endl;
	std::cout << "Zero\n";

	// Problem 22
	std::cout << "Problem 22" << std::endl;
	std::cout << "Outside\n";

	// Problem 23
	std::cout << "Problem 23" << std::endl;
	std::cout << "A line\n";

	// Problem 24
	std::cout << "Problem 24" << std::endl;
	std::cout << "All except v & w on a line but u & v not\n";

	// Problem 25
	std::cout << "Problem 25" << std::endl;
	std::cout << "u x v == 0 && u x w == 0\n";
	std::cout << "u x v != 0 && u x v . w == 0\n";

	// Problem 26
	std::cout << "Problem 26" << std::endl;
	std::cout << "c + 3d = 14\n";
	std::cout << "2c + d = 8\n";
	Eigen::Matrix2f v6_A;
	// operator << is row major
	v6_A << 1, 3, 2, 1;
	Eigen::Vector2f v6_b;
	v6_b << 14, 8;
	Eigen::Vector2f v6_x = v6_A.partialPivLu().solve(v6_b);
	std::cout << "Solution: " << v6_x.transpose() << std::endl;

	// Problem 27
	std::cout << "Problem 27" << std::endl;
	std::cout << "2^4 corners, 2^4*4/8 3D faces, 2^4*4/8*6/2 2D faces,";
	std::cout << "2^4*4/8*6/2*4/3 edges\n";

	// Problem 28
	std::cout << "Problem 28" << std::endl;
	Eigen::Vector3f v8_v, v8_w;
	Eigen::MatrixXf v8_X(3, 2);
	Eigen::Matrix2f v8_A;
	v8_A << 1, 1, 1, -1;	
	Eigen::MatrixXf v8_B(3, 2);		
	v8_B << 4, 2, 5, 5, 6, 8;
	// Eqn is v8_X * v8_A = v8_B
	// take the transpose
	// v8_AT * v8_XT = v8_BT
	v8_X = v8_A.transpose().fullPivLu().solve(v8_B.transpose()).transpose();
	v8_v = v8_X(Eigen::all, 0);
	v8_w = v8_X(Eigen::all, 1);
	std::cout << "v = " << v8_v.transpose() << '\n';	
	std::cout << "w = " << v8_w.transpose() << '\n';	

	// Problem 29
	std::cout << "Problem 29" << std::endl;
	Eigen::Vector2f v9_u, v9_v, v9_w, v9_b;
	v9_u << 1, 3;
	v9_v << 2, 7;
	v9_w << 1, 5;
	v9_b << 0, 1;
	Eigen::Matrix2f v9_A;
	v9_A << v9_u.transpose(), v9_v.transpose();	
	v9_A.transposeInPlace();
	Eigen::Vector2f v9_x1 = v9_A.partialPivLu().solve(v9_b);
	v9_A(Eigen::all, 1) = v9_w;	
	Eigen::Vector2f v9_x2 = v9_A.partialPivLu().solve(v9_b);
	std::cout << "A solution: " << v9_x1.transpose() << '\n';
	std::cout << "Another solution: " << v9_x2.transpose()<< '\n';

	return 0;
}
