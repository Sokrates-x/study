#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int, char **)
{
	Eigen::MatrixXf mat(2, 2);

	mat.reshaped() = Eigen::ArrayXf::LinSpaced(4, 1, 4);
	mat.sum();
	mat.prod();
	mat.mean();
	mat.maxCoeff();
	mat.minCoeff();
	mat.trace();

	// Array has no norms but vector has
	Eigen::VectorXf arr(2);	
	arr << 3, 4;
	// p-Norm for Vectors
	arr.norm();
	arr.squaredNorm();
	arr.lpNorm<1>();
	arr.lpNorm<Eigen::Infinity>();
	
	// p-Norm for Matrix 
	mat.norm(); 	
	assert(mat.norm() == mat.lpNorm<2>());
	mat.lpNorm<1>();	
	mat.squaredNorm();
	mat.lpNorm<Eigen::Infinity>();

	// operator Norm for Matrix
	// NEED MORE ATTENTION
	// 1-norm
	mat.cwiseAbs().colwise().sum().maxCoeff(); 	
	// infinity norm
	mat.cwiseAbs().rowwise().sum().maxCoeff();

	// 
	auto arr_a = mat.array();
	(arr_a > 2).all();	
	(arr_a > 2).any();
	(arr_a > 2).count();
	
	// 
	

	return 0;
}
