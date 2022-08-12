#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cassert>

int main(int, char **)
{
	Eigen::MatrixXi m(2, 2);
	m << 1, 2, 3, 4;

	// tanspose
	m.transposeInPlace(); // do NOT use m=m.transpose();
	m.transpose();
	// conjugate
	m.conjugate();
	// adjoint
	m.adjoint();

	m.reverseInPlace();
	m.adjointInPlace();
	// 	
		
	Eigen::VectorXi vec(10);
	vec << 0, 1, 2, 3, 4, 5, 6, 7, 8, 9;
	vec.conservativeResize(5);

	Eigen::VectorXi vec1(5);
	vec1 << 0, 1, 2, 3, 4;
	vec1.conservativeResize(3); // resize is NOT ok

	// + - * / suqare is ok
	Eigen::MatrixXi mat(2, 2);		
	mat << 1, 2, 4, 7;

	mat += mat;
	mat *= 2;
	mat /= 2;
	mat = mat - Eigen::MatrixXi::Identity(2, 2);
//	Eigen::ArrayXXi arr = mat; 
	auto arr = mat.array();
	arr = arr.square();
	// matrix x matrix is also ok
	//mat = mat * mat; // okay but not efficient
	auto matb = mat;
	matb.noalias() = mat * mat; // more efficient if b exists already.
	// never do this mat.noalias() = mat * mat;

	// non-square matrix is not okay if resize
	Eigen::MatrixXi matx(2, 2);
	Eigen::MatrixXi maty(3, 2);

	matx << 1, 2, 3, 4;
	maty << 1, 2, 3, 4, 5, 6;

	// ok
	//maty = maty * matx;
	// it seems that the next two statements are same
	// but the doc suggest the second one
//	matx = (maty * matx).cwiseAbs(); // not preferred
	matx = (maty * matx).eval().cwiseAbs(); //okay
	
	// Dot Product 
	Eigen::Vector3i u(1, 2, 3);
	Eigen::Vector3i v(1, 2, 3);
	u.dot(v);

	// Cross Product
	u.cross(v);

	//  Matrix 
	Eigen::MatrixXi matrix(2, 2);
	matrix << 1, 2, 3, 4;
	matrix.sum();
	matrix.prod();
	matrix.mean();
	matrix.minCoeff();
	matrix.maxCoeff();
	matrix.trace();
	assert(matrix.trace() == matrix.diagonal().sum());


	// Arrays
	Eigen::ArrayXi arr_a(3);
	arr_a << 1, 2, 3;

	// Arrays subtraction by scalar
	arr_a.square() - 1;

	// Arrays multiplication : coefficient-wise multiplication
	arr_a * arr_a;

	// Abs
	arr_a.abs();
	// sqrt
	arr_a.sqrt();

	// min max & i do NOT know how to use it
	Eigen::ArrayXXi arr_b(2, 2);
	arr_b << 1, 2, 3, 4;
	arr_b.min(arr_b);
	arr_b.max(arr_b);

	// convert between arrys & matrix
	Eigen::MatrixXi mat_arr(2, 3);
	auto arr_mat = mat_arr.array(); 
	mat_arr = arr_mat.matrix();
	// do NOT do anything like this: mat_arr + arr_mat
	// but this is okay: mat_arr = arr_mat arr_mat = mat_arr
	
	// cwise product for Matrix
	Eigen::MatrixXi mat_c(2, 2);
	mat_c << 1, 2, 3, 4;
	Eigen::MatrixXi mat_d(2, 2);
	mat_d << 1, 2, 3, 4;

	//
	auto res = mat_c.cwiseProduct(mat_d);
	std::cout << res << std::endl;
	return 0;
}
