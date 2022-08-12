#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{

	Eigen::Matrix3f m;
	auto n = Eigen::MatrixXd::Random(3, 4); 

	Eigen::MatrixXd l;
	l.resize(4, 5);	
	
	Eigen::Matrix4i i;
	Eigen::VectorXf v(30);	
	Eigen::RowVectorXf rv(30);

	// alloc on the stack
	Eigen::Vector2i va(1, 3);
	Eigen::Vector3i vb(1, 3, 5);
	Eigen::Vector4i vc(1, 3, 5, 7);
	
	Eigen::VectorXi d { {1, 3, 5, 7, 9} };
	Eigen::MatrixXi md { {1, 2}, {3, 4} };

	Eigen::Matrix<int, 2, 3> me;	
	me << 1, 3, 5, 7, 9, 1;

	Eigen::Vector<int, 4> mv;
	mv << 1, 3, 5, 7;

	//std::cout << mv[3] << std::endl;

	// alloc on the heap
	Eigen::MatrixXf big_m(100, 100);
	
	// disallow alloc on the heap	
	// a matix on stack is not default initialized
	Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic, 0, 3, 4> m_on_stack;
	m_on_stack.resize(2, 3);
	Eigen::Matrix2i m_on_stack2;

	// storage orders
	Eigen::Matrix<double, 3, 4, Eigen::RowMajor> row_major_m;	

	// convenience type
	Eigen::Matrix3Xi m_3x2(3, 2); // seems not very convenient

	// Arrays
	Eigen::ArrayXi arr_a(3);
	Eigen::ArrayXXi arr_b(2, 2);
	arr_b << 1, 2, 3, 4;
		
	std::cout << arr_b << std::endl;

	return 0;
}
