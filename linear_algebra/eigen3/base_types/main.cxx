#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cassert>

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

	// ArraySizeSize<Type>
	Eigen::Array2<int> arr_c;	
	arr_c << 1, 2;
	Eigen::Array22<int> arr_d;
	arr_d << 1, 2, 3, 4;

	// Block
	Eigen::Matrix3i mat;
	mat.reshaped() = Eigen::ArrayXi::LinSpaced(9, 1, 9);
	Eigen::Block<Eigen::Matrix3i, 2, 2> blk(mat, 0, 0);	
	Eigen::Block<Eigen::Matrix3i> blk1(mat, 0, 0, 2, 2);

	// ATTENTION: Col or Row ctor
	// size must be exactlly matched
	Eigen::Block<Eigen::Matrix3i, 3, 1> blk2(mat, 0);
	Eigen::Block<Eigen::Matrix3i, 1, 3> blk3(mat, 0);

	// Diagonal Matrix
	Eigen::DiagonalMatrix<int, 3, 3> dmat;
	dmat.setIdentity();	

	// Index View
	std::vector<int> vecx{0, 1};
	Eigen::IndexedView<Eigen::Matrix3i, std::vector<int>, std::vector<int>>
		iview(mat, vecx, vecx);
	assert(iview.nestedExpression() == mat);

	// IO Format
	Eigen::IOFormat fmt(Eigen::StreamPrecision, 0, ", ", "\n", "[", "]");
	std::cout << mat.format(fmt) << std::endl;

	// TriangularView<Matrix, Mode>
	mat.triangularView<Eigen::Upper>();

	
	// VectorBlock		
	Eigen::Vector4i vec_a;
	vec_a = Eigen::ArrayXi::LinSpaced(4, 1, 4);
	//Eigen::Block<Eigen::Vector4i, 4, 1> vblk(vec_a, 0);
	Eigen::VectorBlock<Eigen::Vector4i, 3> vblk(vec_a, 0, 3);
	vec_a.segment(1, 2);

	
//	std::cout << res << std::endl;


	return 0;
}
