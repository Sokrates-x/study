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
	assert(res == matrix.diagonal().sum());

	
	
	std::cout << res << std::endl;




	return 0;
}
